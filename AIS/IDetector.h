#pragma once
#include "IAntigen.h"
#include <memory>
namespace AIS
{

class IDetector
{
public:
	virtual bool match(const IAntigen* antigen) const = 0;

	virtual ~IDetector();
};

typedef std::shared_ptr<IDetector> DetectorPtr;

template<class T>
class Range
{
public:
	Range(const T& start, const T& end)
		: start_(start)
		, end_(end)
	{
	}

	virtual ~Range()
	{
	}
	
	// [start. end]
	virtual  bool match(const T& value) const
	{
		return start_ <= value && value <= end_;
	}

	// [start. end]
	bool operator()(const T& value) const
	{
		return match(value);
	}
	const T start_;
	const T end_;
};
} // namespace AIS
