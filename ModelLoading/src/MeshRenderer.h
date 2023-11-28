#pragma once

class MeshRenderer
{
public:
	void Render();

	MeshRenderer(const MeshRenderer&) = delete;
	MeshRenderer& operator=(const MeshRenderer&) = delete;
};

