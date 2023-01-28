/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:09 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/28 05:39:19 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "tests.hpp"

void test_map_iterators( void )
{
	std::cout << "test_iterators\n";
	// are all past-the-end iterators equal ?
	std::map< char, int > m1;
	std::map< char, int > m2;
	std::map< char, int > m3;
	std::map< char, int > m4;

	m1['a']; m1['b'];
	m2['c']; m2['d']; m2['e'];
	std::cout << (m1.end() == m2.end()) << std::endl;
	std::cout << (m3.end() == m4.end()) << std::endl;
	std::map<char, int>::iterator it = m3.begin();
	std::pair<const char, int> a = *(m3.end());
	std::cout << (int)a.first << a.second << std::endl;
	if (it->second)
		std::cout << "ok\n";
	else
		std::cout << "ko\n";
	m3['z'];
	--it;
	std::cout << it->first << std::endl;
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
