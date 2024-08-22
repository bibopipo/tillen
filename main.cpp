#include <stdio.h>
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const int screen_with = 1024;
const int screen_height = 768;
TGAImage image(screen_with, screen_height, TGAImage::RGB);


int CanvasToViewport(int x, int y, int width, int height, double vwidth, double vheight, double* vx, double* vy)
{
	*vx = x / width * vwidth;
	*vy = y / height * vheight;
	return 0;
}

int main(int argc, char** argv)
{
	for (int x = 0; x < screen_with; x++)
	{
		for (int y = 0; y < screen_height; y++)
		{
			image.set(x, y, red);
		}
	}
	image.write_tga_file("output.tga");
	return 0;
}