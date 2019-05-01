#pragma once
#include "BitsArray.h"
#include <memory>

namespace AIS
{

class Antigen
{
public:
	virtual Antigen* clone() const = 0;

	virtual ~Antigen() {};
};


class AntigenWithBitRepresentation : public Antigen
{
public:
	virtual AntigenWithBitRepresentation* clone() const = 0;
	virtual BitsArray get_bitsarray() const = 0;

	virtual ~AntigenWithBitRepresentation();
};

typedef std::shared_ptr<Antigen> AntigenPtr;
typedef std::shared_ptr<AntigenWithBitRepresentation> AntigenWithBitRepresentationPtr;

} // namespace AIS