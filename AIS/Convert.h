#pragma once
#include "KDDAntigen.h"
#include <string>

namespace AIS
{
namespace Convert
{

template<typename E>
E convert_string_to_enum(const std::string& s);

template<>
KDDAntigen::protocol_type convert_string_to_enum<KDDAntigen::protocol_type>(const std::string& type_str)
{
#define CASE(x) if(type_str == #x) return KDDAntigen::protocol_type::x
	CASE(tcp);
	CASE(udp);
	CASE(icmp);
#undef CASE

	throw std::runtime_error("Wrong protocol type!");
}

template<>
KDDAntigen::connection_state convert_string_to_enum<KDDAntigen::connection_state>(const std::string& state_str)
{
#define CASE(x) if(state_str == #x) return KDDAntigen::connection_state::x
	CASE(S0);
	CASE(S1);
	CASE(SF);
	CASE(REJ);
	CASE(S2);
	CASE(S3);
	CASE(RSTO);
	CASE(RSTR);
	CASE(RSTOS0);
	CASE(RSTRH);
	CASE(SH);
	CASE(SHR);
	CASE(OTH);
#undef CASE

	throw std::runtime_error("Wrong connection state!");
}

template<typename E>
std::string convert_enum_to_string(E e);

template<>
std::string convert_enum_to_string<KDDAntigen::protocol_type>(KDDAntigen::protocol_type type)
{
#define CASE(x) case KDDAntigen::protocol_type::x: return #x
	switch (type)
	{
		CASE(tcp);
		CASE(udp);
		CASE(icmp);
	}
#undef CASE

	throw std::runtime_error("Wrong protocol type!");
}

template<>
std::string convert_enum_to_string<KDDAntigen::connection_state>(KDDAntigen::connection_state type)
{
#define CASE(x) case KDDAntigen::connection_state::x: return #x
	switch (type)
	{
		CASE(S0);
		CASE(S1);
		CASE(SF);
		CASE(REJ);
		CASE(S2);
		CASE(S3);
		CASE(RSTO);
		CASE(RSTR);
		CASE(RSTOS0);
		CASE(RSTRH);
		CASE(SH);
		CASE(SHR);
		CASE(OTH);
	}
#undef CASE

	throw std::runtime_error("Wrong connection state!");
}

}
}