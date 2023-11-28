#pragma once

class ManagedVertexArray
{
public:
	ManagedVertexArray();
	~ManagedVertexArray();

	unsigned int Name() const { return name; }

	ManagedVertexArray(const ManagedVertexArray&) = delete;
	ManagedVertexArray& operator=(const ManagedVertexArray&) = delete;

private:
	unsigned int name;
};

