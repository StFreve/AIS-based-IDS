#pragma once
#include <bitset>
#include <vector>
namespace Distance
{
	template<size_t SIZE>
	size_t Hamming(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		return (bits_1 ^ bits_2).count();
	}

	template<size_t SIZE>
	std::vector<size_t>&& Binary(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		std::vector<int> result(4, 0);
		for (int i = 0; i < SIZE; ++i) {
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

	template<size_t SIZE>
	double RusselAndRao(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0];
		double denominator = binary_distances[0] + binary_distances[1] +
			binary_distances[2] + binary_distances[3];
		return denominator ? numerator / denominator : 0;
	}

	template<size_t SIZE>
	double JacardAndNeedham(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0];
		double denominator = binary_distances[0] + binary_distances[1] +
			binary_distances[2];
		return denominator ? numerator / denominator : 0;
	}

	template<size_t SIZE>
	double Kulzinski(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0];
		double denominator = 1 + binary_distances[1] +
			binary_distances[2];
		return numerator / denominator;
	}

	template<size_t SIZE>
	double RogersAndTanimoto(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0] + binary_distances[3];
		double denominator = binary_distances[0] + 2 * ( binary_distances[1] +
			binary_distances[2] ) + binary_distances[3];
		return denominator ? numerator / denominator : 0;
	}

	template<size_t SIZE>
	double Yule(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0]*binary_distances[3] -
			binary_distances[1]*binary_distances[2];
		double denominator = binary_distances[0] * binary_distances[3] +
			binary_distances[1] * binary_distances[2];
		return denominator ? numerator / denominator : 0;
	}

	template<size_t SIZE>
	double SokalAndMichener(const std::bitset<SIZE>& bits_1, const std::bitset<SIZE>& bits_2)
	{
		auto binary_distances = std::move(Binary(bits_1, bits_2));

		double numerator = binary_distances[0] + binary_distances[3];
		double denominator = binary_distances[0] + binary_distances[1] +
			binary_distances[2] + binary_distances[3];
		return denominator ? numerator / denominator : 0;
	}
}