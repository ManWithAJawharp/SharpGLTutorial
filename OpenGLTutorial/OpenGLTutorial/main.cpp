#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"

using namespace Core;
using namespace Init;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("OpenGL Beginner Tutorial"),
		400, 300, 800, 600, true);

	ContextInfo context(4, 5, true);

	FramebufferInfo framebufferInfo(true, true, true, true);

	Init_GLUT::init(window, context, framebufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	Init_GLUT::run();

	delete scene;
	return 0;
}