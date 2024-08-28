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

	TillenVec3 camera_pos;
	TillenVec3 camera_forward;
	TillenVec3 camera_up;
	TillenVec3 camera_right;
	double near_distance;
	double far_distance;

	GLFWwindow* window;
	unsigned int frame_texture;
	unsigned int shader_program_id;
	unsigned int vbo, vao, ebo;

	TillenRenderer();
	~TillenRenderer();

	int init(int ww, int wh, TillenFrameBuffer* fb, TillenScene* s);
	int process_input();

	TillenVec2 canvas_to_viewport(int x, int y);
	TillenColorRGBA comput_light(const TillenVec3& position, const TillenVec3& normal, const TillenVec3& light_direction, const TillenVec3& view_position, const TillenColorRGBA& light_color, double shiny);
	TillenColorRGBA comput_point_light(const TillenVec3& position, const TillenVec3& normal, const PointLight& pl, double shiny);
	TillenColorRGBA comput_directional_light(const TillenVec3& position, const TillenVec3& normal, const DirectionalLight& dl, double shiny);
	int draw_scene();

	int render_loop();
	int exit();
};