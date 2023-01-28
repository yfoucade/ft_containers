/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:09 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/28 21:53:01 by yfoucade         ###   ########.fr       */
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
		ft::map<char, int> m0;
		ft::map<char, int> m1;
		ft::pair<char, int> a('a', 97);
		ft::pair<char, int> star('*', 42);
		ft::pair<char, int> zero('0', 47);
		
		m1.insert(a); m1.insert(star); m1.insert(zero);
		ft::map<char, int>::iterator it0 = m0.begin();
		std::cout << "m0.begin() == m0.end() ? " << (it0 == m0.end()) << std::endl;
		ft::map<char, int>::iterator it1 = m1.begin();
		std::cout << "m1.begin() == m1.end() ? " << (it1 == m1.end()) << std::endl;
		while (it1 != m1.end())
		{
			(*it1).second++;
			std::cout << it1->second++ << " " << it1->second << " ";
			++it1;
		}
		std::cout << std::endl;
	}
	{
		ft::pair<char, int> pair_list[3] = {
			ft::pair<char, int>('a', 97),
			ft::pair<char, int>('*', 42),
			ft::pair<char, int>('0', 47)
		};
		const ft::map<char, int> m0;
		const ft::map<char, int> m1(pair_list, pair_list+3);
		
		ft::map<char, int>::const_iterator it0 = m0.begin();
		std::cout << "m0.begin() == m0.end() ? " << (it0 == m0.end()) << std::endl;
		ft::map<char, int>::const_iterator it1 = m1.begin();
		std::cout << "m1.begin() == m1.end() ? " << (it1 == m1.end()) << std::endl;
		while (it1 != m1.end())
		{
			std::cout << it1->second << " ";
			++it1;
		}
		std::cout << std::endl;
	}
	// {
	// 	std::map<char, int> m0;
	// 	std::map<char, int> m1;
	// 	std::pair<char, int> a('a', 97);
	// 	std::pair<char, int> star('*', 42);
	// 	std::pair<char, int> zero('0', 47);
		
	// 	m1.insert(a); m1.insert(star); m1.insert(zero);
	// 	std::map<char, int>::reverse_iterator it0 = m0.rbegin();
	// 	std::cout << "m0.rbegin() == m0.rend() ? " << (it0 == m0.rend()) << std::endl;
	// 	std::map<char, int>::reverse_iterator it1 = m1.rbegin();
	// 	std::cout << "m1.rbegin() == m1.rend() ? " << (it1 == m1.rend()) << std::endl;
	// 	while (it1 != --m1.rend())
	// 	{
	// 		it1[1].second++;
	// 		std::cout << it1->second++ << " " << it1->second << " ";
	// 		++it1;
	// 	}
	// 	std::cout << std::endl;
	// }
	{
		ft::map<char, int> m0;
		ft::map<char, int> m1;
		ft::pair<char, int> a('a', 97);
		ft::pair<char, int> star('*', 42);
		ft::pair<char, int> zero('0', 47);
		
		m1.insert(a); m1.insert(star); m1.insert(zero);
		ft::map<char, int>::reverse_iterator it0 = m0.rbegin();
		std::cout << "m0.rbegin() == m0.rend() ? " << (it0 == m0.rend()) << std::endl;
		ft::map<char, int>::reverse_iterator it1 = m1.rbegin();
		std::cout << "m1.rbegin() == m1.rend() ? " << (it1 == m1.rend()) << std::endl;
		while (it1 != m1.rend())
		{
			(*it1).second++;
			std::cout << it1->second++ << " " << it1->second << " ";
			++it1;
		}
		std::cout << std::endl;
	}
	{
		ft::pair<char, int> pair_list[3] = {
			ft::pair<char, int>('a', 97),
			ft::pair<char, int>('*', 42),
			ft::pair<char, int>('0', 47)
		};
		const ft::map<char, int> m0;
		const ft::map<char, int> m1(pair_list, pair_list+3);
		
		ft::map<char, int>::const_reverse_iterator it0 = m0.rbegin();
		std::cout << "m0.rbegin() == m0.rend() ? " << (it0 == m0.rend()) << std::endl;
		ft::map<char, int>::const_reverse_iterator it1 = m1.rbegin();
		std::cout << "m1.rbegin() == m1.rend() ? " << (it1 == m1.rend()) << std::endl;
		while (it1 != m1.rend())
		{
			std::cout << it1->second << " ";
			++it1;
		}
		std::cout << std::endl;
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
