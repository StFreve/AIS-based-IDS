#include "RCBDetector.h"
#include <stdexcept>
namespace AIS
{

RCBDetector::RCBDetector(const AntigenWithBitRepresentation* antigen, size_t R)
	: R_(R)
{
	if (antigen == NULL)
	{
		throw std::runtime_error("RCB requres Antigen  to be presented");
	}
	antigen_.reset(antigen->clone());
}

bool RCBDetector::match_impl(const Antigen* antigen) const
{
	const AntigenWithBitRepresentation* antigen_with_bits_representation = dynamic_cast<const AntigenWithBitRepresentation*>(antigen);
	if (antigen_with_bits_representation == NULL)
	{
		throw std::runtime_error("RCB requres Antigen with bits representation to be presented");
	}
	return Algorithms::RContiguousBitsMatchingRule(antigen_->get_bitsarray(), antigen_with_bits_representation->get_bitsarray(), R_);
}

} // namespace AIS