#pragma once

#include "OutOfBounds.h"

#include <iosfwd>

class Dataset
{
public:
	Dataset();
	// Dataset(const Dataset &p_Other);
	// Dataset(Dataset &&p_Other);
	~Dataset();

	int size() const;
	void insert(double val);

	double &operator [](int index);
	const double &operator [](int index) const;

private:
	bool inBounds(int index) const;

private:

	int count;
	double *dataPtr;
};

