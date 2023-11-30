#include "CameraController.h"

#include <iostream>
#include <math.h>

CameraController::CameraController(Camera* camera) :
	camera(camera),
	horizontalAngle(0),
	horizontalRotationSpeed(5)
{
}

void CameraController::HandlePlayerInput(KeyToken keyToken, int scancode, KeyAction action, int mods)
{
	if (action == KeyAction::Press || action == KeyAction::Repeat)
	{
		if (keyToken == KeyToken::A)
		{
			horizontalAngle += horizontalRotationSpeed;
		}
		else if (keyToken == KeyToken::D)
		{
			horizontalAngle -= horizontalRotationSpeed;
		}

		horizontalAngle = fmod(horizontalAngle, 360.0f);
		if (horizontalAngle < 0)
		{
			horizontalAngle = 360.0f + horizontalAngle;
		}
		std::cout << "Angle: " << horizontalAngle << std::endl;
	}
}
