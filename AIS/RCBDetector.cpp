#include "RCBDetector.h"
#include "MatchingRules.h"

namespace AIS
{

template<size_t R, class AntigenWithBitRepresentation>
RCBDetector<R, AntigenWithBitRepresentation>::RCBDetector(const AntigenWithBitRepresentation& antigen)
	: antigen_(antigen)
{
}

template<size_t R, class AntigenWithBitRepresentation>
bool RCBDetector<R, AntigenWithBitRepresentation>::match(const AntigenWithBitRepresentation& antigen) const
{
	return Algorithms::RContiguousBitsMatchingRule<R>(antigen_.get_bitset(), antigen.get_bitset());
}

} // namespace AIS