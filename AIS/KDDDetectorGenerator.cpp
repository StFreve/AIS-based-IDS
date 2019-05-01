#include "KDDDetectorGenerator.h"
#include "Utilities.h"

namespace AIS
{

KDDDetectorGenerator::KDDDetectorGenerator()
	: generator_(rd_())
{
}

KDDDetectorGenerator::~KDDDetectorGenerator()
{
}

KDDDetector * KDDDetectorGenerator::generate() const
{
	auto duration_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto protocol_type_range(Utilities::generate_range<KDDAntigen::protocol_type>(generator_));
	auto service_range(Utilities::generate_range<std::string>(generator_));
	auto flag_range(Utilities::generate_range<KDDAntigen::connection_state>(generator_));
	auto src_bytes_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto dst_bytes_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto land_range(Utilities::generate_range<bool>(generator_));
	auto wrong_fragment_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto urgent_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto hot_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto num_failed_login_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto logged_in_range(Utilities::generate_range<bool>(generator_));
	auto num_compromised_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto root_shell_range(Utilities::generate_range<bool>(generator_));
	auto su_attempted_range(Utilities::generate_range<bool>(generator_));
	auto num_root_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto num_file_creation_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto num_shell_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto num_access_files_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto num_outbound_cmds_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto is_hot_login_range(Utilities::generate_range<bool>(generator_));
	auto is_guest_login_range(Utilities::generate_range<bool>(generator_));
	auto count_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto srv_count_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto serror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto srv_serror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto rerror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto src_rerror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto same_srv_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto diff_srv_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto srv_diff_host_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_count_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto dst_host_srv_count_range(Utilities::generate_range<size_t>(generator_, 0, 1000));
	auto dst_host_same_srv_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_diff_srv_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_same_src_port_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_srv_diff_host_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_serror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_srv_serror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_rerror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));
	auto dst_host_srv_rerror_rate_range(Utilities::generate_range<double>(generator_, 0, 1));

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