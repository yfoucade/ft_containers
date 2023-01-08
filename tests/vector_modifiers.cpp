/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:29:30 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/08 01:29:22 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_clear( void )
{
	{
		std::cout << "test clear() [std]\n";
		
		std::cout << "std::vector< int > v1;\n";
		std::vector< int > v1;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "test clear() [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "test clear() [ft]\n";
		
		std::cout << "ft::vector< ft::vector< char > > v1(5, ft::vector< char >(4, '*'));\n";
		ft::vector< ft::vector< char > > v1(5, ft::vector< char >(4, '*'));
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(ft::vector< char >(1, ' '));
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << std::hex << v1.data() << std::dec << std::endl;
		std::cout << std::endl;
	}
}

void	test_insert( void )
{
	
}

void	test_erase( void )
{
	
}

void	test_push_back( void )
{
	
}

void	test_pop_back( void )
{
	
}

void	test_resize( void )
{
	
}

void	test_swap( void )
{
	
}


void	test_modifiers( void )
{
	test_clear();
	test_insert();
	test_erase();
	test_push_back();
	test_pop_back();
	test_resize();
	test_swap();
}