#include "CameraController.h"

#include <iostream>

CameraController::CameraController(Camera* camera) :
	camera(camera)
{
}

void CameraController::HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods)
{
	std::cout << "Received input event" << std::endl;
}
