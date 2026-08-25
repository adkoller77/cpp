#include "Fixed.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

static bool close(float a, float b, float epsilon)
{
	return std::fabs(a - b) < epsilon;
}

int	main(void)
{
	std::cout << "=== ex02 tests ===" << std::endl << std::endl;

	{
		Fixed a(2.0f);
		Fixed b(3.0f);
		assert(a < b);
		assert(b > a);
		assert(a <= b);
		assert(b >= a);
		assert(a != b);
		Fixed c(2.0f);
		assert(a == c);
		std::cout << "[OK] comparison operators work" << std::endl;
	}
	{
		Fixed a(2.5f);
		Fixed b(1.5f);
		assert(close((a + b).toFloat(), 4.0f, 0.01f));
		assert(close((a - b).toFloat(), 1.0f, 0.01f));
		assert(close((a * b).toFloat(), 3.75f, 0.01f));
		assert(close((a / b).toFloat(), 1.6666f, 0.01f));
		std::cout << "[OK] arithmetic operators (+ - * /) work" << std::endl;
	}
	{
		Fixed a(5.05f);
		Fixed b(2);
		Fixed c = a * b;
		assert(close(c.toFloat(), 10.1016f, 0.001f));
		std::cout << "[OK] Fixed(5.05f) * Fixed(2) matches subject example" << std::endl;
	}
	{
		Fixed a;
		Fixed pre = ++a;
		assert(pre.getRawBits() == 1);
		assert(a.getRawBits() == 1);
		std::cout << "[OK] pre-increment adds epsilon and returns updated value" << std::endl;
	}
	{
		Fixed a;
		Fixed post = a++;
		assert(post.getRawBits() == 0);
		assert(a.getRawBits() == 1);
		std::cout << "[OK] post-increment returns old value, updates raw value" << std::endl;
	}
	{
		Fixed a(1);
		Fixed pre = --a;
		assert(pre.getRawBits() == a.getRawBits());
		assert(a.getRawBits() == 255);
		std::cout << "[OK] pre-decrement subtracts epsilon" << std::endl;
	}
	{
		Fixed a(1);
		Fixed post = a--;
		assert(post.getRawBits() == 256);
		assert(a.getRawBits() == 255);
		std::cout << "[OK] post-decrement returns old value, updates raw value" << std::endl;
	}
	{
		Fixed a(2.0f);
		Fixed b(5.0f);
		assert(&Fixed::min(a, b) == &a);
		assert(&Fixed::max(a, b) == &b);
		Fixed const ca(2.0f);
		Fixed const cb(5.0f);
		assert(&Fixed::min(ca, cb) == &ca);
		assert(&Fixed::max(ca, cb) == &cb);
		std::cout << "[OK] static min/max (const and non-const) return correct references" << std::endl;
	}

	std::cout << std::endl << "All ex02 tests passed." << std::endl;
	return 0;
}
