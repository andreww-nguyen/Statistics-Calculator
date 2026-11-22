#pragma once

#include <string>
#include <sstream>

class Exception
{
public:
	std::string Message() const;

private:
	virtual std::string getMessage() const = 0;
};

