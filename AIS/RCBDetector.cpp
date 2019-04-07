#include "RCBDetector.h"
#include <stdexcept>
namespace AIS
{

RCBDetector::RCBDetector(const IAntigenWithBitRepresentation* antigen, size_t R)
	: R_(R)
{
	if (antigen == NULL)
	{
		throw std::runtime_error("RCB requres Antigen  to be presented");
	}
	antigen_.reset(antigen->clone());
}

bool RCBDetector::match(const IAntigen* antigen) const
{
	const IAntigenWithBitRepresentation* antigen_with_bits_representation = dynamic_cast<const IAntigenWithBitRepresentation*>(antigen);
	if (antigen_with_bits_representation == NULL)
	{
		throw std::runtime_error("RCB requres Antigen with bits representation to be presented");
	}
	return Algorithms::RContiguousBitsMatchingRule(antigen_->get_bitsarray(), antigen_with_bits_representation->get_bitsarray(), R_);
}

} // namespace AIS