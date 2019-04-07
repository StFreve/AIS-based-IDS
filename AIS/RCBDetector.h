#pragma once
#include "IDetector.h"
#include "IAntigen.h"
#include "MatchingRules.h"

#include <stddef.h>

namespace AIS
{

template<class AntigenWithBitRepresentation>
class RCBDetector :	public IDetector
{
public:
	RCBDetector(const AntigenWithBitRepresentation& antigen, size_t R)
		: antigen_(antigen)
		, R_(R)
	{
	}

	bool match(const AntigenWithBitRepresentation& antigen) const
	{
		return Algorithms::RContiguousBitsMatchingRule(antigen_.get_bitarray(), antigen.get_bitarray(), R_);
	}
private:
	const AntigenWithBitRepresentation antigen_;
	const size_t R_;
};

} // namespace AIS