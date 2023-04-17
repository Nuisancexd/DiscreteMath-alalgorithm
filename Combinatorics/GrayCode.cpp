#include <iostream>
#include <bitset>

template<const unsigned int n>
uint64_t gray_encode(std::bitset<n> v)
{
	v = v ^ (v >> 1);
	return v.to_ulong();
}

template<const unsigned int n>
uint64_t gray_dencode(std::bitset<n> v)
{
	v = v ^ (v >> 1);

	for (int i = 2; i < v.size(); i *= 2)
	{
		v = v ^ (v >> i);
	}

	return v.to_ulong();
}

int main()
{
	std::bitset<5>bs(22);
	constexpr unsigned int n = bs.size();
	uint64_t g = gray_encode<n>(bs);
	std::bitset<5>d(g);
	std::cout << d << "\t\t" << g << std::endl;

	constexpr unsigned int nn = d.size();
	uint64_t dg = gray_dencode<nn>(d);
	std::bitset<5>dd(dg);
	std::cout << dd << "\t\t" << dg << std::endl;
}
