/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:05:59 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 14:08:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point(void) {}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

const Fixed&	Point::getX(void) const
{
	return (_x);
}

const Fixed&	Point::getY(void) const
{
	return (_y);
}
