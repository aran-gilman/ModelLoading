#pragma once

class ManagedBuffer
{
public:
	ManagedBuffer();
	~ManagedBuffer();

	unsigned int Name() const { return name; }

	ManagedBuffer(const ManagedBuffer&) = delete;
	ManagedBuffer& operator=(const ManagedBuffer&) = delete;

private:
	unsigned int name;
};

