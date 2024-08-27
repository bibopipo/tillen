#pragma once

#include <vector>

#include "sphere.h"

class TillenScene
{
public:
	TillenScene();
	~TillenScene();
	std::vector<Sphere> spheres;
};