#include "tgaimage.h"
#include "tillen_math.h"
#include "renderer.h"
#include "frame_buffer.h"
#include "scene.h"


int test()
{
	test_tillen_tgaimage();
	test_tillen_math();
	return 0;
}


int main(int argc, char** argv)
{
	//test();
	TillenFrameBuffer frame_buffer;
	TillenScene scene;

	TillenRenderer render;
	render.init(800, 600, &frame_buffer, &scene);
	render.render_loop();

	return 0;
}