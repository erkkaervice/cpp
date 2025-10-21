/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:07 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 14:07:55 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& other);
		~Point(void);

		Point&	operator=(const Point& other);

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

#endif
