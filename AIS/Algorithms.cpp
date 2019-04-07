#include "Algorithms.h"
#include <algorithm>

namespace AIS
{
namespace Algorithms
{

/*************************** Distances ***************************/

std::vector<size_t> BinaryDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	std::vector<size_t> result(4, 0);
	size_t max_size = std::max(bits_1.size(), bits_2.size());
	for (size_t i = 0; i < max_size; ++i) {
		if (bits_1[i] == 1 && bits_2[i] == 1) {
			++result[0];
		}
		else if (bits_1[i] == 1 && bits_2[i] == 0) {
			++result[1];
		}
		else if (bits_1[i] == 0 && bits_2[i] == 1) {
			++result[2];
		}
		else if (bits_1[i] == 0 && bits_2[i] == 0) {
			++result[3];
		}
	}

	return result;
}

size_t HammingDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	return (bits_1 ^ bits_2).count();
}

double RusselAndRaoDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2] + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}

double JacardAndNeedhamDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2];
	return denominator ? numerator / denominator : 0;
}

double KulzinskiDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = 1 + binary_distances[1] +
		binary_distances[2];
	return numerator / denominator;
}

double RogersAndTanimotoDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0] + binary_distances[3];
	double denominator = binary_distances[0] + 2 * (binary_distances[1] +
		binary_distances[2]) + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}

double YuleDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0] * binary_distances[3] -
		binary_distances[1] * binary_distances[2];
	double denominator = binary_distances[0] * binary_distances[3] +
		binary_distances[1] * binary_distances[2];
	return denominator ? numerator / denominator : 0;
}

double SokalAndMichenerDistance(const BitsArray & bits_1, const BitsArray & bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0] + binary_distances[3];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2] + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}


/*************************** Matching Rules ***************************/

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

/*************************** Negative Selection ***************************/

void NegativeSelection(std::vector<DetectorPtr>& detectors, const std::vector<AntigenPtr>& self_antigens)
{
	std::vector<DetectorPtr> result;
	for (auto& detector : detectors)
	{
		bool recongnises_self_antigen = false;
		for (auto& antigen : self_antigens)
		{
			if (detector->match(antigen.get()))
			{
				recongnises_self_antigen = true;
				break;
			}
		}
		if (recongnises_self_antigen == false)
		{
			result.push_back(detector);
		}
	}
	detectors.swap(result);
}

/*************************** Positive Selection ***************************/

/*************************** Clonal Selection ***************************/


} // namepsace Algorithm
} // namespace AIS