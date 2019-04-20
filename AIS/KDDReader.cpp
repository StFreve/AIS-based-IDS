#include "KDDReader.h"
#include "Convert.h"

namespace AIS
{

KDDReader::KDDReader(const std::string& kdd_set_path)
	: kdd_set_(kdd_set_path)
{
	// Read Header
	std::string temp;
	std::getline(kdd_set_, temp);
}


KDDReader::~KDDReader()
{
}

std::vector<std::pair<KDDAntigenPtr, bool>> KDDReader::read_chunk(size_t chunk_size)
{
	std::vector<std::pair<KDDAntigenPtr, bool> > kdd_antigens;

	size_t duration;
	std::string protocol_type_str;
	std::string service;
	std::string connection_state_str;
	size_t src_bytes;
	size_t dst_bytes;
	bool land;
	size_t wrong_fragment;
	size_t urgent;
	size_t hot;
	size_t num_failed_login;
	bool logged_in;
	size_t num_compromised;
	bool root_shell;
	bool su_attempted;
	size_t num_root;
	size_t num_file_creation;
	size_t num_shell;
	size_t num_access_files;
	size_t num_outbound_cmds;
	bool is_hot_login;
	bool is_guest_login;
	size_t count;
	size_t srv_count;
	double serror_rate;
	double srv_serror_rate;
	double rerror_rate;
	double src_rerror_rate;
	double same_srv_rate;
	double diff_srv_rate;
	double srv_diff_host_rate;
	size_t dst_host_count;
	size_t dst_host_srv_count;
	double dst_host_same_srv_rate;
	double dst_host_diff_srv_rate;
	double dst_host_same_src_port_rate;
	double dst_host_srv_diff_host_rate;
	double dst_host_serror_rate;
	double dst_host_srv_serror_rate;
	double dst_host_rerror_rate;
	double dst_host_srv_rerror_rate;
	size_t dummy;
	std::string class_str;

	while (kdd_set_ >> duration
		>> protocol_type_str
		>> service
		>> connection_state_str
		>> src_bytes
		>> dst_bytes
		>> land
		>> wrong_fragment
		>> urgent
		>> hot
		>> num_failed_login
		>> logged_in
		>> num_compromised
		>> root_shell
		>> su_attempted
		>> num_root
		>> num_file_creation
		>> num_shell
		>> num_access_files
		>> num_outbound_cmds
		>> is_hot_login
		>> is_guest_login
		>> count
		>> srv_count
		>> serror_rate
		>> srv_serror_rate
		>> rerror_rate
		>> src_rerror_rate
		>> same_srv_rate
		>> diff_srv_rate
		>> srv_diff_host_rate
		>> dst_host_count
		>> dst_host_srv_count
		>> dst_host_same_srv_rate
		>> dst_host_diff_srv_rate
		>> dst_host_same_src_port_rate
		>> dst_host_srv_diff_host_rate
		>> dst_host_serror_rate
		>> dst_host_srv_serror_rate
		>> dst_host_rerror_rate
		>> dst_host_srv_rerror_rate
		>> class_str
		>> dummy)
	{
		KDDAntigen::protocol_type protocol_type = Convert::convert_string_to_enum<KDDAntigen::protocol_type>(protocol_type_str);
		KDDAntigen::connection_state flag = Convert::convert_string_to_enum<KDDAntigen::connection_state>(connection_state_str);
		kdd_antigens.push_back(
			{
				KDDAntigenPtr(new KDDAntigen(duration,
					protocol_type,
					service,
					flag,
					src_bytes,
					dst_bytes,
					land,
					wrong_fragment,
					urgent,
					hot,
					num_failed_login,
					logged_in,
					num_compromised,
					root_shell,
					su_attempted,
					num_root,
					num_file_creation,
					num_shell,
					num_access_files,
					num_outbound_cmds,
					is_hot_login,
					is_guest_login,
					count,
					srv_count,
					serror_rate,
					srv_serror_rate,
					rerror_rate,
					src_rerror_rate,
					same_srv_rate,
					diff_srv_rate,
					srv_diff_host_rate,
					dst_host_count,
					dst_host_srv_count,
					dst_host_same_srv_rate,
					dst_host_diff_srv_rate,
					dst_host_same_src_port_rate,
					dst_host_srv_diff_host_rate,
					dst_host_serror_rate,
					dst_host_srv_serror_rate,
					dst_host_rerror_rate,
					dst_host_srv_rerror_rate,
					dummy)),
				class_str == "normal" /* is Normal */
			}
		);
		if (kdd_antigens.size() == chunk_size) {
			break;
		}
	}
	return kdd_antigens;
}

std::vector<std::pair<KDDAntigenPtr, bool>> AIS::KDDReader::read_all()
{
	return read_chunk(-1);
}

bool KDDReader::eof() const
{
	return kdd_set_.eof();
}

} // namespace AIS