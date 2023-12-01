#include "CameraController.h"

#include <format>
#include <iostream>
#include <cmath>

#include "Camera.h"

namespace
{
	constexpr float MaxHorizontalAngle = 360.0f;
	constexpr float MaxVerticalAngle = 89.0f;
	constexpr float MinUpdateSpeed = 0.001f;
}

CameraController::CameraController(Camera* camera) :
	camera(camera),

	maxHorizontalRotationSpeed(180),
	currentHorizontalAngle(0),
	currentHorizontalRotationVelocity(0),

	maxVerticalRotationSpeed(180),
	currentVerticalAngle(0),
	currentVerticalRotationVelocity(0),

	currentCameraDistance(5.0f),
	minCameraDistance(1.0f),
	maxCameraDistance(10.0f),
	remainingDistanceChange(0.0f),
	maxDistanceChangeSpeed(5.0f)
{
	UpdateCameraPosition();
}

void CameraController::HandleKeyboardInput(KeyToken keyToken, int scancode, KeyAction action, int mods)
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
		else if (keyToken == KeyToken::S)
		{
			currentVerticalRotationVelocity -= maxVerticalRotationSpeed;
		}
		else if (keyToken == KeyToken::W)
		{
			currentVerticalRotationVelocity += maxVerticalRotationSpeed;
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
		else if (keyToken == KeyToken::S)
		{
			currentVerticalRotationVelocity += maxVerticalRotationSpeed;
		}
		else if (keyToken == KeyToken::W)
		{
			currentVerticalRotationVelocity -= maxVerticalRotationSpeed;
		}
	}
}

void CameraController::HandleScrollInput(double xOffset, double yOffset)
{
	remainingDistanceChange -= yOffset;
}

void CameraController::Update(double elapsedTime)
{
	bool wasPositionUpdated = false;
	if (std::abs(currentHorizontalRotationVelocity) > MinUpdateSpeed)
	{
		currentHorizontalAngle += (currentHorizontalRotationVelocity * elapsedTime);
		currentHorizontalAngle = std::fmod(currentHorizontalAngle, MaxHorizontalAngle);
		if (currentHorizontalAngle < 0)
		{
			currentHorizontalAngle += MaxHorizontalAngle;
		}
		wasPositionUpdated = true;
	}
	
	if (std::abs(currentVerticalRotationVelocity) > MinUpdateSpeed)
	{
		currentVerticalAngle += (currentVerticalRotationVelocity * elapsedTime);
		if (currentVerticalAngle > MaxVerticalAngle)
		{
			currentVerticalAngle = MaxVerticalAngle;
		}
		else if (currentVerticalAngle < -MaxVerticalAngle)
		{
			currentVerticalAngle = -MaxVerticalAngle;
		}
		wasPositionUpdated = true;
	}

	if (remainingDistanceChange > MinUpdateSpeed)
	{
		float diff = maxDistanceChangeSpeed * elapsedTime;
		float newRemainingDistance = remainingDistanceChange - diff;
		if (newRemainingDistance - diff < 0.0f)
		{
			diff = remainingDistanceChange;
			remainingDistanceChange = 0;
		}
		else
		{
			remainingDistanceChange = newRemainingDistance;
		}
		currentCameraDistance += diff;
		if (currentCameraDistance > maxCameraDistance)
		{
			currentCameraDistance = maxCameraDistance;
		}
		wasPositionUpdated = true;
	}
	else if (remainingDistanceChange < -MinUpdateSpeed)
	{
		float diff = -maxDistanceChangeSpeed * elapsedTime;
		float newRemainingDistance = remainingDistanceChange - diff;
		if (newRemainingDistance - diff > 0.0f)
		{
			diff = remainingDistanceChange;
			remainingDistanceChange = 0;
		}
		else
		{
			remainingDistanceChange = newRemainingDistance;
		}
		currentCameraDistance += diff;
		if (currentCameraDistance < minCameraDistance)
		{
			currentCameraDistance = minCameraDistance;
		}
		wasPositionUpdated = true;
	}

	if (wasPositionUpdated)
	{
		UpdateCameraPosition();
	}
}

void CameraController::UpdateCameraPosition()
{
	float verticalMultiplier = std::cos(glm::radians(currentVerticalAngle));

	float x = verticalMultiplier * std::cos(glm::radians(currentHorizontalAngle));
	float y = std::sin(glm::radians(currentVerticalAngle));
	float z = verticalMultiplier * std::sin(glm::radians(currentHorizontalAngle));

	glm::vec3 newPosition{ x, y, z };

	camera->SetPosition(newPosition * currentCameraDistance);
}
