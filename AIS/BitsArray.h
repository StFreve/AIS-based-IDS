#pragma once
#include <vector>
#include <stdexcept>

namespace AIS
{

static const unsigned char BitsSetTable256[256] =
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
	B6(0), B6(1), B6(1), B6(2)
};

template <class RealByte>
class ByteInterpretation
{
public:
	ByteInterpretation(RealByte byte = 0) : byte_(byte) { }

	inline operator RealByte() const { return byte_; }
	explicit inline operator bool() const { return byte_; }

	inline ByteInterpretation& operator^=(const ByteInterpretation& rhpb) { byte_ ^= rhpb.byte_; return *this; };
	inline ByteInterpretation& operator|=(const ByteInterpretation& rhpb) { byte_ |= rhpb.byte_; return *this; };
	inline ByteInterpretation& operator&=(const ByteInterpretation& rhpb) { byte_ &= rhpb.byte_; return *this; };
	inline ByteInterpretation& operator>>=(size_t shift) { byte_ >>= shift; return *this; };
	inline ByteInterpretation& operator<<=(size_t shift) { byte_ <<= shift; return *this; };

	inline ByteInterpretation operator~() { return ~byte_; };
	inline ByteInterpretation operator^(const ByteInterpretation& rhpb) { return byte_ ^ rhpb.byte_; };
	inline ByteInterpretation operator|(const ByteInterpretation& rhpb) { return byte_ | rhpb.byte_; };
	inline ByteInterpretation operator&(const ByteInterpretation& rhpb) { return byte_ & rhpb.byte_; };
	inline ByteInterpretation& operator>>(size_t shift) { return byte_ >> shift; };
	inline ByteInterpretation& operator<<(size_t shift) { return byte_ << shift; };

	inline bool operator[](size_t index) const
	{
		if (index > 7)
		{
			throw std::runtime_error("Byte contains only 8 bits");
		}
		
		return (byte_ >> index) & 1;
	}

	inline unsigned char count() const
	{
		return BitsSetTable256[byte_];
	}
public:
	RealByte byte_;
};

typedef ByteInterpretation<unsigned char> Byte;
// LSB
class BitsArray
{
public:
	BitsArray();
	BitsArray(const Byte& byte, size_t repeat);
	BitsArray(const std::vector<Byte>& bytes, bool LSB = true);

	size_t count() const;
	size_t size() const;
	BitsArray& operator^=(const BitsArray& lhba);
	BitsArray& operator|=(const BitsArray& lhba);
	BitsArray& operator&=(const BitsArray& lhba);

	BitsArray operator~();
	BitsArray operator^(const BitsArray& lhba) const;
	BitsArray operator|(const BitsArray& lhba) const;
	BitsArray operator&(const BitsArray& lhba) const;

	bool operator==(const BitsArray& lhba);
	bool operator!=(const BitsArray& lhba);

	bool operator[](size_t index) const;
private:

	void count_cache();
	void remove_zeroes();
private:
	std::vector<Byte> bytes_;
	size_t count_;
};

} // namespace AIS