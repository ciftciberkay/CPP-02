#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed& Fixed::operator=(const Fixed& righthand)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &righthand)
        this->_fixedPointValue = righthand.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const set)
{
    this->_fixedPointValue = set;
}