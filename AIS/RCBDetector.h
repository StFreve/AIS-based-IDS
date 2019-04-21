#pragma once
#include "Detector.h"
#include "Antigen.h"
#include "Algorithms.h"
#include <stdexcept>
#include <stddef.h>

namespace AIS
{

class RCBDetector :	public Detector
{
public:
	RCBDetector(const AntigenWithBitRepresentation* antigen, size_t R);

	virtual bool match(const Antigen* antigen) const override;
private:
	AntigenWithBitRepresentationPtr antigen_;
	const size_t R_;
};

} // namespace AIS