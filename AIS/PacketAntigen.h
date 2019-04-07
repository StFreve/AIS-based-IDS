#pragma once
#include "IAntigen.h"

namespace AIS
{

template <size_t MAX_PACKET_SIZE>
class PacketAntigen :
	public IAntigenWithBitRepresentation<MAX_PACKET_SIZE* 8 /* convert Bytes in Bits */>
{
public:
	PacketAntigen();
	~PacketAntigen();
};

} // namespace AIS
