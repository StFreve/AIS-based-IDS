#pragma once
#include "IDetector.h"
#include <stddef.h>

namespace AIS
{

template<size_t R, class AntigenWithBitRepresentation>
class RCBDetector :	public IDetector<AntigenWithBitRepresentation>
{
public:
	RCBDetector(const AntigenWithBitRepresentation& antigen);

	bool match(const AntigenWithBitRepresentation& antigen) const;
private:
	const AntigenWithBitRepresentation antigen_;
};

} // namespace AIS