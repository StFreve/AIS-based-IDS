#pragma once
#include "IDetector.h"
#include "IAntigen.h"
#include "Algorithms.h"
#include <stdexcept>
#include <stddef.h>

namespace AIS
{

class RCBDetector :	public IDetector
{
public:
	RCBDetector(const IAntigenWithBitRepresentation* antigen, size_t R);

	virtual bool match(const IAntigen* antigen) const override;
private:
	AntigenWithBitRepresentationPtr antigen_;
	const size_t R_;
};

} // namespace AIS