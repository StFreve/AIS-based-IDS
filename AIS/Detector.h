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
	Detector(const Detector& rhd);

	virtual ~Detector();

	bool match(const Antigen* antigen) const;
	size_t stimulated() const;
	void reset();

public:
	virtual Detector* clone() const = 0;
	virtual void mutate() = 0;

protected:
	virtual bool match_impl(const Antigen* antigen) const = 0;

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

	Range(const Range& rhr)
		: start_(rhr.start_)
		, end_(rhr.end_)
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

	T start_;
	T end_;
};

} // namespace AIS
