#include "Camera.h"

#include "BufferOperations.h"

Camera::Camera(CameraData initialCameraConfig) :
	shaderData(initialCameraConfig)
{
	SetBufferData(ubo, shaderData, BufferUsage::StaticDraw);
	BindUniformBlock(ubo, 0);
}
