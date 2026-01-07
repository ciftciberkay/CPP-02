#include "Fixed.hpp"

// Varsayılan constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Kopya constructor
Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    // Atama operatörünü çağırarak değerleri kopyalıyoruz
    *this = src;
}

// Kopya Atama Operatörü
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    // PDF çıktısında atama sırasında getRawBits çağrıldığı görülüyor
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Ham Bitleri Al
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Ham Bitleri Ayarla
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}