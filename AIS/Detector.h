#pragma once
#include "Antigen.h"
#include <memory>
#include <atomic>
namespace AIS
{

class Detector
{
public:
	Detector();
	virtual ~Detector();;

	virtual bool match(const Antigen* antigen) const = 0;

public:
	size_t stimulated_counter() const;
	void reset_stimulatated_counter();
	void stimulated() const;

private:
	mutable std::atomic<size_t> stimulated_counter_;
};

typedef std::shared_ptr<Detector> DetectorPtr;

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
