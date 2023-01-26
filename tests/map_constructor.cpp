/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:18:18 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/26 23:27:47 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include "tests.hpp"

void test_constructor( void )
{
	std::cout << "========================\n";
	std::cout << "=== test_constructor ===\n";
	std::cout << "========================\n";

	{
		std::cout << "empty constructor\n";
		std::cout << "std::map<char, int> m1;\n";
		std::map<char, int> m1;
		std::cout << "ft::map<char, int> m2;\n";
		ft::map<char, int> m2;
		std::cout << "std::map< std::map<char, int>, std::vector<int> > m3;\n";
		std::map< std::map<char, int>, std::vector<int> > m3;
		std::cout << "ft::map<ft::map<char, int>, ft::vector<int>> m4;\n";
		ft::map< ft::map<char, int>, ft::vector<int> > m4;
	}

	{
		std::cout << "constructor with Compare and Allocator\n";
		EvenFirst<char> comp;
		std::allocator<char> alloc;
		std::map<char, int, EvenFirst<char>, std::allocator<char> > m1(comp, alloc);
		ft::map<char, int, EvenFirst<char>, std::allocator<char> > m2(comp, alloc);
		std::pair< const char, int > p1('a', 1);
		ft::pair< const char, int > p2(42, 42);
		// create several pairs
		// add them all,
		// test the order by printing all elements
		
		m1.insert(p1);
		m2.insert(p2);
	}

	// ft::map<char, int>::iterator it(m2.begin());
	// m2['a'] = 1;
	// --it;
	// std::cout << ((*it).second) << std::endl;
}