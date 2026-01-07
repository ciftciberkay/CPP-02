#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Ortodoks Kanonik Form Elemanları
    Fixed();                                // Varsayılan Constructor
    Fixed(const Fixed& src);                // Kopya Constructor
    Fixed& operator = (const Fixed& rhs);   // Kopya Atama Operatörü
    ~Fixed();                               // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif