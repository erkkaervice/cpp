/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:58:45 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/14 16:15:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = (n << _fractionalBits);
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

bool	Fixed::operator>(const Fixed& other) const { return (_value > other._value); }
bool	Fixed::operator<(const Fixed& other) const { return (_value < other._value); }
bool	Fixed::operator>=(const Fixed& other) const { return (_value >= other._value); }
bool	Fixed::operator<=(const Fixed& other) const { return (_value <= other._value); }
bool	Fixed::operator==(const Fixed& other) const { return (_value == other._value); }
bool	Fixed::operator!=(const Fixed& other) const { return (_value != other._value); }

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long	inter;
	inter = static_cast<long>(this->_value) * static_cast<long>(other._value);
	result._value = static_cast<int>(inter >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	inter;
	inter = (static_cast<long>(this->_value) << _fractionalBits) / static_cast<long>(other._value);
	result._value = static_cast<int>(inter);
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	this->_value += 1;
	return (old);
}

Fixed&	Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->_value -= 1;
	return (old);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return (out);
}
