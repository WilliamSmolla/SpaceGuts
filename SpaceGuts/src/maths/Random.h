#pragma once

class Random
{
public:
	template<typename T>
	static int Range(T min, T max)
	{
		return min + static_cast<T>(rand()) /
			(static_cast<T>(RAND_MAX / (max - min)));
	}
};

