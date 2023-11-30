#pragma once

#include <memory>

#include "InputEnums.h"

class Camera;

class CameraController
{
public:
	CameraController(Camera* camera);

	void HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods);

private:
	Camera* camera;
};