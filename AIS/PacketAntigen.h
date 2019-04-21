#pragma once
#include "Antigen.h"

namespace AIS
{

class PacketAntigen : public AntigenWithBitRepresentation
{
public:
	PacketAntigen();
	~PacketAntigen();

	virtual PacketAntigen* clone() const;
	virtual BitsArray get_bitsarray() const;
};

} // namespace AIS
