#include "frame_buffer.h"


TillenFrameBuffer::TillenFrameBuffer(int w, int h)
{
	this->width = w;
	this->height = h;
	this->buffer = new double[this->width * this->height * 4];
	this->texture_data = new uint8_t[this->width * this->height * 4];
}

TillenFrameBuffer::~TillenFrameBuffer()
{
	delete[]this->buffer;
	delete[]this->texture_data;
}

int TillenFrameBuffer::put_pixel(int x, int y, const TillenColorRGBA& color)
{
	int index = (y * this->width + x) * 4;
	this->buffer[index] = color.r;
	this->buffer[index + 1] = color.g;
	this->buffer[index + 2] = color.b;
	this->buffer[index + 3] = color.a;
	return 0;
}

TillenColorRGBA TillenFrameBuffer::get_pixel(int x, int y)
{
	int index = (y * this->width + x) * 4;
	return TillenColorRGBA(
		this->buffer[index],
		this->buffer[index + 1],
		this->buffer[index + 2],
		this->buffer[index + 3]
	);
}

int TillenFrameBuffer::clear_buffer()
{
	for (int i = 0; i < this->width * this->height * 4; i++)
	{
		this->buffer[i] = 0;
	}
	return 0;
}

int TillenFrameBuffer::fill_texture_data()
{
	for (int i = 0; i < this->width * this->height * 4; i++)
	{
		if (i % 4 == 0)
			this->texture_data[i] = uint8_t(0.3 * 255.0);
		else if (i % 4 == 1)
			this->texture_data[i] = uint8_t(0.5 * 255.0);
		else if (i % 4 == 2)
			this->texture_data[i] = uint8_t(0.28 * 255.0);
		else
			this->texture_data[i] = uint8_t(1.0 * 255.0);
		//this->texture_data[i] = uint8_t(255.0 * this->buffer[i]);
		//std::cout << int(this->texture_data[i]) << std::endl;;
	}
	return 0;
}
