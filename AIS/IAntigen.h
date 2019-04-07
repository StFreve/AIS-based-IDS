#pragma once
#include "BitsArray.h"

namespace AIS
{

class IAntigen
{
};


class IAntigenWithBitRepresentation : public IAntigen
{
public:
	virtual BitsArray get_bitarray() const = 0;
};

} // namespace AIS