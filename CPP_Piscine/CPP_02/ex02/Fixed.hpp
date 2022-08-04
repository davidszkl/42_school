#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
public:

	Fixed();
	Fixed(Fixed const & src);
	Fixed(const int nbr_int);
	Fixed(const float nbr_float);
	~Fixed();

	Fixed&	operator=(Fixed const & rhs);

	bool	operator<(Fixed const & rhs);
	bool	operator>(Fixed const & rhs);
	bool	operator>=(Fixed const & rhs);
	bool	operator<=(Fixed const & rhs);
	bool	operator==(Fixed const & rhs);
	bool	operator!=(Fixed const & rhs);

	Fixed	operator+(Fixed const & rhs);
	Fixed	operator-(Fixed const & rhs);
	Fixed	operator*(Fixed const & rhs);
	Fixed	operator/(Fixed const & rhs);

	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed&		min(Fixed &fixed1, Fixed &fixed2);
	static Fixed&		max(Fixed &fixed1, Fixed &fixed2);
	const static Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	const static Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

	float	toFloat()	const;
	int		toInt()		const;
	
	int		getRawBits() const;
	void	setRawBits(int const raw);

private:

	int	_RawBits;
	const static int _FractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &stream, Fixed const & fixed);

#endif