#pragma once

#include <memory>

class Camera;

class CameraController
{
public:
	CameraController(Camera* camera);

	void HandlePlayerInput(int keyToken, int scancode, int action, int mods);

private:
	Camera* camera;
};