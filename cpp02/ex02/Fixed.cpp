#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractBits));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractBits);
}

int Fixed::toInt(void) const
{
	return _value / (1 << _fractBits);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return _value > rhs._value;
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return _value < rhs._value;
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return _value >= rhs._value;
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return _value <= rhs._value;
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return _value == rhs._value;
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return _value != rhs._value;
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed result;

	result.setRawBits(_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed result;
	long long product = static_cast<long long>(_value) * rhs._value;

	result.setRawBits(static_cast<int>(product >> _fractBits));
	return result;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed result;
	long long dividend = static_cast<long long>(_value) << _fractBits;

	result.setRawBits(static_cast<int>(dividend / rhs._value));
	return result;
}

Fixed &Fixed::operator++(void)
{
	++_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	++_value;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	--_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	--_value;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
