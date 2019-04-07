#include "MatchingRules.h"
#include <algorithm>

namespace AIS
{
namespace Algorithms
{

bool RContiguousBitsMatchingRule(const BitsArray & d, const BitsArray & x, size_t R)
{
	size_t eq = 0;
	size_t max_size = std::max(d.size(), x.size());
	for (size_t i = 0; i < max_size && eq < R; ++i)
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

bool RChunkMatchingRule(const BitsArray & d, const BitsArray & x, size_t p, size_t R)
{
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