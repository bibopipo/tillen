#pragma once

#include "tillen_math.h"

class TillenFrameBuffer
{
public:
	TillenFrameBuffer(int w =1024, int h = 768);
	~TillenFrameBuffer();
	int put_pixel(int x, int y, const TillenColorRGBA& color);
	TillenColorRGBA get_pixel(int x, int y);
	int clear_buffer();
	int fill_texture_data();

	int width, height;
	double* buffer;
	uint8_t* texture_data;
};