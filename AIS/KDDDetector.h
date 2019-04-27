#pragma once
#include "Detector.h"
#include "Antigen.h"
#include "KDDAntigen.h"
namespace AIS
{

class KDDDetector : public Detector
{
public:
	KDDDetector(size_t start, size_t R,
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
		const Range<double>& dst_host_srv_rerror_rate_range);

	virtual bool match_impl(const Antigen* antigen) const;
	virtual KDDDetector* clone(bool reset_stimations = true) const;
	virtual void mutate();

private:
	KDDDetector(const KDDDetector&) = default;

private:
	size_t start_, R_;

	Range<size_t> duration_range_;
	Range<KDDAntigen::protocol_type> protocol_type_range_;
	Range<std::string> service_range_;
	Range<KDDAntigen::connection_state> flag_range_;
	Range<size_t> src_bytes_range_;
	Range<size_t> dst_bytes_range_;
	Range<bool> land_range_;
	Range<size_t> wrong_fragment_range_;
	Range<size_t> urgent_range_;
	Range<size_t> hot_range_;
	Range<size_t> num_failed_login_range_;
	Range<bool> logged_in_range_;
	Range<size_t> num_compromised_range_;
	Range<bool> root_shell_range_;
	Range<bool> su_attempted_range_;
	Range<size_t> num_root_range_;
	Range<size_t> num_file_creation_range_;
	Range<size_t> num_shell_range_;
	Range<size_t> num_access_files_range_;
	Range<size_t> num_outbound_cmds_range_;
	Range<bool> is_hot_login_range_;
	Range<bool> is_guest_login_range_;
	Range<size_t> count_range_;
	Range<size_t> srv_count_range_;
	Range<double> serror_rate_range_;
	Range<double> srv_serror_rate_range_;
	Range<double> rerror_rate_range_;
	Range<double> src_rerror_rate_range_;
	Range<double> same_srv_rate_range_;
	Range<double> diff_srv_rate_range_;
	Range<double> srv_diff_host_rate_range_;
	Range<size_t> dst_host_count_range_;
	Range<size_t> dst_host_srv_count_range_;
	Range<double> dst_host_same_srv_rate_range_;
	Range<double> dst_host_diff_srv_rate_range_;
	Range<double> dst_host_same_src_port_rate_range_;
	Range<double> dst_host_srv_diff_host_rate_range_;
	Range<double> dst_host_serror_rate_range_;
	Range<double> dst_host_srv_serror_rate_range_;
	Range<double> dst_host_rerror_rate_range_;
	Range<double> dst_host_srv_rerror_rate_range_;
};

} // namespace AIS