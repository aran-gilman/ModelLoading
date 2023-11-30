#pragma once

#include <memory>

#include "InputEnums.h"

class Camera;

class CameraController
{
public:
	CameraController(Camera* camera);

	void HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods);
	void Update(double elapsedTime);

private:
	Camera* camera;

	float maxHorizontalRotationSpeed;
	float currentHorizontalAngle;
	float currentHorizontalRotationVelocity;

	float maxVerticalRotationSpeed;
	float currentVerticalAngle;
	float currentVerticalRotationVelocity;

	void UpdateCameraPosition();
};