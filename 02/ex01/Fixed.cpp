/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:29:40 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 15:35:44 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return out;
}
