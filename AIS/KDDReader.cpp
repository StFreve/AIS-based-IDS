#include "KDDReader.h"
#include "Convert.h"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
namespace AIS
{

KDDReader::KDDReader(const std::string& kdd_set_path)
	: kdd_set_(kdd_set_path)
{
}

KDDReader::~KDDReader()
{
}

KDDReader::AntigenWithStatus KDDReader::read_line()
{
	AntigenWithStatus kdd_antigen_with_status;

	std::vector<std::string> result;
	std::string line, cell;
	std::getline(kdd_set_, line);

	std::stringstream readingStream(line), convertingStream;
	while (std::getline(readingStream, cell, ','))
	{
		result.push_back(cell);
	}

	if (result.size() != 42) {
		throw std::runtime_error("Wrong line in kdd dataset!");
	}

	std::stringstream lineStream;
	std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(convertingStream, "\n"));

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
	/* bool */ size_t su_attempted;
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
	std::string class_str;

	convertingStream >> duration;
	convertingStream >> protocol_type_str;
	convertingStream >> service;
	convertingStream >> connection_state_str;
	convertingStream >> src_bytes;
	convertingStream >> dst_bytes;
	convertingStream >> land;
	convertingStream >> wrong_fragment;
	convertingStream >> urgent;
	convertingStream >> hot;
	convertingStream >> num_failed_login;
	convertingStream >> logged_in;
	convertingStream >> num_compromised;
	convertingStream >> root_shell;
	convertingStream >> su_attempted;
	convertingStream >> num_root;
	convertingStream >> num_file_creation;
	convertingStream >> num_shell;
	convertingStream >> num_access_files;
	convertingStream >> num_outbound_cmds;
	convertingStream >> is_hot_login;
	convertingStream >> is_guest_login;
	convertingStream >> count;
	convertingStream >> srv_count;
	convertingStream >> serror_rate;
	convertingStream >> srv_serror_rate;
	convertingStream >> rerror_rate;
	convertingStream >> src_rerror_rate;
	convertingStream >> same_srv_rate;
	convertingStream >> diff_srv_rate;
	convertingStream >> srv_diff_host_rate;
	convertingStream >> dst_host_count;
	convertingStream >> dst_host_srv_count;
	convertingStream >> dst_host_same_srv_rate;
	convertingStream >> dst_host_diff_srv_rate;
	convertingStream >> dst_host_same_src_port_rate;
	convertingStream >> dst_host_srv_diff_host_rate;
	convertingStream >> dst_host_serror_rate;
	convertingStream >> dst_host_srv_serror_rate;
	convertingStream >> dst_host_rerror_rate;
	convertingStream >> dst_host_srv_rerror_rate;
	convertingStream >> class_str;

	KDDAntigen::protocol_type protocol_type = Convert::convert_string_to_enum<KDDAntigen::protocol_type>(protocol_type_str);
	KDDAntigen::connection_state flag = Convert::convert_string_to_enum<KDDAntigen::connection_state>(connection_state_str);
	kdd_antigen_with_status.first.reset(new KDDAntigen(duration,
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
		dst_host_srv_rerror_rate));

	if (class_str.empty()) {
		throw std::runtime_error("Wrong line in kdd dataset! No class where specified!");
	}
	if (class_str.back() == '.') {
		class_str.pop_back();
	}

	kdd_antigen_with_status.second = (class_str == "normal"); // is Normal

	return kdd_antigen_with_status;
}

KDDReader::AntigenWithStatusList KDDReader::read_chunk(size_t chunk_size)
{
	AntigenWithStatusList kdd_antigens;

	while (kdd_set_.good() && kdd_antigens.size() < chunk_size) {
		try {
			kdd_antigens.push_back(read_line());
		} 
		catch (const std::exception& err) {
			std::cerr << "Failed to parse line from kdd dataset: " << err.what() << std::endl;
		}
	}

	return kdd_antigens;
}

KDDReader::AntigenWithStatusList AIS::KDDReader::read_all()
{
	return read_chunk(-1);
}

bool KDDReader::eof() const
{
	return kdd_set_.eof();
}

} // namespace AIS