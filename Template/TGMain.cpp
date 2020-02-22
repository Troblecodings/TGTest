#include "TGMain.h"
#include <TGEngine.hpp>
#include <gamecontent/PlayerController.hpp>
#include <gamecontent/Actor.hpp>
#include <pipeline/buffer/Texturebuffer.hpp>
#include <gamecontent/camera/2DCamera.hpp>
#include <io/Resource.hpp>

using namespace tge::gmc;
using namespace tge::tex;

int main() {
	initEngine();

	Map map;
	loadResourceFile("Test.map", &map);
	// This isn't production code ... I hope you did not think it is ...
	for_each(map.textures.begin(), map.textures.end(), [](TextureInputInfo in) { printf("X = %i\nY = %i\nComp = %i", in.x, in.y, in.comp); });
	for_each(map.materials.begin(), map.materials.end(), [](Material in) { printf("color = [%f, %f, %f, %f]\ndiffuseTexture = %i", in.color.r, in.color.g, in.color.b, in.color.a, in.diffuseTexture); });
	for_each(map.actors.begin(), map.actors.end(), [](ActorInputInfo in) { printf("pProperties.material = %i\npProperties.layer = %i", in.pProperties.material, in.pProperties.layer); });
	startTGEngine();
	return 0;
}