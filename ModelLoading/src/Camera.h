#pragma once

#include <glm/glm.hpp>

#include "ManagedBuffer.h"

struct CameraData
{
	glm::mat4 view;
	glm::mat4 projection;
};

class Camera
{
public:
	Camera(CameraData initialCameraConfig);

private:
	UniformBuffer ubo;
	CameraData shaderData;
};

