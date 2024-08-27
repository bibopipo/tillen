#pragma once

#include <vector>

#include "sphere.h"
#include "light.h"

class TillenScene
{
public:
	TillenScene();
	~TillenScene();
	std::vector<Sphere> spheres;

	std::vector<PointLight> point_lights;
	std::vector<DirectionalLight> directional_lights;
	TillenColorRGBA ambient_light;
};