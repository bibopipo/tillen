#include "scene.h"


TillenScene::TillenScene()
{
	// spheres
	Sphere s0;
	s0.center = TillenVec3(0, -2, 6);
	s0.radius = 2;
	s0.color = TillenColorRGBA(1.0, 0, 0, 1.0);
	s0.specular = 500;
	this->spheres.push_back(s0);

	Sphere s1;
	s1.center = TillenVec3(4, 0, 8);
	s1.radius = 2;
	s1.color = TillenColorRGBA(0, 0, 1.0, 1.0);
	s1.specular = 500;
	this->spheres.push_back(s1);

	Sphere s2;
	s2.center = TillenVec3(-4, 0, 8);
	s2.radius = 2;
	s2.color = TillenColorRGBA(0, 1.0, 0, 1.0);
	s2.specular = 10;
	this->spheres.push_back(s2);

	Sphere s3;
	s3.center = TillenVec3(0, -10002, 0);
	s3.color = TillenColorRGBA(1.0, 1.0, 0, 1.0);
	s3.radius = 10000;
	s3.specular = 1000;
	this->spheres.push_back(s3);

	// lights
	this->ambient_light = TillenColorRGBA(0.2, 0.2, 0.2, 1.0);

	PointLight pl0;
	pl0.position = TillenVec3(4, 2, 0);
	pl0.color = TillenColorRGBA(0.6, 0.6, 0.6, 1.0);
	this->point_lights.push_back(pl0);

	DirectionalLight dl0;
	dl0.direction = TillenVec3(1, 4, 4);
	dl0.color = TillenColorRGBA(0.2, 0.2, 0.2, 1.0);
	this->directional_lights.push_back(dl0);
}

TillenScene::~TillenScene()
{

}
