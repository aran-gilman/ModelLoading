#include "CameraController.h"

#include <format>
#include <iostream>
#include <cmath>

#include "Camera.h"

CameraController::CameraController(Camera* camera) :
	camera(camera),
	currentHorizontalAngle(0),
	maxHorizontalRotationSpeed(180),
	currentHorizontalRotationVelocity(0)
{
	UpdateCameraPosition();
}

void CameraController::HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods)
{
	if (action == KeyAction::Press)
	{
		if (keyToken == KeyToken::A)
		{
			currentHorizontalRotationVelocity += maxHorizontalRotationSpeed;
		}
		else if (keyToken == KeyToken::D)
		{
			currentHorizontalRotationVelocity -= maxHorizontalRotationSpeed;
		}
	}
	else if (action == KeyAction::Release)
	{
		if (keyToken == KeyToken::A)
		{
			currentHorizontalRotationVelocity -= maxHorizontalRotationSpeed;
		}
		else if (keyToken == KeyToken::D)
		{
			currentHorizontalRotationVelocity += maxHorizontalRotationSpeed;
		}
	}
}

void CameraController::Update(double elapsedTime)
{
	if (std::abs(currentHorizontalRotationVelocity) > 0.0001f)
	{
		currentHorizontalAngle += (currentHorizontalRotationVelocity * elapsedTime);
		UpdateCameraPosition();
	}
}

void CameraController::UpdateCameraPosition()
{
	currentHorizontalAngle = std::fmod(currentHorizontalAngle, 360.0f);
	if (currentHorizontalAngle < 0)
	{
		currentHorizontalAngle = 360.0f + currentHorizontalAngle;
	}

	float x = std::cos(glm::radians(currentHorizontalAngle)) * 5;
	float y = 0.0f;
	float z = std::sin(glm::radians(currentHorizontalAngle)) * 5;

	camera->SetPosition({ x, y, z});
}
