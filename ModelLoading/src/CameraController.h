#pragma once

#include <memory>

class Camera;

class CameraController
{
public:
	CameraController(Camera* camera);

private:
	Camera* camera;
};

