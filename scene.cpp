#include "scene.h"


TillenScene::TillenScene()
{
	Sphere s0;
	s0.center = TillenVec3(0, -2, 6);
	s0.radius = 2;
	s0.color = TillenColorRGBA(1.0, 0, 0, 1.0);
	this->spheres.push_back(s0);

	Sphere s1;
	s1.center = TillenVec3(4, 0, 8);
	s1.radius = 2;
	s1.color = TillenColorRGBA(0, 0, 1.0, 1.0);
	this->spheres.push_back(s1);

	Sphere s2;
	s2.center = TillenVec3(-4, 0, 8);
	s2.radius = 2,
	s2.color = TillenColorRGBA(0, 1.0, 0, 1.0);
	this->spheres.push_back(s2);
}

TillenScene::~TillenScene()
{

}
