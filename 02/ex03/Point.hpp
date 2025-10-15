/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:07 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/14 16:22:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& other);
		~Point(void);

		Point&	operator=(Point const& other);

		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;
};

#endif
