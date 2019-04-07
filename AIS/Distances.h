#pragma once
#include "BitsArray.h"
#include <vector>
#include <algorithm>
namespace AIS
{
namespace Algorithms
{

size_t HammingDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	return (bits_1 ^ bits_2).count();
}

std::vector<size_t>&& BinaryDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	std::vector<int> result(4, 0);
	size_t max_size = std::max(bits_1.size(), bits_2.size());
	for (int i = 0; i < max_size; ++i) {
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
}

double RusselAndRaoDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2] + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}

double JacardAndNeedhamDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2];
	return denominator ? numerator / denominator : 0;
}

double KulzinskiDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0];
	double denominator = 1 + binary_distances[1] +
		binary_distances[2];
	return numerator / denominator;
}

double RogersAndTanimotoDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0] + binary_distances[3];
	double denominator = binary_distances[0] + 2 * ( binary_distances[1] +
		binary_distances[2] ) + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}

double YuleDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0]*binary_distances[3] -
		binary_distances[1]*binary_distances[2];
	double denominator = binary_distances[0] * binary_distances[3] +
		binary_distances[1] * binary_distances[2];
	return denominator ? numerator / denominator : 0;
}

double SokalAndMichenerDistance(const BitsArray& bits_1, const BitsArray& bits_2)
{
	auto binary_distances = std::move(BinaryDistance(bits_1, bits_2));

	double numerator = binary_distances[0] + binary_distances[3];
	double denominator = binary_distances[0] + binary_distances[1] +
		binary_distances[2] + binary_distances[3];
	return denominator ? numerator / denominator : 0;
}

} // namepsace Algorithm
} // namespace AIS