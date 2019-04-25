#include "KDDDetectorGenerator.h"
#include <cmath> 

namespace AIS
{

template<class T>
Range<T> generate_range(std::default_random_engine& generator);

template<>
Range<double> generate_range(std::default_random_engine& generator)
{
	std::uniform_real_distribution<double> dist(0.0, std::nextafter(1.0, std::numeric_limits<double>::max()));
	double a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
Range<size_t> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<size_t> dist(0, 1000);
	size_t a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
Range<bool> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist(0, 1);
	bool a = dist(generator), b = dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
Range<KDDAntigen::connection_state> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist((int)KDDAntigen::connection_state::S0, (int)KDDAntigen::connection_state::OTH);
	KDDAntigen::connection_state a = (KDDAntigen::connection_state) dist(generator), b = (KDDAntigen::connection_state) dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
Range<KDDAntigen::protocol_type> generate_range(std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> dist((int)KDDAntigen::protocol_type::tcp, (int)KDDAntigen::protocol_type::icmp);
	KDDAntigen::protocol_type a = (KDDAntigen::protocol_type) dist(generator), b = (KDDAntigen::protocol_type) dist(generator);
	if (a > b) {
		std::swap(a, b);
	}
	return { a, b };
}

template<>
Range<std::string> generate_range(std::default_random_engine& generator)
{
	return { "any", "any" };
}

KDDDetectorGenerator::KDDDetectorGenerator()
	: generator_(rd_())
{
}

KDDDetectorGenerator::~KDDDetectorGenerator()
{
}

KDDDetector * KDDDetectorGenerator::generate() const
{
	auto duration_range(generate_range<size_t>(generator_));
	auto protocol_type_range(generate_range<KDDAntigen::protocol_type>(generator_));
	auto service_range(generate_range<std::string>(generator_));
	auto flag_range(generate_range<KDDAntigen::connection_state>(generator_));
	auto src_bytes_range(generate_range<size_t>(generator_));
	auto dst_bytes_range(generate_range<size_t>(generator_));
	auto land_range(generate_range<bool>(generator_));
	auto wrong_fragment_range(generate_range<size_t>(generator_));
	auto urgent_range(generate_range<size_t>(generator_));
	auto hot_range(generate_range<size_t>(generator_));
	auto num_failed_login_range(generate_range<size_t>(generator_));
	auto logged_in_range(generate_range<bool>(generator_));
	auto num_compromised_range(generate_range<size_t>(generator_));
	auto root_shell_range(generate_range<bool>(generator_));
	auto su_attempted_range(generate_range<bool>(generator_));
	auto num_root_range(generate_range<size_t>(generator_));
	auto num_file_creation_range(generate_range<size_t>(generator_));
	auto num_shell_range(generate_range<size_t>(generator_));
	auto num_access_files_range(generate_range<size_t>(generator_));
	auto num_outbound_cmds_range(generate_range<size_t>(generator_));
	auto is_hot_login_range(generate_range<bool>(generator_));
	auto is_guest_login_range(generate_range<bool>(generator_));
	auto count_range(generate_range<size_t>(generator_));
	auto srv_count_range(generate_range<size_t>(generator_));
	auto serror_rate_range(generate_range<double>(generator_));
	auto srv_serror_rate_range(generate_range<double>(generator_));
	auto rerror_rate_range(generate_range<double>(generator_));
	auto src_rerror_rate_range(generate_range<double>(generator_));
	auto same_srv_rate_range(generate_range<double>(generator_));
	auto diff_srv_rate_range(generate_range<double>(generator_));
	auto srv_diff_host_rate_range(generate_range<double>(generator_));
	auto dst_host_count_range(generate_range<size_t>(generator_));
	auto dst_host_srv_count_range(generate_range<size_t>(generator_));
	auto dst_host_same_srv_rate_range(generate_range<double>(generator_));
	auto dst_host_diff_srv_rate_range(generate_range<double>(generator_));
	auto dst_host_same_src_port_rate_range(generate_range<double>(generator_));
	auto dst_host_srv_diff_host_rate_range(generate_range<double>(generator_));
	auto dst_host_serror_rate_range(generate_range<double>(generator_));
	auto dst_host_srv_serror_rate_range(generate_range<double>(generator_));
	auto dst_host_rerror_rate_range(generate_range<double>(generator_));
	auto dst_host_srv_rerror_rate_range(generate_range<double>(generator_));

	return new KDDDetector(0, 4,
		duration_range,
		protocol_type_range,
		service_range,
		flag_range,
		src_bytes_range,
		dst_bytes_range,
		land_range,
		wrong_fragment_range,
		urgent_range,
		hot_range,
		num_failed_login_range,
		logged_in_range,
		num_compromised_range,
		root_shell_range,
		su_attempted_range,
		num_root_range,
		num_file_creation_range,
		num_shell_range,
		num_access_files_range,
		num_outbound_cmds_range,
		is_hot_login_range,
		is_guest_login_range,
		count_range,
		srv_count_range,
		serror_rate_range,
		srv_serror_rate_range,
		rerror_rate_range,
		src_rerror_rate_range,
		same_srv_rate_range,
		diff_srv_rate_range,
		srv_diff_host_rate_range,
		dst_host_count_range,
		dst_host_srv_count_range,
		dst_host_same_srv_rate_range,
		dst_host_diff_srv_rate_range,
		dst_host_same_src_port_rate_range,
		dst_host_srv_diff_host_rate_range,
		dst_host_serror_rate_range,
		dst_host_srv_serror_rate_range,
		dst_host_rerror_rate_range,
		dst_host_srv_rerror_rate_range);
}

}