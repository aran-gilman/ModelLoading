#include "CameraController.h"

#include <iostream>

CameraController::CameraController(Camera* camera) :
	camera(camera)
{
}

void CameraController::HandlePlayerInput(int keyToken, int scancode, int action, int mods)
{
	std::cout << "Received event with key token " << keyToken << std::endl;
}
