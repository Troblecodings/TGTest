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

	playercontroller = [](Input* in) {};

	TopDownCamera camera;
	camera.positionx = 0;
	camera.positiony = 0;
	camera.screenwidth = tge::win::mainWindowWidth;
	camera.screenheight = tge::win::mainWindowHeight;
	setTopDownCamera(&camera);

	Map map;
	loadResourceFile("test.tgr", &map);

	startTGEngine();
	return 0;
}