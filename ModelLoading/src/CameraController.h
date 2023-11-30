#pragma once

#include <memory>

#include "InputEnums.h"

class Camera;

class CameraController
{
public:
	CameraController(Camera* camera);

	void HandleKeyboardInput(KeyToken keyToken, int scancode, KeyAction action, int mods);
	void HandleScrollInput(double xOffset, double yOffset);

	void Update(double elapsedTime);

private:
	Camera* camera;

	float maxHorizontalRotationSpeed;
	float currentHorizontalAngle;
	float currentHorizontalRotationVelocity;

	float maxVerticalRotationSpeed;
	float currentVerticalAngle;
	float currentVerticalRotationVelocity;

	float cameraDistance;

	void UpdateCameraPosition();
};