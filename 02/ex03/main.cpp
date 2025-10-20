/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:05:22 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/20 16:26:07 by eala-lah         ###   ########.fr       */
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

	std::cout << "\n--- STARTING BSP TEST 1 (Inside) ---" << std::endl;
	bool result1 = bsp(a, b, c, p1);
	std::cout << "--- RESULT: p1 inside: " << (result1 ? "true" : "false") << " ---" << std::endl;

	std::cout << "\n--- STARTING BSP TEST 2 (Vertex) ---" << std::endl;
	bool result2 = bsp(a, b, c, p2);
	std::cout << "--- RESULT: p2 vertex: " << (result2 ? "true" : "false") << " ---" << std::endl;

	std::cout << "\n--- STARTING BSP TEST 3 (Edge) ---" << std::endl;
	bool result3 = bsp(a, b, c, p3);
	std::cout << "--- RESULT: p3 edge:   " << (result3 ? "true" : "false") << " ---" << std::endl;

	std::cout << "\n--- STARTING BSP TEST 4 (Outside) ---" << std::endl;
	bool result4 = bsp(a, b, c, p4);
	std::cout << "--- RESULT: p4 outside:" << (result4 ? "true" : "false") << " ---" << std::endl;

	std::cout << "\n--- END OF TESTS ---" << std::endl;
	return 0;
}
