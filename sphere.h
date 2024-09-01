#pragma once

#include "tillen_math.h"

class Sphere
{
public:
	TillenVec3 center;
	double radius;
	TillenColorRGBA color;
	double specular;
	double reflective;
};
