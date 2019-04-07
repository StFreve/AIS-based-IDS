#pragma once
#include "BitsArray.h"
#include <vector>

namespace AIS
{
namespace Algorithms
{

size_t HammingDistance(const BitsArray& bits_1, const BitsArray& bits_2);

std::vector<size_t> BinaryDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double RusselAndRaoDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double JacardAndNeedhamDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double KulzinskiDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double RogersAndTanimotoDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double YuleDistance(const BitsArray& bits_1, const BitsArray& bits_2);

double SokalAndMichenerDistance(const BitsArray& bits_1, const BitsArray& bits_2);

} // namepsace Algorithm
} // namespace AIS