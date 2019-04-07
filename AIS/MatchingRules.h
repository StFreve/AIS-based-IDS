#pragma once
#include <bitset>

namespace AIS
{
namespace Algorithms
{

template<size_t R, size_t SIZE>
bool RContiguousBitsMatchingRule(const std::bitset<SIZE>& d, const std::bitset<SIZE>& x)
{
	size_t eq = 0;
	for (size_t i = 0; i < SIZE && eq < R; ++i)
	{
		if (d[i] == x[i])
		{
			++eq;
		}
		else
		{
			eq = 0;
		}
	}
	return eq >= R;
}

template<size_t R, size_t SIZE>
bool RChunkMatchingRule(const std::bitset<R>& d, size_t p, const std::bitset<SIZE>& x)
{
	if (p + R > SIZE)
	{
		return false;
	}
	for (size_t i = 0; i < R; ++i)
	{
		if (x[p + i] != d[i])
		{
			return false;
		}
	}
	return true;
}

} // namepsace Algorithm
} // namespace AIS