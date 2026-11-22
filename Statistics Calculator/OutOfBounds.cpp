#include "OutOfBounds.h"

OutOfBounds::OutOfBounds(int index)
	: index{index}
{}

std::string OutOfBounds::getMessage() const
{
	std::stringstream s;
	s << "Index: [" << index << "] is out of bounds";
	return s.str();
}