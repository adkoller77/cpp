#include "Fixed.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <sstream>

static bool close(float a, float b, float epsilon)
{
	return std::fabs(a - b) < epsilon;
}

int	main(void)
{
	std::cout << "=== ex01 tests ===" << std::endl << std::endl;

	{
		Fixed a;
		assert(a.toInt() == 0);
		assert(close(a.toFloat(), 0.0f, 0.001f));
		std::cout << "[OK] default constructor -> 0" << std::endl;
	}
	{
		Fixed a(42);
		assert(a.toInt() == 42);
		assert(close(a.toFloat(), 42.0f, 0.001f));
		std::cout << "[OK] int constructor converts correctly" << std::endl;
	}
	{
		Fixed a(-5);
		assert(a.toInt() == -5);
		std::cout << "[OK] int constructor handles negative values" << std::endl;
	}
	{
		Fixed a(42.42f);
		assert(a.toInt() == 42);
		assert(close(a.toFloat(), 42.42f, 0.01f));
		std::cout << "[OK] float constructor converts correctly" << std::endl;
	}
	{
		Fixed a(-13.75f);
		assert(close(a.toFloat(), -13.75f, 0.01f));
		std::cout << "[OK] float constructor handles negative values" << std::endl;
	}
	{
		Fixed a(1234.4321f);
		Fixed b(a);
		assert(close(b.toFloat(), 1234.4321f, 0.01f));
		assert(b.getRawBits() == a.getRawBits());
		std::cout << "[OK] copy constructor preserves converted value" << std::endl;
	}
	{
		Fixed a(3.5f);
		Fixed b;
		b = a;
		assert(close(b.toFloat(), 3.5f, 0.01f));
		std::cout << "[OK] copy assignment preserves converted value" << std::endl;
	}
	{
		Fixed a(7);
		std::ostringstream oss;
		oss << a;
		assert(oss.str() == "7");
		std::cout << "[OK] operator<< prints float representation" << std::endl;
	}

	std::cout << std::endl << "All ex01 tests passed." << std::endl;
	return 0;
}
