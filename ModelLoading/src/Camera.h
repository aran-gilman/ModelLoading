#pragma once

#include <glm/glm.hpp>

#include "ManagedBuffer.h"

class Camera
{
public:
	Camera(glm::vec3 position, float aspectRatio, float fieldOfView);

	void SetPosition(glm::vec3 position);

private:
	UniformBuffer ubo;

	glm::vec3 position;

	float aspectRatio;
	float fieldOfView;
	float zNear;
	float zFar;
};

