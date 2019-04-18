#include "KDDAntigen.h"

namespace AIS
{

KDDAntigen::KDDAntigen(size_t duration,
	protocol_type protocol_type,
	std::string service,
	connection_state flag,
	size_t src_bytes,
	size_t dst_bytes,
	bool land,
	size_t wrong_fragment,
	size_t urgent,
	size_t hot,
	size_t num_failed_login,
	bool logged_in,
	size_t num_compromised,
	bool root_shell,
	bool su_attempted,
	size_t num_root,
	size_t num_file_creation,
	size_t num_shell,
	size_t num_access_files,
	size_t num_outbound_cmds,
	bool is_hot_login,
	bool is_guest_login,
	size_t count,
	size_t srv_count,
	double serror_rate,
	double srv_serror_rate,
	double rerror_rate,
	double src_rerror_rate,
	double same_srv_rate,
	double diff_srv_rate,
	double srv_diff_host_rate,
	size_t dst_host_count,
	size_t dst_host_srv_count,
	double dst_host_same_srv_rate,
	double dst_host_diff_srv_rate,
	double dst_host_same_src_port_rate,
	double dst_host_srv_diff_host_rate,
	double dst_host_serror_rate,
	double dst_host_srv_serror_rate,
	double dst_host_rerror_rate,
	double dst_host_srv_rerror_rate,
	size_t dummy)
	: duration_(duration)
	, protocol_type_(protocol_type)
	, service_(service)
	, flag_(flag)
	, src_bytes_(src_bytes)
	, dst_bytes_(dst_bytes)
	, land_(land)
	, wrong_fragment_(wrong_fragment)
	, urgent_(urgent)
	, hot_(hot)
	, num_failed_login_(num_failed_login)
	, logged_in_(logged_in)
	, num_compromised_(num_compromised)
	, root_shell_(root_shell)
	, su_attempted_(su_attempted)
	, num_root_(num_root)
	, num_file_creation_(num_file_creation)
	, num_shell_(num_shell)
	, num_access_files_(num_access_files)
	, num_outbound_cmds_(num_outbound_cmds)
	, is_hot_login_(is_hot_login)
	, is_guest_login_(is_guest_login)
	, count_(count)
	, srv_count_(srv_count)
	, serror_rate_(serror_rate)
	, srv_serror_rate_(srv_serror_rate)
	, rerror_rate_(rerror_rate)
	, src_rerror_rate_(src_rerror_rate)
	, same_srv_rate_(same_srv_rate)
	, diff_srv_rate_(diff_srv_rate)
	, srv_diff_host_rate_(srv_diff_host_rate)
	, dst_host_count_(dst_host_count)
	, dst_host_srv_count_(dst_host_srv_count)
	, dst_host_same_srv_rate_(dst_host_same_srv_rate)
	, dst_host_diff_srv_rate_(dst_host_diff_srv_rate)
	, dst_host_same_src_port_rate_(dst_host_same_src_port_rate)
	, dst_host_srv_diff_host_rate_(dst_host_srv_diff_host_rate)
	, dst_host_serror_rate_(dst_host_serror_rate)
	, dst_host_srv_serror_rate_(dst_host_srv_serror_rate)
	, dst_host_rerror_rate_(dst_host_rerror_rate)
	, dst_host_srv_rerror_rate_(dst_host_srv_rerror_rate)
	, dummy_(dummy)
{
}

KDDAntigen::~KDDAntigen()
{
}

size_t KDDAntigen::get_duration() const { return duration_; }

KDDAntigen::protocol_type KDDAntigen::get_protocol_type() const { return protocol_type_; }

std::string KDDAntigen::get_service() const { return service_; }

KDDAntigen::connection_state KDDAntigen::get_flag() const { return flag_; }

size_t KDDAntigen::get_src_bytes() const { return src_bytes_; }

size_t KDDAntigen::get_dst_bytes() const { return dst_bytes_; }

bool KDDAntigen::get_land() const { return land_; }

size_t KDDAntigen::get_wrong_fragment() const { return wrong_fragment_; }

size_t KDDAntigen::get_urgent() const { return urgent_; }

size_t KDDAntigen::get_hot() const { return hot_; }

size_t KDDAntigen::get_num_failed_login() const { return num_failed_login_; }

bool KDDAntigen::get_logged_in() const { return logged_in_; }

size_t KDDAntigen::get_num_compromised() const { return num_compromised_; }

bool KDDAntigen::get_root_shell() const { return root_shell_; }

bool KDDAntigen::get_su_attempted() const { return su_attempted_; }

size_t KDDAntigen::get_num_root() const { return num_root_; }

size_t KDDAntigen::get_num_file_creation() const { return num_file_creation_; }

size_t KDDAntigen::get_num_shell() const { return num_shell_; }

size_t KDDAntigen::get_num_access_files() const { return num_access_files_; }

size_t KDDAntigen::get_num_outbound_cmds() const { return num_outbound_cmds_; }

bool KDDAntigen::get_is_hot_login() const { return is_hot_login_; }

bool KDDAntigen::get_is_guest_login() const { return is_guest_login_; }

size_t KDDAntigen::get_count() const { return count_; }

size_t KDDAntigen::get_srv_count() const { return srv_count_; }

double KDDAntigen::get_serror_rate() const { return serror_rate_; }

double KDDAntigen::get_srv_serror_rate() const { return srv_serror_rate_; }

double KDDAntigen::get_rerror_rate() const { return rerror_rate_; }

double KDDAntigen::get_src_rerror_rate() const { return src_rerror_rate_; }

double KDDAntigen::get_same_srv_rate() const { return same_srv_rate_; }

double KDDAntigen::get_diff_srv_rate() const { return diff_srv_rate_; }

double KDDAntigen::get_srv_diff_host_rate() const { return srv_diff_host_rate_; }

size_t KDDAntigen::get_dst_host_count() const { return dst_host_count_; }

size_t KDDAntigen::get_dst_host_srv_count() const { return dst_host_srv_count_; }

double KDDAntigen::get_dst_host_same_srv_rate() const { return dst_host_same_srv_rate_; }

double KDDAntigen::get_dst_host_diff_srv_rate() const { return dst_host_diff_srv_rate_; }

double KDDAntigen::get_dst_host_same_src_port_rate() const { return dst_host_same_src_port_rate_; }

double KDDAntigen::get_dst_host_srv_diff_host_rate() const { return dst_host_srv_diff_host_rate_; }

double KDDAntigen::get_dst_host_serror_rate() const { return dst_host_serror_rate_; }

double KDDAntigen::get_dst_host_srv_serror_rate() const { return dst_host_srv_serror_rate_; }

double KDDAntigen::get_dst_host_rerror_rate() const { return dst_host_rerror_rate_; }

double KDDAntigen::get_dst_host_srv_rerror_rate() const { return dst_host_srv_rerror_rate_; }

size_t KDDAntigen::get_dummy() const { return dummy_; }

KDDAntigen* KDDAntigen::clone() const { return new KDDAntigen(*this); }

} // namespace AIS