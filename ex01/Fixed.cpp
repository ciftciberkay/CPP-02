#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = x << _fractionalBits;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(x * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(const Fixed &righthand)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &righthand)
    {
        this->_fixedPointValue = righthand.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
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
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &i) 
{
    o << i.toFloat();
    return o;
}