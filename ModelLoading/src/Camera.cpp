#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include "BufferOperations.h"
#include "VectorConstants.h"

namespace
{
	struct CameraData
	{
		glm::mat4 view;
		glm::mat4 projection;
	};
}


Camera::Camera(glm::vec3 position, float aspectRatio, float fieldOfView) :
	position(position),
	aspectRatio(aspectRatio),
	fieldOfView(fieldOfView),
	zNear(0.1f),
	zFar(100.0f)
{
	CameraData shaderData{
		glm::lookAt(position, constants::vec3::Zero, constants::vec3::Up),
		glm::perspective(glm::radians(fieldOfView), aspectRatio, zNear, zFar)
	};
	SetBufferData(ubo, shaderData, BufferUsage::StaticDraw);
	BindUniformBlock(ubo, 0);
}
