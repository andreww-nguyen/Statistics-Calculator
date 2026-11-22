#pragma once
#include "Exception.h"

class OutOfBounds : public Exception
{
public:
	OutOfBounds(int index);

private:
	std::string getMessage() const override;

private:
	int index;
};

