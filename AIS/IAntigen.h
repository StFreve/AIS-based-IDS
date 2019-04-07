#pragma once
#include <bitset>

namespace AIS
{

class IAntigen
{
};

template <size_t SIZE>
class IAntigenWithBitRepresentation : public IAntigen
{
public:
	std::bitset<SIZE> get_bitset() const = 0;
};

} // namespace AIS