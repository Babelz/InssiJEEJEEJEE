#pragma once
#include <algorithm>

class Random
{
public:
	Random();

	int next(int min, int max);

	~Random();
};

