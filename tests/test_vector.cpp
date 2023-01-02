/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:39 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/02 16:52:56 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include "pair.hpp"

void constructor_default(void)
{
	{
		std::cout << "Default constructor for std::vector<int>" << std::endl;
		std::vector<int> v1;

		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v1.data() = " << v1.data() << std::endl;
		std::cout << std::endl;

		std::cout << "Default constructor for ft::vector<int>" << std::endl;
		ft::vector<int> v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << "v2.data() = " << v2.data() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Default constructor for std::vector<char>" << std::endl;
		std::vector<char> v1;

		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << "Default constructor for ft::vector<char>" << std::endl;
		ft::vector<char> v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Default constructor for std::vector< std::pair<int, int> >" << std::endl;
		std::vector< std::pair<int, int> > v1;

		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << "Default constructor for ft::vector< ft::pair<int, int> >" << std::endl;
		ft::vector< ft::pair<int, int> > v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << std::endl;
	}
}

void constructor_alloc( void )
{
	{
		std::cout << "Alloc constructor std::vector<int>(std::allocator<char>)\n";
		std::allocator<int> alloc;
		std::vector<int, std::allocator<char> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Alloc constructor ft::vector<int>(std::allocator<char>)\n";
		std::allocator<int> alloc;
		// allocate the correct number of
		// allocator::size_type to store `count` instances of T.
		ft::vector<int, std::allocator<char> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Alloc constructor std::vector<int>(std::allocator<char>)\n";
		std::allocator<int> alloc;
		std::vector<char, std::allocator<int> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Alloc constructor ft::vector<int>(std::allocator<char>)\n";
		std::allocator<int> alloc;
		ft::vector<char, std::allocator<int> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
}

void test_constructor(void){
	std::vector<int> v1;
	ft::vector<int> v2(5, 10);

	ft::vector<int>::iterator begin = v2.begin();
	ft::vector<int>::iterator end = v2.end();
	while (begin != end)
	{
		*begin = 42.024;
		std::cout << *begin++ << "\n";
	}
	
	ft::vector<float> v3(v2.begin(), v2.end());
	ft::vector<float>::iterator begin2 = v3.begin();
	ft::vector<float>::iterator end2 = v3.end();
	while (begin2 != end2)
	{
		*begin2 = 42.024;
		std::cout << *begin2++ << "\n";
	}
	ft::vector<int> v4 = v2;
	// v4 = v2;
	ft::vector<int>::iterator begin4 = v4.begin();
	ft::vector<int>::iterator end4 = v4.end();
	while (begin4 != end4)
	{
		*begin4 = 42.024;
		std::cout << *begin4++ << "\n";
	}
}

int main(void){
	constructor_default();
	constructor_alloc();
	// test_constructor();
}