#pragma once
#include "BitsArray.h"
#include <memory>
namespace AIS
{

class IAntigen
{
public:
	virtual IAntigen* clone() const = 0;
};


class IAntigenWithBitRepresentation : public IAntigen
{
public:
	virtual IAntigenWithBitRepresentation* clone() const = 0;
	virtual BitsArray get_bitsarray() const = 0;
};

typedef std::shared_ptr<IAntigen> AntigenPtr;
typedef std::shared_ptr<IAntigenWithBitRepresentation> AntigenWithBitRepresentationPtr;

} // namespace AIS