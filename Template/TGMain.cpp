#include "TGMain.h"
#include <TGEngine.hpp>
#include <gamecontent/PlayerController.hpp>
#include <gamecontent/Actor.hpp>
#include <pipeline/buffer/Texturebuffer.hpp>
#include <gamecontent/camera/2DCamera.hpp>
#include <io/Resource.hpp>
#include <pipeline/buffer/UniformBuffer.hpp>

using namespace tge::gmc;
using namespace tge::tex;

static TopDownCamera camera;
static glm::vec2 testAnim;

int main() {
	initEngine();

	camera.positionx = 0;
	camera.positiony = 0;
	camera.screenwidth = tge::win::mainWindowWidth;
	camera.screenheight = tge::win::mainWindowHeight;
	playercontroller = [](Input in) {
		camera.positionx -= in.deltax; 
		camera.positiony -= in.deltay;
		setTopDownCamera(camera); 
		testAnim.x += 0.001;
		tge::buf::fillUniformBuffer(2, &testAnim, sizeof(glm::vec2));
	};

	setTopDownCamera(camera);

	Map map;
	loadResourceFile("test.tgr", &map);


	startTGEngine();
	return 0;
}