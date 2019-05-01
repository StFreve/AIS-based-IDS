#pragma once
#include "Detector.h"
#include "KDDAntigen.h"

#include <cmath> 
#include <initializer_list>
#include <random>
namespace AIS
{
namespace Utilities
{

template<class T>
Range<T> generate_range(std::default_random_engine& generator);
template<class T>
Range<T> generate_range(std::default_random_engine& generator, T range_start, T range_end);

template<>
inline Range<double> generate_range(std::default_random_engine& generator, double range_start, double range_end)
{
	std::uniform_real_distribution<double> dist(range_start, std::nextafter(range_end, std::numeric_limits<double>::max()));
	double a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
inline Range<size_t> generate_range(std::default_random_engine& generator, size_t range_start, size_t range_end)
{
	std::uniform_int_distribution<size_t> dist(range_start, range_end);
	size_t a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
inline Range<bool> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist(0, 1);
	bool a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
inline Range<KDDAntigen::connection_state> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist((int)KDDAntigen::connection_state::S0, (int)KDDAntigen::connection_state::OTH);
	KDDAntigen::connection_state a = (KDDAntigen::connection_state) dist(generator), b = (KDDAntigen::connection_state) dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
inline Range<KDDAntigen::protocol_type> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist((int)KDDAntigen::protocol_type::tcp, (int)KDDAntigen::protocol_type::icmp);
	KDDAntigen::protocol_type a = (KDDAntigen::protocol_type) dist(generator), b = (KDDAntigen::protocol_type) dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
inline Range<std::string> generate_range(std::default_random_engine& generator)
{
	return { "any", "any" };
}

} // namespace Algorihtm
} // namespace AIS