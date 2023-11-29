#include "Camera.h"

#include "BufferOperations.h"

Camera::Camera()
{
	SetBufferData(ubo, CameraData{}, BufferUsage::StaticDraw);
	BindUniformBlock(ubo, 0);
}
