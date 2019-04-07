#include "BitsArray.h"
#include <algorithm>
namespace AIS
{

BitsArray::BitsArray()
	: count_(0)
{
}

BitsArray::BitsArray(const Byte & byte, size_t repeat)
	: bytes_(byte ? repeat : 0, byte)
	, count_(byte ? repeat * byte.count() : 0)
{
}

BitsArray::BitsArray(const std::vector<Byte>& bytes, bool LSB)
	: bytes_(bytes)
	, count_(0)
{
	if (LSB == false)
	{
		std::reverse(bytes_.begin(), bytes_.end());
	}

	remove_zeroes();
}

size_t BitsArray::count() const
{
	return count_;
}

size_t BitsArray::size() const
{
	return bytes_.size() << 3;
}

BitsArray & BitsArray::operator^=(const BitsArray & lhba)
{
	if (lhba.bytes_.size() > bytes_.size())
	{
		bytes_.resize(lhba.size());
	}
	auto bit = bytes_.begin();
	auto be = bytes_.begin();
	auto lhbit = lhba.bytes_.cbegin();
	auto lhbe = lhba.bytes_.cbegin();

	for (;bit != be && lhbit != lhbe; ++bit, ++lhbit)
	{
		*bit ^= *lhbit;
	}

	remove_zeroes();
	count_cache();
	return *this;
}

BitsArray & BitsArray::operator|=(const BitsArray & lhba)
{
	if (lhba.bytes_.size() > bytes_.size())
	{
		bytes_.resize(lhba.size());
	}

	auto bit = bytes_.begin();
	auto be = bytes_.begin();
	auto lhbit = lhba.bytes_.cbegin();
	auto lhbe = lhba.bytes_.cbegin();

	for (;bit != be && lhbit != lhbe; ++bit, ++lhbit)
	{
		*bit |= *lhbit;
	}

	remove_zeroes();
	count_cache();
	return *this;
}

BitsArray & BitsArray::operator&=(const BitsArray & lhba)
{
	if (lhba.bytes_.size() > bytes_.size())
	{
		bytes_.resize(lhba.size());
	}

	auto bit = bytes_.begin();
	auto be = bytes_.begin();
	auto lhbit = lhba.bytes_.cbegin();
	auto lhbe = lhba.bytes_.cbegin();

	for (;bit != be && lhbit != lhbe; ++bit, ++lhbit)
	{
		*bit &= *lhbit;
	}
	remove_zeroes();
	count_cache();
	return *this;
}

BitsArray BitsArray::operator~()
{
	count_ = size() - count_;
	for (auto& byte : bytes_)
	{
		byte = ~byte;
	}
	remove_zeroes();
	return *this;
}

BitsArray BitsArray::operator^(const BitsArray & lhba) const
{
	return BitsArray(*this) ^= lhba;
}

BitsArray BitsArray::operator|(const BitsArray & lhba) const
{
	return BitsArray(*this) |= lhba;
}

BitsArray BitsArray::operator&(const BitsArray & lhba) const
{
	return BitsArray(*this) &= lhba;
}

bool BitsArray::operator==(const BitsArray & lhba)
{
	return bytes_ == lhba.bytes_;
}

bool BitsArray::operator!=(const BitsArray & lhba)
{
	return bytes_ != lhba.bytes_;
}

bool BitsArray::operator[](size_t index) const
{
	if (index >= bytes_.size())
	{
		return 0;
	}
	return bytes_[index >> 3][ index & 7 ];
}

void BitsArray::count_cache()
{
	count_ = 0;
	for (auto& byte : bytes_)
	{
		count_ += byte.count();
	}
}

void BitsArray::remove_zeroes()
{
	while (bytes_.empty() == false && !bytes_.back())
	{
		bytes_.pop_back();
	}
}

} // namespace AIS