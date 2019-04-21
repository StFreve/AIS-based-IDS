#include "KDDDetector.h"
#include <algorithm>

namespace AIS
{

KDDDetector::KDDDetector(size_t start, size_t R,
	const Range<size_t>& duration_range,
	const Range<KDDAntigen::protocol_type>& protocol_type_range,
	const Range<std::string>& service_range,
	const Range<KDDAntigen::connection_state>& flag_range,
	const Range<size_t>& src_bytes_range,
	const Range<size_t>& dst_bytes_range,
	const Range<bool>& land_range,
	const Range<size_t>& wrong_fragment_range,
	const Range<size_t>& urgent_range,
	const Range<size_t>& hot_range,
	const Range<size_t>& num_failed_login_range,
	const Range<bool>& logged_in_range,
	const Range<size_t>& num_compromised_range,
	const Range<bool>& root_shell_range,
	const Range<bool>& su_attempted_range,
	const Range<size_t>& num_root_range,
	const Range<size_t>& num_file_creation_range,
	const Range<size_t>& num_shell_range,
	const Range<size_t>& num_access_files_range,
	const Range<size_t>& num_outbound_cmds_range,
	const Range<bool>& is_hot_login_range,
	const Range<bool>& is_guest_login_range,
	const Range<size_t>& count_range,
	const Range<size_t>& srv_count_range,
	const Range<double>& serror_rate_range,
	const Range<double>& srv_serror_rate_range,
	const Range<double>& rerror_rate_range,
	const Range<double>& src_rerror_rate_range,
	const Range<double>& same_srv_rate_range,
	const Range<double>& diff_srv_rate_range,
	const Range<double>& srv_diff_host_rate_range,
	const Range<size_t>& dst_host_count_range,
	const Range<size_t>& dst_host_srv_count_range,
	const Range<double>& dst_host_same_srv_rate_range,
	const Range<double>& dst_host_diff_srv_rate_range,
	const Range<double>& dst_host_same_src_port_rate_range,
	const Range<double>& dst_host_srv_diff_host_rate_range,
	const Range<double>& dst_host_serror_rate_range,
	const Range<double>& dst_host_srv_serror_rate_range,
	const Range<double>& dst_host_rerror_rate_range,
	const Range<double>& dst_host_srv_rerror_rate_range,
	const Range<size_t>& dummy_range)
	: start_(start)
	, R_(R)
	, duration_range_(duration_range)
	, protocol_type_range_(protocol_type_range)
	, service_range_(service_range)
	, flag_range_(flag_range)
	, src_bytes_range_(src_bytes_range)
	, dst_bytes_range_(dst_bytes_range)
	, land_range_(land_range)
	, wrong_fragment_range_(wrong_fragment_range)
	, urgent_range_(urgent_range)
	, hot_range_(hot_range)
	, num_failed_login_range_(num_failed_login_range)
	, logged_in_range_(logged_in_range)
	, num_compromised_range_(num_compromised_range)
	, root_shell_range_(root_shell_range)
	, su_attempted_range_(su_attempted_range)
	, num_root_range_(num_root_range)
	, num_file_creation_range_(num_file_creation_range)
	, num_shell_range_(num_shell_range)
	, num_access_files_range_(num_access_files_range)
	, num_outbound_cmds_range_(num_outbound_cmds_range)
	, is_hot_login_range_(is_hot_login_range)
	, is_guest_login_range_(is_guest_login_range)
	, count_range_(count_range)
	, srv_count_range_(srv_count_range)
	, serror_rate_range_(serror_rate_range)
	, srv_serror_rate_range_(srv_serror_rate_range)
	, rerror_rate_range_(rerror_rate_range)
	, src_rerror_rate_range_(src_rerror_rate_range)
	, same_srv_rate_range_(same_srv_rate_range)
	, diff_srv_rate_range_(diff_srv_rate_range)
	, srv_diff_host_rate_range_(srv_diff_host_rate_range)
	, dst_host_count_range_(dst_host_count_range)
	, dst_host_srv_count_range_(dst_host_srv_count_range)
	, dst_host_same_srv_rate_range_(dst_host_same_srv_rate_range)
	, dst_host_diff_srv_rate_range_(dst_host_diff_srv_rate_range)
	, dst_host_same_src_port_rate_range_(dst_host_same_src_port_rate_range)
	, dst_host_srv_diff_host_rate_range_(dst_host_srv_diff_host_rate_range)
	, dst_host_serror_rate_range_(dst_host_serror_rate_range)
	, dst_host_srv_serror_rate_range_(dst_host_srv_serror_rate_range)
	, dst_host_rerror_rate_range_(dst_host_rerror_rate_range)
	, dst_host_srv_rerror_rate_range_(dst_host_srv_rerror_rate_range)
	, dummy_range_(dummy_range)
{
}


KDDDetector::~KDDDetector()
{
}

bool KDDDetector::match(const Antigen * antigen) const
{
	const KDDAntigen* kdd_antigen = dynamic_cast<const KDDAntigen*>(antigen);
	if (kdd_antigen == NULL) {
		throw std::runtime_error("KDDDetector can work only with KDDAntigen!");
	}
	size_t max_seq = 0, current_seq = 0, pos = 0;
#define PROCESS(member) \
	if (member##_range_.match(kdd_antigen->get_##member()) && pos++ >= start_) { \
		++current_seq; \
	} \
	else { \
		max_seq = std::max(max_seq, current_seq); \
		current_seq = 0; \
	}

	PROCESS(duration);
	PROCESS(protocol_type);
	//PROCESS(service);
	PROCESS(flag);
	PROCESS(src_bytes);
	PROCESS(dst_bytes);
	PROCESS(land);
	PROCESS(wrong_fragment);
	PROCESS(urgent);
	PROCESS(hot);
	PROCESS(num_failed_login);
	PROCESS(logged_in);
	PROCESS(num_compromised);
	PROCESS(root_shell);
	PROCESS(su_attempted);
	PROCESS(num_root);
	PROCESS(num_file_creation);
	PROCESS(num_shell);
	PROCESS(num_access_files);
	PROCESS(num_outbound_cmds);
	PROCESS(is_hot_login);
	PROCESS(is_guest_login);
	PROCESS(count);
	PROCESS(srv_count);
	PROCESS(serror_rate);
	PROCESS(srv_serror_rate);
	PROCESS(rerror_rate);
	PROCESS(src_rerror_rate);
	PROCESS(same_srv_rate);
	PROCESS(diff_srv_rate);
	PROCESS(srv_diff_host_rate);
	PROCESS(dst_host_count);
	PROCESS(dst_host_srv_count);
	PROCESS(dst_host_same_srv_rate);
	PROCESS(dst_host_diff_srv_rate);
	PROCESS(dst_host_same_src_port_rate);
	PROCESS(dst_host_srv_diff_host_rate);
	PROCESS(dst_host_serror_rate);
	PROCESS(dst_host_srv_serror_rate);
	PROCESS(dst_host_rerror_rate);
	PROCESS(dst_host_srv_rerror_rate);
	//PROCESS(dummy);

#undef PROCESS

	return max_seq >= R_;
}

} // namespace AIS