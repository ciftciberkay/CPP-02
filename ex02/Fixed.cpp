#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const int x)
{
	this->_fixedPointValue = x << _fractionalBits;
}

Fixed::Fixed(const float x)
{
	this->_fixedPointValue = roundf(x * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed::~Fixed(){
}

Fixed &Fixed::operator=(const Fixed &righthand)
{
	if (this != &righthand)
		this->_fixedPointValue = righthand.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const set)
{
	this->_fixedPointValue = set;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &righthand) const
{
	return this->getRawBits() > righthand.getRawBits();
}

bool Fixed::operator<(const Fixed &righthand) const
{
	return this->getRawBits() < righthand.getRawBits();
}

bool Fixed::operator>=(const Fixed &righthand) const
{
	return this->getRawBits() >= righthand.getRawBits();
}

bool Fixed::operator<=(const Fixed &righthand) const
{
	return this->getRawBits() <= righthand.getRawBits();
}

bool Fixed::operator==(const Fixed &righthand) const
{
	return this->getRawBits() == righthand.getRawBits();
}

bool Fixed::operator!=(const Fixed &righthand) const
{
	return this->getRawBits() != righthand.getRawBits();
}

Fixed Fixed::operator+(const Fixed &righthand) const
{
	return Fixed(this->toFloat() + righthand.toFloat());
}

Fixed Fixed::operator-(const Fixed &righthand) const
{
	return Fixed(this->toFloat() - righthand.toFloat());
}

Fixed Fixed::operator*(const Fixed &righthand) const
{
	return Fixed(this->toFloat() * righthand.toFloat());
}

Fixed Fixed::operator/(const Fixed &righthand) const
{
	return Fixed(this->toFloat() / righthand.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}