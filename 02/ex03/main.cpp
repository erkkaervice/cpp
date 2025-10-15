/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:05:22 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/14 16:23:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(0.0f, 10.0f);

	Point	p1(2.0f, 2.0f);
	Point	p2(0.0f, 0.0f);
	Point	p3(5.0f, 0.0f);
	Point	p4(10.0f, 10.0f);

	std::cout << "p1 inside: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	std::cout << "p2 vertex: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	std::cout << "p3 edge:   " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
	std::cout << "p4 outside:" << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;

	return (0);
}
