/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:20:17 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/07 17:43:32 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

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
		// std::cout << "v2.data() = " << v2.data() << std::endl;
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
	}
	{
		std::cout << "Default constructor for ft::vector<char>" << std::endl;
		ft::vector<char> v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		// std::cout << "v1.data() = " << v2.data() << std::endl;
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
		std::cout << "Alloc constructor std::vector< char, std::allocator<int> >(std::allocator<int>)\n";
		std::allocator<int> alloc;
		std::vector< char, std::allocator<int> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.push_back(42);
		v1.push_back(45);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Alloc constructor ft::vector< char, std::allocator<int> >(std::allocator<int>)\n";
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

void constructor_count_value( void )
{
	{
		std::cout << "Constructor count_value std::vector<int>(0, 42)\n";
		std::vector<int, std::allocator<char> > v1(0, 42);
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
		std::cout << "Constructor count_value ft::vector<int>(0, 42)\n";
		ft::vector<int, std::allocator<char> > v1(0, 42);
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
		std::cout << "Constructor count_value std::vector<int>(5, 42)\n";
		std::vector<int, std::allocator<char> > v1(5, 42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// push_back doubles the _capacity when vector is full.
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
		std::cout << "Constructor count_value ft::vector<int>(5, 42)\n";
		ft::vector<int, std::allocator<char> > v1(5, 42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
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

void constructor_iterator( void )
{
	int tab_int[] = {3, 14, 15, 92, 65};
	{
		std::cout << "Iterator constructor std::vector<int>(tab_int, tab_int+4)\n";
		std::vector<int, std::allocator<char> > v1(tab_int, tab_int+4);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// push_back doubles the _capacity when vector is full.
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
		std::cout << "Iterator constructor ft::vector<int>(tab_int, tab_int+4)\n";
		ft::vector<int, std::allocator<char> > v1(tab_int, tab_int+4);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
		// v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		std::vector<int> tab_vec[] = {std::vector<int>(), std::vector<int>()};
		std::cout << "Iterator constructor std::vector<std::vector<int>>(tab_int, tab_int+4)\n";
		std::vector<std::vector<int>, std::allocator<char> > v1(tab_vec, tab_vec+2);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// push_back doubles the _capacity when vector is full.
		v1.push_back(std::vector<int>());
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0].data() << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		ft::vector<int> tab_vec[] = {ft::vector<int>(), ft::vector<int>()};
		std::cout << "Iterator constructor ft::vector<ft::vector<int> >(tab_vec, tab_vec+2)\n";
		ft::vector<ft::vector<int>, std::allocator<char> > v1(tab_vec, tab_vec+2);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
		v1.push_back(ft::vector<int>());
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0].data() << " " << std::endl;
		std::cout << v1.data() << std::endl;
		std::cout << std::endl;
	}
	{
		std::vector<int> a(5, 21);
		std::vector<int> b(5, 42);
		std::vector<int> c;
		std::vector<int> tab_vec[] = {a, b};
		std::cout << "Iterator constructor std::vector<std::vector<int>>(tab_int, tab_int+4)\n";
		std::vector<std::vector<int>, std::allocator<char> > v1(tab_vec, tab_vec+2);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// push_back doubles the _capacity when vector is full.
		v1.push_back(c);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0].data() << " " << std::endl;
		std::cout << v1.data() << std::endl;
		std::cout << std::endl;
	}
	{
		ft::vector<int> a(5, 21);
		ft::vector<int> b(5, 42);
		ft::vector<int> c;
		ft::vector<int> tab_vec[] = {a, b};
		std::cout << "Iterator constructor ft::vector<ft::vector<int> >(tab_int, tab_int+4)\n";
		ft::vector<ft::vector<int>, std::allocator<char> > v1(tab_vec, tab_vec+2);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0].data() << " " << std::endl;
		std::cout << v1.data() << std::endl;
		// should double capacity;
		// v1.push_back(c);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0].data() << " " << std::endl;
		std::cout << v1.data() << std::endl;
		std::cout << std::endl;
	}
}

void constructor_copy( void )
{
	{
		std::cout << "Copy constructor std::vector<char>(4, 'c')\n";
		std::vector< char > v_tmp(4, 'c');
		std::vector< char > v1(v_tmp);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		print_content(v_tmp);
		print_content(v1);
		std::cout << "v_tmp.push_back('d')\n";
		std::cout << "push_back('e')\n";
		v_tmp.push_back('d');
		v1.push_back('e');
		print_content(v_tmp);
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "Copy constructor ft::vector<char>(4, 'c')\n";
		ft::vector< char > v_tmp(4, 'c');
		ft::vector< char > v1(v_tmp);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "v_tmp.data() " << std::hex << reinterpret_cast<std::size_t>(v_tmp.data()) << std::endl;
		std::cout << "v1.data() " << reinterpret_cast<std::size_t>(v1.data()) << std::dec << std::endl;
		print_content(v_tmp);
		print_content(v1);
		std::cout << "v_tmp.push_back('d')\n";
		std::cout << "push_back('e')\n";
		v_tmp.push_back('d');
		v1.push_back('e');
		print_content(v_tmp);
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_assignment_operator( void )
{
	{
		std::cout << "Assignment operator [std]\n";
		std::vector< char > v_tmp(4, 'c');
		std::vector< char > v1;

		print_content(v_tmp);
		print_content(v1);
		v1 = v_tmp;
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "Assignment operator [ft]\n";
		ft::vector< char > v_tmp(4, 'c');
		ft::vector< char > v1;

		print_content(v_tmp);
		print_content(v1);
		v1 = v_tmp;
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_assign_count_value( void )
{
	{
		// test whether a new storage is systematically allocated
		std::cout << "Assign member function [std]\n";
		std::vector< char > v1(5, 'c');
		v1.assign(3, 'd');
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		print_content(v1);
		std::cout << "v1[3] = " << v1[3] << std::endl;
		// answer: no!
		// If there is enough capacity, do not destroy and reallocate.
		// Question: Are destructors called ?
		std::cout << std::endl;
	}
	{
		// To answer the last question, we create a 2D vector and check wheter
		// the components of the main vector are destroyed.
		std::cout << "std::vector< std::vector<char> > v1(4, std::vector<char>(5, '*'))\n";
		std::vector< std::vector<char> > v1(4, std::vector<char>(5, '*'));
		print_content(v1[0]);
		v1.assign(3, std::vector<char>(5, 43));
		print_content(v1[2]);
		std::cout << std::endl;
		// print_content(v1[3]); // weird output
		// Answer: elements are destroyed.
	}
	{
		// test whether a new storage is systematically allocated
		std::cout << "Assign member function [ft]\n";
		ft::vector< char > v1(5, 'c');
		v1.assign(3, 'd');
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		print_content(v1);
		std::cout << "v1[3] = " << v1[3] << std::endl;
		// answer: no!
		// If there is enough capacity, do not destroy and reallocate.
		// Question: Are destructors called ?
		std::cout << std::endl;
	}
	{
		// To answer the last question, we create a 2D vector and check wheter
		// the components of the main vector are destroyed.
		std::cout << "std::vector< std::vector<char> > v1(4, std::vector<char>(5, '*'))\n";
		ft::vector< ft::vector<char> > v1(4, ft::vector<char>(5, '*'));
		print_content(v1[0]);
		v1.assign(3, ft::vector<char>(5, 43));
		print_content(v1[2]);
		// print_content(v1[3]); // we ird output
		// Answer: elements are destroyed.
		std::cout << std::endl;
	}
}

void	test_assign_iterator( void )
{
	{
		std::cout << "Assign(first, last) [std]\n";
		int	tab_int[5] = {1, 2, 3, 4, 5};
		std::cout << "std::vector< int > v1()\n";
		std::vector< int > v1;
		v1.assign(tab_int, tab_int + 4);
		print_content(v1);
	}
	{
		std::cout << "Assign(first, last) [ft]\n";
		int	tab_int[5] = {1, 2, 3, 4, 5};
		std::cout << "std::vector< int > v1()\n";
		ft::vector< int > v1;
		v1.assign(tab_int, tab_int + 4);
		print_content(v1);
	}
}

void	test_constructors( void )
{
	constructor_default();
	constructor_alloc();
	constructor_count_value();
	constructor_iterator();
	constructor_copy();
	test_assignment_operator();
	test_assign_count_value();
	test_assign_iterator();
}
