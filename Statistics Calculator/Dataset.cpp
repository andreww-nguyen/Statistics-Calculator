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
		// create a temporary ptr to the current data
		double *temp = dataPtr;
		
		// set dataPtr to nullptr;
		dataPtr = nullptr;
		dataPtr = new double[count + 1];

		// copy the values from temp to dataPtr
		for (int i = 0; i < count; i++)
			dataPtr[i] = temp[i];

		// copy the value to insert and increment count after
		dataPtr[count++] = val;

		// delete the old values
		delete[] temp;
	}
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