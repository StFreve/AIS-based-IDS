#pragma once
namespace AIS
{

template<class AntigenType>
class IDetector
{
public:
	bool match(const AntigenType& antigen) const = 0;
};

} // namespace AIS
