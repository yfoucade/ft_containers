/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:18:18 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/27 19:42:11 by yfoucade         ###   ########.fr       */
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
		{
			std::map< char, int, EvenFirst<char>, std::allocator<char> > m(comp, alloc);
			std::pair< const char, int > p1('a', 97);
			std::pair< const char, int > p2('*', 42);
			std::pair< const char, int > p3(104, 104);
			std::pair< const char, int > p4('A', 65);
			m.insert(p1); m.insert(p2); m.insert(p3); m.insert(p4);
			std::map< char, int, EvenFirst<char> >::iterator it = m.begin();
			std::map< char, int, EvenFirst<char> >::iterator end = m.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
		}
		{
			ft::map< char, int, EvenFirst<char>, std::allocator<char> > m(comp, alloc);
			ft::pair< const char, int > p1('a', 97);
			ft::pair< const char, int > p2('*', 42);
			ft::pair< const char, int > p3(104, 104);
			ft::pair< const char, int > p4('A', 65);
			m.insert(p1); m.insert(p2); m.insert(p3); m.insert(p4); m.insert(p1);
			ft::map< char, int, EvenFirst<char> >::iterator it = m.begin();
			ft::map< char, int, EvenFirst<char> >::iterator end = m.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
		}
	}
	{
		std::cout << "constructor with iterators\n";
		{
			std::pair< const char, int > p[4] = {
				std::pair< const char, int >('a', 97),
				std::pair< const char, int >('*', 42),
				std::pair< const char, int >(104, 104),
				std::pair< const char, int >('A', 65)
			};
			std::map<char, int> m(p, p+4);
			std::map< char, int >::iterator it = m.begin();
			std::map< char, int >::iterator end = m.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
		}
		{
			ft::pair< const char, int > p[4] = {
				ft::pair< const char, int >('a', 97),
				ft::pair< const char, int >('*', 42),
				ft::pair< const char, int >(104, 104),
				ft::pair< const char, int >('A', 65)
			};
			ft::map<char, int> m(p, p+4);
			ft::map< char, int >::iterator it = m.begin();
			ft::map< char, int >::iterator end = m.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
		}
	}
	{
		std::cout << "copy constructor\n";
		{
			std::pair< const char, int > p[4] = {
				std::pair< const char, int >('a', 97),
				std::pair< const char, int >('*', 42),
				std::pair< const char, int >(104, 104),
				std::pair< const char, int >('A', 65)
			};
			std::map<char, int> m(p, p+4);
			std::map<char, int> m2(m);
			std::map< char, int >::iterator it = m2.begin();
			std::map< char, int >::iterator end = m2.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
			std::cout << (m == m2) << std::endl;
			m['a'] = 0;
			std::cout << (m < m2) << std::endl;
		}
		{
			ft::pair< const char, int > p[4] = {
				ft::pair< const char, int >('a', 97),
				ft::pair< const char, int >('*', 42),
				ft::pair< const char, int >(104, 104),
				ft::pair< const char, int >('A', 65)
			};
			ft::map<char, int> m(p, p+4);
			ft::map<char, int> m2(m);
			ft::map< char, int >::iterator it = m2.begin();
			ft::map< char, int >::iterator end = m2.end();
			while ( it != end )
				std::cout << it++->second << std::endl;
			std::cout << (m == m2) << std::endl;
			m['a'] = 0;
			std::cout << (m < m2) << std::endl;
		}
	}
	// ft::map<char, int>::iterator it(m2.begin());
	// m2['a'] = 1;
	// --it;
	// std::cout << ((*it).second) << std::endl;
}