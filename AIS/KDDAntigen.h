#pragma once
#include "Antigen.h"

namespace AIS
{

class KDDAntigen : public Antigen
{
public:
	enum protocol_type
	{
		tcp,
		udp,
		icmp
	};
	enum connection_state
	{
		S0, // Connection attempt seen, no reply.
		S1, // Connection established, not terminated.
		SF, // Normal establishment and termination.Note that this is the same symbol as for state S1.You can tell the two apart because for S1 there will not be any byte counts in the summary, while for SF there will be.
		REJ, // Connection attempt rejected.
		S2, // Connection established and close attempt by originator seen(but no reply from responder).
		S3, // Connection established and close attempt by responder seen(but no reply from originator).
		RSTO, // Connection established, originator aborted(sent a RST).
		RSTR, // Responder sent a RST.
		RSTOS0, // Originator sent a SYN followed by a RST, we never saw a SYN - ACK from the responder.
		RSTRH, // Responder sent a SYN ACK followed by a RST, we never saw a SYN from the(purported) originator.
		SH, // Originator sent a SYN followed by a FIN, we never saw a SYN ACK from the responder(hence the connection was “half” open).
		SHR, // Responder sent a SYN ACK followed by a FIN, we never saw a SYN from the originator.
		OTH // No SYN seen, just midstream traffic(a “partial connection” that was not later closed).
	};

public:
	KDDAntigen(size_t duration,
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
		size_t dummy);
	~KDDAntigen();

	size_t get_duration() const;
	protocol_type get_protocol_type() const;
	std::string get_service() const;
	connection_state get_flag() const;
	size_t get_src_bytes() const;
	size_t get_dst_bytes() const;
	bool get_land() const;
	size_t get_wrong_fragment() const;
	size_t get_urgent() const;
	size_t get_hot() const;
	size_t get_num_failed_login() const;
	bool get_logged_in() const;
	size_t get_num_compromised() const;
	bool get_root_shell() const;
	bool get_su_attempted() const;
	size_t get_num_root() const;
	size_t get_num_file_creation() const;
	size_t get_num_shell() const;
	size_t get_num_access_files() const;
	size_t get_num_outbound_cmds() const;
	bool get_is_hot_login() const;
	bool get_is_guest_login() const;
	size_t get_count() const;
	size_t get_srv_count() const;
	double get_serror_rate() const;
	double get_srv_serror_rate() const;
	double get_rerror_rate() const;
	double get_src_rerror_rate() const;
	double get_same_srv_rate() const;
	double get_diff_srv_rate() const;
	double get_srv_diff_host_rate() const;
	size_t get_dst_host_count() const;
	size_t get_dst_host_srv_count() const;
	double get_dst_host_same_srv_rate() const;
	double get_dst_host_diff_srv_rate() const;
	double get_dst_host_same_src_port_rate() const;
	double get_dst_host_srv_diff_host_rate() const;
	double get_dst_host_serror_rate() const;
	double get_dst_host_srv_serror_rate() const;
	double get_dst_host_rerror_rate() const;
	double get_dst_host_srv_rerror_rate() const;
	size_t get_dummy() const;

	virtual KDDAntigen* clone() const;
private:
	size_t duration_;
	protocol_type protocol_type_;
	std::string service_;
	connection_state flag_;
	size_t src_bytes_;
	size_t dst_bytes_;
	bool land_;
	size_t wrong_fragment_;
	size_t urgent_;
	size_t hot_;
	size_t num_failed_login_;
	bool logged_in_;
	size_t num_compromised_;
	bool root_shell_;
	bool su_attempted_;
	size_t num_root_;
	size_t num_file_creation_;
	size_t num_shell_;
	size_t num_access_files_;
	size_t num_outbound_cmds_;
	bool is_hot_login_;
	bool is_guest_login_;
	size_t count_;
	size_t srv_count_;
	double serror_rate_;
	double srv_serror_rate_;
	double rerror_rate_;
	double src_rerror_rate_;
	double same_srv_rate_;
	double diff_srv_rate_;
	double srv_diff_host_rate_;
	size_t dst_host_count_;
	size_t dst_host_srv_count_;
	double dst_host_same_srv_rate_;
	double dst_host_diff_srv_rate_;
	double dst_host_same_src_port_rate_;
	double dst_host_srv_diff_host_rate_;
	double dst_host_serror_rate_;
	double dst_host_srv_serror_rate_;
	double dst_host_rerror_rate_;
	double dst_host_srv_rerror_rate_;
	size_t dummy_;
};

typedef std::shared_ptr<KDDAntigen> KDDAntigenPtr;
} // namespace AIS