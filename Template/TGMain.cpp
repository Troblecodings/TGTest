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
using namespace tge::io;
using namespace tge::buf;

static TopDownCamera camera;
static glm::vec2 testAnim;

int main() {
	initEngine();

	camera.positionx = 0;
	camera.positiony = 0;
	camera.screenwidth = tge::win::mainWindowWidth;
	camera.screenheight = tge::win::mainWindowHeight;
	playercontroller = [](Input in) {
		camera.positionx -= in.inputX; 
		camera.positiony -= in.inputY;
		setTopDownCamera(camera); 
		testAnim.x += 0.001;
		fillUniformBuffer(TRANSFORM_BUFFER, &testAnim, sizeof(glm::vec2), sizeof(glm::mat4) + sizeof(glm::vec2) * MAX_MATERIALS);
		fillUniformBuffer(TRANSFORM_BUFFER_2, &testAnim, sizeof(glm::vec2), sizeof(glm::mat4) + sizeof(glm::vec2) * MAX_MATERIALS);
		glm::vec4 standart(1, 1, 1, 1);
		tge::buf::fillUniformBuffer(TRANSFORM_BUFFER, &standart, sizeof(glm::vec4), sizeof(glm::mat4));
		tge::buf::fillUniformBuffer(TRANSFORM_BUFFER_2, &standart, sizeof(glm::vec4), sizeof(glm::mat4));
	};

	setTopDownCamera(camera);

	loadResourceFile("test.tgr");

	startTGEngine();
	return 0;
}