/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:09 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/28 09:59:36 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "tests.hpp"

void test_map_iterators( void )
{
	std::cout << "==========================\n";
	std::cout << "=== test_map_iterators ===\n";
	std::cout << "==========================\n";
	{
		std::cout << "test_iterators\n";
		// std::map< char, int > m1;

		
	}
}

void test_insert( void )
{
	// map.insert() copies the values
	std::map< char, int > m;
	std::pair< const char, int > p('a', 1);
	
	m.insert(p);
	p.second = 2;
	std::cout << p.second << std::endl;
	std::cout << (m['a']) << std::endl;
}

int main( void )
{
	std::map< char, int > m;

	m.insert(std::pair< char, int >('a', 1));
	m.insert(std::pair< char, int >('b', 2));
	m.insert(std::pair< char, int >('c', 3));
	m.insert(std::pair< char, int >('z', 26));
	std::map< char, int > n;
	n.insert(std::pair< char, int >('d', 4));
	m.insert(std::pair< char, int >('d', 4));

	// std::map< char, int >::iterator j = ++m.begin();
	std::map< char, int >::iterator i;
	// std::map< char, int >::reverse_iterator r = m.rbegin();
	for (i = m.begin(); i != m.end(); ++i)
	{
		std::cout << (&*i) << ": " << i->first << ", " << (*i).second << std::endl;
		i->second += 1;
		std::cout << (&*i) << ": " << i->first << ", " << (*i).second << std::endl;
		break;
	}
	// data is not contiguous in memory, it is not sorted in memory neither.
	test_insert();
	test_constructor();
	test_map_access();
	test_map_iterators();
}
