#include "Fixed.hpp"
#include <iostream>
#include <cassert>

int	main(void)
{
	std::cout << "=== ex00 tests ===" << std::endl << std::endl;

	{
		Fixed a;
		assert(a.getRawBits() == 0);
		std::cout << "[OK] default constructor initializes raw value to 0" << std::endl;
	}
	{
		Fixed a;
		a.setRawBits(42);
		Fixed b(a);
		assert(b.getRawBits() == 42);
		std::cout << "[OK] copy constructor copies raw bits" << std::endl;
	}
	{
		Fixed a;
		Fixed b;
		a.setRawBits(1337);
		b = a;
		assert(b.getRawBits() == 1337);
		std::cout << "[OK] copy assignment operator copies raw bits" << std::endl;
	}
	{
		Fixed a;
		a.setRawBits(7);
		a = a;
		assert(a.getRawBits() == 7);
		std::cout << "[OK] self-assignment does not corrupt the value" << std::endl;
	}
	{
		Fixed a;
		Fixed const b;
		assert(b.getRawBits() == 0);
		(void)a;
		std::cout << "[OK] getRawBits works on const objects" << std::endl;
	}

	std::cout << std::endl << "All ex00 tests passed." << std::endl;
	return 0;
}
