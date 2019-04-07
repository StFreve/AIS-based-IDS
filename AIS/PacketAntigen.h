#pragma once
#include "IAntigen.h"

namespace AIS
{

class PacketAntigen : public IAntigenWithBitRepresentation
{
public:
	PacketAntigen();
	~PacketAntigen();

	virtual PacketAntigen* clone() const;
	virtual BitsArray get_bitsarray() const;
};

} // namespace AIS
