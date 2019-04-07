#pragma once
#include "BitsArray.h"
namespace AIS
{
namespace Algorithms
{

bool RContiguousBitsMatchingRule(const BitsArray& d, const BitsArray& x, size_t R);

bool RChunkMatchingRule(const BitsArray& d, const BitsArray& x, size_t p, size_t R);

} // namepsace Algorithm
} // namespace AIS