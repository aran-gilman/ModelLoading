#pragma once

class ManagedVertexArray
{
public:
	ManagedVertexArray();
	~ManagedVertexArray();

	unsigned int Name() const { return name; }

	ManagedVertexArray(const ManagedVertexArray&) = delete;
	ManagedVertexArray& operator=(const ManagedVertexArray&) = delete;

	ManagedVertexArray(ManagedVertexArray&& other) noexcept;
	ManagedVertexArray& operator=(ManagedVertexArray&& other) noexcept;

private:
	unsigned int name;
};

