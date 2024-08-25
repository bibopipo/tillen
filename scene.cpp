#include "scene.h"


TillenScene::TillenScene()
{
	spheres[0].center = TillenVec3();
	spheres[0].radius = 1.0;

	spheres[1].center = TillenVec3();
	spheres[1].radius = 1.0;

	spheres[2].center = TillenVec3();
	spheres[2].radius = 1.0;
}

TillenScene::~TillenScene()
{

}
