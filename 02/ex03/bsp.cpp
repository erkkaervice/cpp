/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:06:17 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/14 16:26:07 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	sign(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	ax = a.getX().toFloat();
	float	ay = a.getY().toFloat();
	float	bx = b.getX().toFloat();
	float	by = b.getY().toFloat();
	float	cx = c.getX().toFloat();
	float	cy = c.getY().toFloat();
	float	px = point.getX().toFloat();
	float	py = point.getY().toFloat();

	float	d1 = sign(px, py, ax, ay, bx, by);
	float	d2 = sign(px, py, bx, by, cx, cy);
	float	d3 = sign(px, py, cx, cy, ax, ay);

	if (d1 == 0.0f || d2 == 0.0f || d3 == 0.0f)
		return (false);

	bool	hasNeg = (d1 < 0.0f) || (d2 < 0.0f) || (d3 < 0.0f);
	bool	hasPos = (d1 > 0.0f) || (d2 > 0.0f) || (d3 > 0.0f);

	return (!(hasNeg && hasPos));
}
