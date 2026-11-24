#include "Dataset.h"

Dataset::Dataset()
	: count{0}, dataPtr{nullptr}
{}

Dataset::~Dataset()
{
	delete[] dataPtr;
}

int Dataset::size() const
{
	return count;
}

void Dataset::insert(double val)
{
	// create the new dataset with one more element
	if (count == 0)
	{
		dataPtr = new double[++count];
		dataPtr[0] = val;
	}
	else
	{
		// create a temporary pointer to the old data
		double *temp = dataPtr;

		// allocate a new array for dataPtr
		dataPtr = nullptr;
		dataPtr = new double[count + 1];

		int oldPtr = 0;
		int newPtr = 0;

		// copy values that are smaller than 
		for (; oldPtr < count; oldPtr++, newPtr++)
		{
			if (temp[oldPtr] <= val)
				dataPtr[newPtr] = temp[oldPtr];
			else
				break;
		}

		// when we break out of the loop, we have reached a number that is greater than val
		// insert val and increment the newPtr
		dataPtr[newPtr++] = val;

		// continue copying the rest of the values
		for (; oldPtr < count; oldPtr++, newPtr++)
			dataPtr[newPtr] = temp[oldPtr];
		
		// delete the old array
		delete[] temp;
		++count;
	}
}

void Dataset::insertRandom(int numsToAdd)
{
	// create random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	
}

double &Dataset::operator [](int index)
{
	if (!inBounds(index))
		throw (OutOfBounds(index));

	return dataPtr[index];
}

const double &Dataset::operator [](int index) const
{
	if (!inBounds(index))
		throw (OutOfBounds(index));

	return dataPtr[index];
}

bool Dataset::inBounds(int index) const
{
	return index >= 0 && index < count;
}