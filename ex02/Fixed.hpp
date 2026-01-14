#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int x);
		Fixed(const float x);
		Fixed(const Fixed &source);
		~Fixed();

		Fixed	&operator=(const Fixed &righthand);
		int		getRawBits(void) const;
		void	setRawBits(int const set);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed &righthand) const;
		bool	operator<(const Fixed &righthand) const;
		bool	operator>=(const Fixed &righthand) const;
		bool	operator<=(const Fixed &righthand) const;
		bool	operator==(const Fixed &righthand) const;
		bool	operator!=(const Fixed &righthand) const;
		Fixed	operator+(const Fixed &righthand) const;
		Fixed	operator-(const Fixed &righthand) const;
		Fixed	operator*(const Fixed &righthand) const;
		Fixed	operator/(const Fixed &righthand) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif