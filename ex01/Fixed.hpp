#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &source);
    Fixed &operator=(const Fixed &righthand);
    ~Fixed();

    Fixed(const int x);
    Fixed(const float x);

    int     getRawBits(void) const;
    void    setRawBits(int const set);

    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif