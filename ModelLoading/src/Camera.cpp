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

	CameraData MakeCameraData(glm::vec3 position, float aspectRatio, float fieldOfView)
	{
		return CameraData{
			glm::lookAt(position, constants::vec3::Zero, constants::vec3::Up),
			glm::perspective(glm::radians(fieldOfView), aspectRatio, 0.1f, 100.0f)
		};
	}
}


Camera::Camera(glm::vec3 position, float aspectRatio, float fieldOfView) :
	position(position),
	aspectRatio(aspectRatio),
	fieldOfView(fieldOfView)
{
	CameraData shaderData = MakeCameraData(position, aspectRatio, fieldOfView);
	SetBufferData(ubo, shaderData, BufferUsage::StaticDraw);
	BindUniformBlock(ubo, 0);
}
