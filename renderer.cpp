#include "renderer.h"


TillenRenderer::TillenRenderer()
{
}

TillenRenderer::~TillenRenderer()
{
}

int TillenRenderer::init(int ww, int wh, TillenFrameBuffer* fb, TillenScene* s)
{
	this->camera_pos = TillenVec3(0, 0, -2.0);
	this->near_distance = 2.0;
	this->far_distance = 2000000.0;

	this->window_width = ww;
	this->window_height = wh;

	this->frame_buffer = fb;
	this->scene = s;

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	this->window = glfwCreateWindow(this->window_width, this->window_height, "RenderWidth", NULL, NULL);
	if (this->window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
	}
	glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// create shader
	const char* vs_source = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout(location = 1) in vec2 aTexCoord;\n"
		"out vec2 TexCoord;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
		"}\0";
	const char* fs_source = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D texture1;\n"
		"void main()\n"
		"{\n"
		"   FragColor = texture(texture1, TexCoord);\n"
		"}\n\0";

	// vertex shader
	unsigned int vs_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs_shader, 1, &vs_source, NULL);
	glCompileShader(vs_shader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vs_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vs_shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fs_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs_shader, 1, &fs_source, NULL);
	glCompileShader(fs_shader);
	// check for shader compile errors
	glGetShaderiv(fs_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fs_shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	this->shader_program_id = glCreateProgram();
	glAttachShader(this->shader_program_id, vs_shader);
	glAttachShader(this->shader_program_id, fs_shader);
	glLinkProgram(this->shader_program_id);
	// check for linking errors
	glGetProgramiv(this->shader_program_id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->shader_program_id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vs_shader);
	glDeleteShader(fs_shader);

	// vertex data
	float vertices[] = {
		// positions          // texture coords
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f, // top right
		 1.0f, -1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // bottom left
		-1.0f,  1.0f, 0.0f,   0.0f, 1.0f  // top left 
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);
	glGenBuffers(1, &this->ebo);

	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	// texture 
	// -------------------------
	glGenTextures(1, &this->frame_texture);
	glBindTexture(GL_TEXTURE_2D, this->frame_texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load image, create texture and generate mipmaps
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->frame_buffer->width, this->frame_buffer->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->frame_buffer->texture_data);
	glGenerateMipmap(GL_TEXTURE_2D);

	return 0;
}

int TillenRenderer::process_input()
{
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->window, true);
	return 0;
}

TillenVec2 TillenRenderer::canvas_to_viewport(int x, int y)
{
	return TillenVec2(
		2.0 * x / this->frame_buffer->width - 1.0,
		2.0 * y / this->frame_buffer->height- 1.0
	);
}

int TillenRenderer::draw_scene()
{
	this->frame_buffer->clear_buffer();

	for (int x = 0; x < this->frame_buffer->width; x++)
	{
		for (int y = 0; y < this->frame_buffer->height; y++)
		{
			double closest_t = INFINITY;
			Sphere* closest_sphere = NULL;
			TillenVec2 viewport_point = this->canvas_to_viewport(x, y);
			TillenVec3 viewport_position = TillenVec3(viewport_point.x, viewport_point.y, 0.0);

			for (int i = 0; i < this->scene->spheres.size(); i++)
			{
				Sphere s = this->scene->spheres[i];
				TillenArray2 res;
				int intersection_num = get_intersection_between_sphere_and_ray(
					res,
					this->camera_pos,
					viewport_position,
					s.center,
					s.radius
				);

				for (int j = 0; j < intersection_num; j++)
				{
					double t = res.val[j];
					if (t < 1.0)
						continue;

					if (t < closest_t)
					{
						closest_t = t;
						closest_sphere = &s;
					}
				}
			}

			if (closest_sphere != NULL)
				this->frame_buffer->put_pixel(x, y, closest_sphere->color);
			else
				this->frame_buffer->put_pixel(x, y, TillenColorRGBA(0.0, 0.0, 0.0, 1.0));
		}
	}
	this->frame_buffer->fill_texture_data();
	return 0;
}

int TillenRenderer::render_loop()
{
	while (!glfwWindowShouldClose(this->window))
	{
		// input
		// -----
		this->process_input();

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		this->draw_scene();

		 //bind Texture
		glBindTexture(GL_TEXTURE_2D, this->frame_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->frame_buffer->width, this->frame_buffer->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->frame_buffer->texture_data);
		glGenerateMipmap(GL_TEXTURE_2D);

		// render container
		glUseProgram(this->shader_program_id);

		glBindVertexArray(this->vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
	this->exit();
	return 0;
}

int TillenRenderer::exit()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
	glDeleteProgram(this->shader_program_id);
	glfwTerminate();
	return 0;
}
