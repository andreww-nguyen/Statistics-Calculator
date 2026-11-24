#pragma once

#include "OutOfBounds.h"

#include <iosfwd>
#include <random>

class Dataset
{
public:
	Dataset();
	// Dataset(const Dataset &p_Other);
	// Dataset(Dataset &&p_Other);
	~Dataset();

	int size() const;
	void insert(double val);
	void insertRandom(int numsToAdd);

	double &operator [](int index);
	const double &operator [](int index) const;

private:
	bool inBounds(int index) const;

private:

	int count;
	double *dataPtr;
};

