#pragma once
#include <vector>
#include <string>
#include <stdexcept>

class BitArray
{
public:
	BitArray();
	virtual ~BitArray();
	explicit BitArray(unsigned long nBits, unsigned long value);
	BitArray(const BitArray& b);

	void swap(BitArray& b);
	void resize(unsigned long nBits, bool value);
	void clear();
	void pushBack(bool bit);
	void set();
	void set(int n, bool value);
	void reset();
	void reset(int n);

	bool any() const;
	bool none() const;
	bool empty() const;
	bool operator[](int i) const;
	bool operator==(const BitArray& a) const;
	bool operator!=(const BitArray& a) const;

	int count() const;
	size_t size() const;

	std::string toString() const;

	BitArray& operator=(const BitArray& b);
	BitArray& operator&=(const BitArray& b);
	BitArray& operator|=(const BitArray& b);
	BitArray& operator^=(const BitArray& b);
	BitArray& operator<<(int n);
	BitArray& operator>>(int n);

	BitArray operator<<(int n) const;
	BitArray operator>>(int n) const;
	BitArray operator~();
	
private:
	void insertBit(bool bit, size_t position);
	void insertBits(bool value, size_t begin, size_t end);
	std::vector<unsigned long> _array;
	size_t _size;
};

BitArray operator&(const BitArray& b1, const BitArray& b2);
BitArray operator|(const BitArray& b1, const BitArray& b2);
BitArray operator^(const BitArray& b1, const BitArray& b2);
