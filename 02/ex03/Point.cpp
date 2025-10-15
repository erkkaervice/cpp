/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:05:59 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/14 16:22:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const& other) : _x(other._x), _y(other._y) {}

Point::~Point(void) {}

Point&	Point::operator=(Point const& other)
{
	(void)other;
	return (*this);
}

Fixed const&	Point::getX(void) const
{
	return (_x);
}

Fixed const&	Point::getY(void) const
{
	return (_y);
}
