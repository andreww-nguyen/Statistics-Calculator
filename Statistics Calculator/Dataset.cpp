#include "Dataset.h"

Dataset::Dataset()
	: count{0}, dataPtr{nullptr}
{}

Dataset::Dataset(int size)
	: count{size}, dataPtr{new double[size]}
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
	std::uniform_real_distribution<double> dist(1, 100);

	if (count == 0)
	{
		count = numsToAdd;
		dataPtr = new double[count];

		// initialize the array with random values
		for (int i = 0; i < count; i++)
			dataPtr[i] = dist(gen);

		// sort the array
		quickSort(0, count - 1);
	}
	else
	{
		// create a pointer to the old array
		double *temp = dataPtr;

		// create a new array with a size of count + numsToAdd 
		dataPtr = new double[count + numsToAdd];

		// copy the old values over
		int i = 0;
		for (; i < count; i++)
			dataPtr[i] = temp[i];

		// reinitialize count
		count += numsToAdd;
		
		// initialize the leftover indices with random values
		for (; i < count; i++)
			dataPtr[i] = dist(gen);

		// sort the array
		quickSort(0, count - 1);
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

void Dataset::quickSort(int low, int high)
{
	// return when our indices have crossed
	if (low >= high)
		return;

	int initialPivot = findPivot(low, high);
	int finalPivot = partition(low, initialPivot, high);

	// partition the left half
	quickSort(low, finalPivot - 1);

	// partition the right half
	quickSort(finalPivot + 1, high);
}

int Dataset::partition(int low, int pivot, int high)
{
	double pivotVal = dataPtr[pivot];
	int i = low;
	int j = high - 1;

	// swap pivot to the last element
	std::swap(dataPtr[pivot], dataPtr[high]);

	// partition the array/sub array
	while (true)
	{
		// move i to the right while it is still < pivotVal
		while (i < high && dataPtr[i] < pivotVal)
			i++;

		// move j to the left while it is still > pivotVal
		while (j > low && dataPtr[j] > pivotVal)
			j--;

		// swap if the indices have not crossed
		if (i < j)
		{
			std::swap(dataPtr[i], dataPtr[j]);
			// move i and j to the right and left respectively for the next iteration
			i++; j--;
		}
		else
			break;
	}

	// when the loop ends, everything to the left of i is < pivotVal,
	// so we swap it with the original pivotVal to put it in the correct index
	std::swap(dataPtr[i], dataPtr[high]);

	// return the index of the pivot after it has been moved to correct position
	return i;
}

int Dataset::findPivot(int low, int high)
{
	int mid = low + (high - low) / 2;

	// sort the lowest, middle, and high indices of the array
	if (dataPtr[low] > dataPtr[mid])
		std::swap(dataPtr[low], dataPtr[mid]);
	if (dataPtr[low] > dataPtr[high])
		std::swap(dataPtr[low], dataPtr[high]);
	if (dataPtr[mid] > dataPtr[high])
		std::swap(dataPtr[mid], dataPtr[high]);

	// return the middle index, which will be used as the pivot
	return mid;
}

