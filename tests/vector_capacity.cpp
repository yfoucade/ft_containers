/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:23:32 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/08 00:20:10 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_empty( void )
{
	{
		std::cout << "test empty [std]\n";
		
		std::cout << "std::vector< int > v1;\n";
		std::vector< int > v1;
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.pop_back();\n";
		v1.pop_back();
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.clear();\n";
		v1.clear();
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
	}
	{
		std::cout << "test empty [ft]\n";
		
		std::cout << "std::vector< int > v1;\n";
		ft::vector< int > v1;
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.pop_back();\n";
		v1.pop_back();
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;

		std::cout << "v1.clear();\n";
		v1.clear();
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
	}
	std::cout << std::endl;
}

void	test_reserve( void )
{
	{
		std::cout << "test reserve() [ft]\n";
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;

		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.reserve(2)\n";
		v1.reserve(2);
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		
		for (int i = 0; i < 3; ++i)
		{
			std::cout << "v1.push_back(" << i << ")\n";
			v1.push_back(i);
			std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		}

		std::cout << "v1.reserve(0)\n";
		v1.reserve(0);
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	}
}

void	test_capacity( void )
{
	test_empty();
	test_reserve();
}