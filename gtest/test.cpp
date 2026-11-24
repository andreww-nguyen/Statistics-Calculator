#include "pch.h"
#include "../Statistics Calculator/Dataset.cpp"
#include "../Statistics Calculator/Exception.cpp"
#include "../Statistics Calculator/OutOfBounds.cpp"

TEST(DatasetTests, Constructor) 
{
	Dataset data;
	EXPECT_EQ(data.size(), 0);
}

TEST(DatasetTests, Insert)
{
	Dataset data;
	data.insert(3.0);
	EXPECT_DOUBLE_EQ(data[0], 3.0);
	data.insert(2.0);

	EXPECT_DOUBLE_EQ(data[0], 2.0);
	EXPECT_DOUBLE_EQ(data[1], 3.0);
	data.insert(1.0);
	EXPECT_DOUBLE_EQ(data[0], 1.0);
	EXPECT_DOUBLE_EQ(data[1], 2.0);
	EXPECT_DOUBLE_EQ(data[2], 3.0);

	EXPECT_ANY_THROW(data[3]);
	EXPECT_ANY_THROW(data[-1] = 5.0);
}

TEST(DatasetTests, OperatorIndex)
{
	Dataset data;
	data.insert(0);
	data.insert(1);
	data.insert(2);
	EXPECT_DOUBLE_EQ(data[0], 0.0);
	EXPECT_DOUBLE_EQ(data[1], 1.0);
	EXPECT_DOUBLE_EQ(data[2], 2.0);

	EXPECT_ANY_THROW(data[3]);
	EXPECT_ANY_THROW(data[-1] = 5.0);
}

