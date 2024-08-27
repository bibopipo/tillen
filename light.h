#pragma once

#include "tillen_math.h"

class PointLight
{
public:
	TillenVec3 position;
	TillenColorRGBA color;
};


class DirectionalLight
{
public:
	TillenVec3 direction;
	TillenColorRGBA color;
};
