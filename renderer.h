#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "scene.h"
#include "frame_buffer.h"

class TillenRenderer
{
public:
	TillenFrameBuffer* frame_buffer;
	TillenScene* scene;
	int window_width;
	int window_height;

	GLFWwindow* window;
	unsigned int frame_texture;
	unsigned int shader_program_id;
	unsigned int vbo, vao, ebo;

	TillenRenderer();
	~TillenRenderer();

	int init(int ww, int wh, TillenFrameBuffer* fb, TillenScene* s);
	int process_input();
	int draw_scene();
	int render_loop();
	int exit();
};