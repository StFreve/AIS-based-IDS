#pragma once
#include "IAntigen.h"

namespace AIS
{

class PacketAntigen : public IAntigenWithBitRepresentation
{
public:
	PacketAntigen();
	~PacketAntigen();
};

} // namespace AIS
