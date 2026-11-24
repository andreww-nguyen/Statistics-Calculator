#pragma once

#include "OutOfBounds.h"

#include <iosfwd>
#include <random>

class Dataset
{
public:
	Dataset();
	Dataset(int size);
	// Dataset(const Dataset &p_Other);
	// Dataset(Dataset &&p_Other);
	~Dataset();

	int size() const;
	void insert(double val);
	void insertRandom(int numsToAdd);

	double &operator [](int index);
	const double &operator [](int index) const;

	
	void quickSort(int low, int high); // only listed as public so gtests has access to it

private:
	bool inBounds(int index) const;

	/**
	 * @brief 
	 * @param low 
	 * @param pivot 
	 * @param high 
	 * @return the final index of the pivot after partitioning the array/ subarray
	 */
	int partition(int low, int pivot, int high);

	/**
	 * @brief 
	 * @param low 
	 * @param high 
	 * @return the index of the pivot to use to partition the array/sub array
	 */
	int findPivot(int low, int high);

private:

	int count;
	double *dataPtr;
};

