#include "CameraController.h"

#include <iostream>
#include <cmath>

#include "Camera.h"

CameraController::CameraController(Camera* camera) :
	camera(camera),
	horizontalAngle(0),
	horizontalRotationSpeed(0.05)
{
	UpdateCameraPosition();
}

void CameraController::HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods)
{
	if (action == KeyAction::Press || action == KeyAction::Repeat)
	{
		if (keyToken == KeyToken::A)
		{
			horizontalAngle += horizontalRotationSpeed;
			UpdateCameraPosition();
		}
		else if (keyToken == KeyToken::D)
		{
			horizontalAngle -= horizontalRotationSpeed;
			UpdateCameraPosition();
		}
	}
}

void CameraController::UpdateCameraPosition()
{
	horizontalAngle = std::fmod(horizontalAngle, 360.0f);
	if (horizontalAngle < 0)
	{
		horizontalAngle = 360.0f + horizontalAngle;
	}

	float x = std::cos(horizontalAngle) * 5;
	float y = 0.0f;
	float z = std::sin(horizontalAngle) * 5;

	camera->SetPosition({ x, y, z});
}
