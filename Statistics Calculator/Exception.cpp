#include "Exception.h"

std::string Exception::Message() const
{
	std::stringstream s;
	s << "ERROR: " << this->getMessage();

	return s.str();
}