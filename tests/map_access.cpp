/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 05:04:54 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/28 06:02:45 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "tests.hpp"

void test_map_access( void )
{
	std::cout << "=======================\n";
	std::cout << "=== test_map_access ===\n";
	std::cout << "=======================\n";
	{
		std::cout << "test map::at()\n";
		std::map<char, int> m;
		m['a'] = 97;

		int& p = m.at('a');
		const std::map<char, int> m2(m);
		const int& q = m2.at('a');
		p = 98;
		std::cout << m['a'] << " " << q << std::endl;

		try
		{
			int& q = m.at('b');
			q = 42;
			std::cout << m['b'] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			const int& q = m2.at('b');
			std::cout << q << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "test ft::map::at()\n";
		ft::map<char, int> m;
		m['a'] = 97;

		int& p = m.at('a');
		const ft::map<char, int> m2(m);
		const int& q = m2.at('a');
		p = 98;
		std::cout << m['a'] << " " << q << std::endl;

		try
		{
			int& q = m.at('b');
			q = 42;
			std::cout << q << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			const int& q = m2.at('b');
			std::cout << q << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "test map operator[]\n";
		std::map<char, int> m;
		m['a'] = 97;

		int& p = m['a'];
		p = 98;
		std::cout << m['a'] << std::endl;

		try
		{
			int& q = m['b'];
			std::cout << q << std::endl;
			q = 42;
			std::cout << q << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "test map operator[]\n";
		ft::map<char, int> m;
		m['a'] = 97;

		int& p = m['a'];
		p = 98;
		std::cout << m['a'] << std::endl;

		try
		{
			int& q = m['b'];
			std::cout << q << std::endl;
			q = 42;
			std::cout << q << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}