#pragma once

#include <glm/glm.hpp>

#include "ManagedBuffer.h"

struct CameraData
{
	glm::vec4 view;
	glm::vec4 projection;
	glm::vec4 position;
};

class Camera
{
public:
	Camera();

private:
	UniformBuffer ubo;
};

