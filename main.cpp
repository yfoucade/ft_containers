/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:02:52 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/08 00:41:05 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <string>
#include <deque>
#ifdef STD //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
#endif

#include "tests.hpp"
#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void ft_main(int seed)
{
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}

void constructor_default(void)
{
	{
		std::cout << "Default constructor for ft::vector<int>" << std::endl;
		ft::vector<int> v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Default constructor for ft::vector<char>" << std::endl;
		ft::vector<char> v2;

		std::cout << "v2.empty() = " << v2.empty() << std::endl;
		std::cout << "v2.size() = " << v2.size() << std::endl;
		std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
		std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
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
		std::cout << "Alloc constructor ft::vector<int>(std::allocator<char>)\n";
		std::allocator<int> alloc;
		// allocate the correct number of
		// allocator::size_type to store `count` instances of T.
		ft::vector<int, std::allocator<char> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
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
		std::cout << "Alloc constructor ft::vector< char, std::allocator<int> >(std::allocator<int>)\n";
		std::allocator<int> alloc;
		ft::vector<char, std::allocator<int> > v1(alloc);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
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
		std::cout << "Constructor count_value ft::vector<int>(0, 42)\n";
		ft::vector<int, std::allocator<char> > v1(0, 42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
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
		std::cout << "Iterator constructor ft::vector<int>(tab_int, tab_int+4)\n";
		ft::vector<int, std::allocator<char> > v1(tab_int, tab_int+4);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
		// v1.push_back(42);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << v1[0] << " " << std::endl;
		std::cout << sizeof(v1.data()[0]) << std::endl;
		std::cout << std::endl;
	}
	{
		ft::vector<int> tab_vec[] = {ft::vector<int>(), ft::vector<int>()};
		std::cout << "Iterator constructor ft::vector<ft::vector<int> >(tab_vec, tab_vec+2)\n";
		ft::vector<ft::vector<int>, std::allocator<char> > v1(tab_vec, tab_vec+2);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
		v1.push_back(ft::vector<int>());
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
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
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		// should double capacity;
		// v1.push_back(c);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;
	}
}

void constructor_copy( void )
{
	{
		std::cout << "Copy constructor ft::vector<char>(4, 'c')\n";
		ft::vector< char > v_tmp(4, 'c');
		ft::vector< char > v1(v_tmp);
		std::cout << "v1.empty() = " << v1.empty() << std::endl;
		std::cout << "v1.size() = " << v1.size() << std::endl;
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
}

void	test_assignment_operator( void )
{
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
		// print_content(v1[3]); // weird output
		// Answer: elements are destroyed.
		std::cout << std::endl;
	}
}

void	test_assign_iterator( void )
{
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
	// test_assign_count_value();
	test_assign_iterator();
}

void	test_at( void )
{
	{
		std::cout << "test at() [ft]\n";
		ft::vector<int> v1(5, 42);

		std::cout << "int &p1 = v1.at(3);\n";
		int &p1 = v1.at(3);
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);
		
		try{
			int &p3 = v1.at(1024);
			std::cout << "p3 = " << p3 << std::endl;
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}

void	test_brackets_operator( void )
{
	{
		std::cout << "test [] [ft]\n";
		ft::vector<int> v1(5, 42);

		std::cout << "int &p1 = v1.[3];\n";
		int &p1 = v1[3];
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);

		std::cout << std::endl;
	}
}

void	test_front( void )
{
	{
		std::cout << "test front() [ft]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		ft::vector< int > v1(5, 42);
		
		std::cout << "int &p1 = v1.front();\n";
		int &p1 = v1.front();
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_back( void )
{
	{
		std::cout << "test back() [ft]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		ft::vector< int > v1(5, 42);
		
		std::cout << "int &p1 = v1.back();\n";
		int &p1 = v1.back();
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_data( void )
{
	{
		std::cout << "test data() [ft]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		ft::vector< int > v1(5, 42);
		
		std::cout << "int *p1 = v1.data();\n";
		int *p1 = v1.data();
		std::cout << "*p1 = " << *p1 << std::endl;
		std::cout << "*p1 = 21;\n";
		*p1 = 21;
		std::cout << "*p1 = " << *p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_access( void )
{
	test_at();
	test_brackets_operator();
	test_front();
	test_back();
	test_data();
	ft::vector< int > v1;
	for (int i = 0; i < 5; i++)
		v1.push_back(i);
	test_const_access(v1);
}

void	test_iterator( ft::vector< int >& v )
{
	std::cout << "test iterator\n";
	ft::vector< int >::iterator first = v.begin();
	ft::vector< int >::iterator last = v.end();

	while (first != last)
		std::cout << *first++ << " ";
	std::cout << std::endl;
}

void	test_const_iterator( const ft::vector< int >& v )
{
	std::cout << "test const_iterator\n";
	ft::vector< int >::const_iterator first = v.begin();
	ft::vector< int >::const_iterator last = v.end();

	while (first != last)
	{
		// *first = 42;
		std::cout << *first++ << " ";
	}
	std::cout << std::endl;
}

void	test_reverse_iterator( ft::vector< int >& v )
{
	std::cout << "test reverse_iterator\n";
	ft::vector< int >::reverse_iterator first = v.rbegin();
	ft::vector< int >::reverse_iterator last = v.rend();

	while (first != last)
		std::cout << *first++ << " ";
	std::cout << std::endl;
}

void	test_const_reverse_iterator( const ft::vector< int >& v )
{
	std::cout << "test const_reverse_iterator\n";
	ft::vector< int >::const_reverse_iterator first = v.rbegin();
	ft::vector< int >::const_reverse_iterator last = v.rend();

	while (first != last)
	{
		// *first = 5;
		std::cout << *first++ << " ";
	}
	std::cout << std::endl;
}

ft::vector< int > range_vector(int min, int max)
{
	ft::vector< int > res;
	while (min < max)
		res.push_back(min++);
	return res;
}

void	test_iterators( void )
{
	ft::vector< int > v1 = range_vector(0, 5);
	test_iterator(v1);
	test_const_iterator(v1);
	test_reverse_iterator(v1);
	test_const_reverse_iterator(v1);
}

void	test_empty( void )
{
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

void	test_clear( void )
{
	{
		std::cout << "test clear() [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(42);
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "test clear() [ft]\n";
		
		std::cout << "ft::vector< ft::vector< char > > v1(5, ft::vector< char >(4, '*'));\n";
		ft::vector< ft::vector< char > > v1(5, ft::vector< char >(4, '*'));
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		
		std::cout << "v1.push_back(42);\n";
		v1.push_back(ft::vector< char >(1, ' '));
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << "\nv1.clear()\n";
		v1.clear();
		std::cout << "v1.size() = " << v1.size() << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;
	}
}

void	test_insert( void )
{
	{
		std::cout << "test insert(pos, value) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		v1.insert(v1.begin(), 42);
		print_content(v1);
		v1.insert(v1.begin(), 41);
		print_content(v1);
		v1.insert(v1.begin() + 1, 1729);
		print_content(v1);
		v1.insert(v1.end(), 101);
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "test insert(pos, count, value) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		v1.insert(v1.begin(), 3, 42);
		print_content(v1);
		v1.insert(v1.begin(), 1, 41);
		print_content(v1);
		v1.insert(v1.begin() + 1, 2, 1729);
		print_content(v1);
		v1.insert(v1.end(), 0, 101);
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "test insert(pos, first, last) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		v1.insert(v1.begin(), tab, tab + 2);
		print_content(v1);
		v1.insert(v1.begin(), tab + 1, tab + 7);
		print_content(v1);
		v1.insert(
			v1.begin() + 1,
			ft::reverse_iterator<int *>(tab+5),
			ft::reverse_iterator<int *>(tab));
		print_content(v1);
		v1.insert(v1.end(), tab, tab + 1);
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "test insert(pos, value) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< ft::vector< int > > v1;
		v1.insert(v1.begin(), ft::vector< int >(42));
		v1.insert(v1.begin(), ft::vector< int >(41));
		v1.insert(v1.begin() + 1, ft::vector< int >(1729));
		v1.insert(v1.end(), ft::vector< int >(101));
		std::cout << std::endl;
	}
}

void	test_erase( void )
{
	{
		std::cout << "test erase(pos) [ft]\n";
		int tab[] = {0, 1, 2, 3, 4};
		ft::vector< int > v1(tab, tab + 5);
		print_content(v1);
		v1.erase(v1.begin());
		print_content(v1);
		v1.erase(v1.begin() + 1);
		print_content(v1);
		v1.erase(v1.end() - 1);
		print_content(v1);
		v1.erase(v1.begin());
		print_content(v1);
		v1.erase(v1.begin());
		print_content(v1);
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		v1.insert(v1.begin(), tab, tab + 5);
		typename ft::vector< int >::iterator it = v1.erase(v1.begin() + 2, v1.end());
		if ( it == v1.end())
			std::cout << "Success\n";
		std::cout << std::endl;
	}
	{
		std::cout << "does erase() call the destructors of the deleted elements? [ft]\n";
		ft::vector< ft::vector< int > > v1;
		v1.push_back( ft::vector< int >(2, 42) );
		typename ft::vector< ft::vector< int > >::iterator it = v1.begin();
		std::cout << "(*it)[0] = " << (*it)[0] << std::endl;
		v1.erase(it);
		// std::cout << "(*it)[0] = " << (*it)[0] << std::endl;
		std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
		std::cout << std::endl;
	}
}

void	test_erase_2( void )
{
	{
		int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		ft::vector<int> c(tab, tab + 10);
		print_content(c);
	
		c.erase(c.begin());
		print_content(c);
	
		c.erase(c.begin()+2, c.begin()+5);
		print_content(c);
	
		// Erase all even numbers
		for (ft::vector<int>::iterator it = c.begin(); it != c.end();)
		{
			if (*it % 2 == 0)
				it = c.erase(it);
			else
				++it;
		}
		print_content(c);
		std::cout << std::endl;
	}
}

void	test_push_back( void )
{
	{
		std::cout << "test push_back() [ft]\n";
		ft::vector< int > v1;
		v1.push_back(42);
		print_content(v1);
		v1.push_back(21);
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_pop_back( void )
{
	{
		std::cout << "test pop_back() [ft]\n";
		ft::vector< int > v1(3, 42);
		v1.pop_back();
		print_content(v1);
		v1.pop_back();
		print_content(v1);
		v1.pop_back();
		print_content(v1);
		// v1.pop_back();
		// print_content(v1);
		std::cout << std::endl;
	}
}

void	test_resize( void )
{
	{
		std::cout << "test resize(count, value) [ft]\n";
		ft::vector< int > v1(5, 42);
		v1.resize(7, 21);
		print_content(v1);
		v1.resize(2, 0);
		print_content(v1);
		v1.resize(0, 0);
		print_content(v1);
		std::cout << std::endl;
	}
}

void	test_swap( void )
{
	{
		std::cout << "test swap(other) [ft]\n";
		ft::vector< int > v1(5, 42);
		ft::vector< int > v2(2, 21);
		v1.swap(v2);
		print_content(v1);
		print_content(v2);
		std::cout << std::endl;
	}
}

void	test_modifiers( void )
{
	test_clear();
	test_insert();
	test_erase();
	test_erase_2();
	test_push_back();
	test_pop_back();
	test_resize();
	test_swap();
}

void	test_eq( void )
{
	{
		std::cout << "test equal [ft]\n";
		ft::vector< int > v1(5, 42);
		ft::vector< int > v2(5, 42);
		std::cout << (v1 == v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 == v2) << std::endl;
		std::cout << std::endl;
	}
}

void	test_neq( void )
{
	{
		std::cout << "test not equal [ft]\n";
		ft::vector< int > v1(5, 42);
		ft::vector< int > v2(5, 42);
		std::cout << (v1 != v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 != v2) << std::endl;
		std::cout << std::endl;
	}
}

void	test_lt( void )
{
	{
		std::cout << "test less than [ft]\n";
		ft::vector< int > v1(5, 42);
		ft::vector< int > v2(5, 42);
		std::cout << (v1 < v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 < v2) << std::endl;
		std::cout << std::endl;
	}
}

void	test_non_member_swap( void )
{
	std::cout << "test swap(lhs, rhs) [ft]\n";
	ft::vector< int > v1(5, 42);
	ft::vector< int > v2(3, 21);
	ft::swap(v1, v2);
	print_content(v1);
	print_content(v2);
	std::cout << std::endl;
}

void	test_comparisons( void )
{
	{
		std::cout << "test comparisons\n";
		int tab[] = {1, 2, 3, 7, 8, 9, 10};
		ft::vector<int> alice(tab, tab + 3);
		ft::vector<int> bob(tab + 3, tab + 6);
		ft::vector<int> eve(tab, tab + 3);

		std::cout << std::boolalpha;

		// Compare non equal containers
		std::cout << "alice == bob returns " << (alice == bob) << '\n';
		std::cout << "alice != bob returns " << (alice != bob) << '\n';
		std::cout << "alice <  bob returns " << (alice < bob) << '\n';
		std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
		std::cout << "alice >  bob returns " << (alice > bob) << '\n';
		std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

		std::cout << '\n';

		// Compare equal containers
		std::cout << "alice == eve returns " << (alice == eve) << '\n';
		std::cout << "alice != eve returns " << (alice != eve) << '\n';
		std::cout << "alice <  eve returns " << (alice < eve) << '\n';
		std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
		std::cout << "alice >  eve returns " << (alice > eve) << '\n';
		std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
		std::cout << std::endl;
	}
}

void	test_non_member( void )
{
	test_eq();
	test_neq();
	test_lt();
	test_non_member_swap();
	test_comparisons();
}

void test_map_iterators( void )
{
	std::cout << "==========================\n";
	std::cout << "=== test_map_iterators ===\n";
	std::cout << "==========================\n";
	{
		std::cout << "test iterators\n";
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
		std::cout << "test const_iterators\n";
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
		std::cout << "test reverse_iterators\n";
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
		std::cout << "test const_reverse_iterators\n";
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

void test_map_capacity( void )
{
	std::cout << "=========================\n";
	std::cout << "=== test_map_capacity ===\n";
	std::cout << "=========================\n";
	{
		std::cout << "test empty\n";
		ft::map<char, int> m1;
		ft::map<char, int> m2;
		m2.insert(ft::pair<char, int>('a', 97));

		std::cout << m1.empty() << std::endl;
		std::cout << m2.empty() << std::endl;
		m2.erase('a');
		std::cout << m2.empty() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "test size\n";
		ft::map<char, int> m1;
		ft::map<char, int> m2;
		m2.insert(ft::pair<char, int>('a', 97));
		m2.insert(ft::pair<char, int>('b', 98));
		m2.insert(ft::pair<char, int>('c', 99));

		std::cout << m1.size() << std::endl;

		ft::map<char, int>::iterator it = m2.begin();
		ft::map<char, int>::iterator end = m2.end();
		while (it != end)
			std::cout << it++->second << " ";
		std::cout << "\n";
		
		std::cout << m2.size() << std::endl;
		m2.erase('a');

		for (it = m2.begin(); it != end; ++it)
			std::cout << it++->second << " ";

		std::cout << m2.size() << std::endl;
		m2.clear();
		std::cout << m2.size() << std::endl;
		std::cout << std::endl;
	}
}

void test_map_modifiers( void )
{
	std::cout << "==========================\n";
	std::cout << "=== test_map_modifiers ===\n";
	std::cout << "==========================\n";
	{
		std::cout << "test clear() [ft]\n";
		// after clear, any past-the-end iterator remains valid
		ft::map<char, int> m1;
		m1.insert(ft::pair<char, int>('a', 97));
		m1.insert(ft::pair<char, int>('b', 98));
		ft::map<char, int>::iterator it = m1.begin();
		ft::map<char, int>::iterator end = m1.end();
		ft::map<char, int>::reverse_iterator rit = m1.rbegin();
		ft::map<char, int>::reverse_iterator rend = m1.rend();

		std::cout << m1.size() << std::endl;
		m1.clear();
		std::cout << m1.size() << std::endl;
		m1.insert(ft::pair<char, int>('c', 99));
		// check that past-the-end iterator is not invalidated
		for(it = m1.begin(); it != end; ++it)
			std::cout << it->second << " ";
		std::cout << "\n";
		// check for past-the-end reverse iterator
		// for(rit = m1.rbegin(); rit != rend; ++rit)
		for(rit = m1.rbegin(), rend=m1.rend(); rit != rend; ++rit)
			std::cout << rit->second << " ";
		std::cout << "\n";
		std::cout << (rend == m1.rend()) << std::endl;
	}
	{
		std::cout << "test insert(value) [ft]\n";
		ft::map<char, int> m1;

		m1.insert(ft::pair<char, int>('a', 98));
		for(ft::map<char, int>::iterator it=m1.begin(); it != m1.end(); ++it)
			std::cout << it->second << " ";
		std::cout << "\n";
		std::cout << m1.size() << "\n";
		m1.insert(ft::pair<char, int>('a', 98));
		for(ft::map<char, int>::iterator it=m1.begin(); it != m1.end(); ++it)
			std::cout << it->second << " ";
		std::cout << "\n";
		std::cout << m1.size() << "\n";
		m1.insert(ft::pair<char, int>('b', 99));
		for(ft::map<char, int>::iterator it=m1.begin(); it != m1.end(); ++it)
			std::cout << it->second << " ";
		std::cout << "\n";
		std::cout << m1.size() << "\n";
	}
	{
		
	}
}

void test_constructor( void )
{
	std::cout << "========================\n";
	std::cout << "=== test_constructor ===\n";
	std::cout << "========================\n";

	{
		std::cout << "constructor with Compare and Allocator\n";
		EvenFirst<char> comp;
		std::allocator<char> alloc;
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
	{
		std::cout << "assignment operator\n";
		ft::pair< const char, int > p[4] = {
			ft::pair< const char, int >('a', 97),
			ft::pair< const char, int >('*', 42),
			ft::pair< const char, int >(104, 104),
			ft::pair< const char, int >('A', 65)
		};
		ft::map<char, int> m(p, p+4);
		ft::map<char, int> m2;
		m2 = m;
		ft::map< char, int >::iterator it = m2.begin();
		ft::map< char, int >::iterator end = m2.end();
		while ( it != end )
			std::cout << it++->second << std::endl;
	}
	// ft::map<char, int>::iterator it(m2.begin());
	// m2['a'] = 1;
	// --it;
	// std::cout << ((*it).second) << std::endl;
	{
		std::cout << "test destructor (nested maps)\n";
		ft::map< ft::map<char, int>, ft::map<char, int> > m;
		ft::map< char, int > empty;
		ft::map< char, int > m1;
		ft::map< char, int > m2;

		ft::pair<const char, int> p1('*', 42);
		ft::pair<const char, int> p2('a', 97);
		ft::pair<const char, int> p3('0', 47);

		m1.insert(p1);
		m2.insert(p2); m2.insert(p3);
		
		ft::pair< const ft::map<char, int>, ft::map<char, int> > mp1(empty, empty);
		ft::pair< const ft::map<char, int>, ft::map<char, int> > mp2(empty, m1);
		ft::pair< const ft::map<char, int>, ft::map<char, int> > mp3(m1, m2);
		ft::pair< const ft::map<char, int>, ft::map<char, int> > mp4(m2, m1);

		m.insert(mp1); m.insert(mp2); m.insert(mp3); m.insert(mp4);
	}
}

void test_map_access( void )
{
	std::cout << "=======================\n";
	std::cout << "=== test_map_access ===\n";
	std::cout << "=======================\n";
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

void test_stack( void )
{
	ft::stack<int> s1;
	ft::stack<int> s2;

	std::cout << s1.empty() << ", " << s1.size() << std::endl;
	s1.push(42);
	std::cout << s1.empty() << ", " << s1.size() << std::endl;
	s2 = s1;
	ft::stack<int> s3(s2);
	s3.pop();
	std::cout << s3.empty() << ", " << s3.size() << std::endl;
	std::cout << (s1 == s2) << ", " << (s1 == s3) << std::endl;
	swap(s2, s3);
	std::cout << (s1 == s2) << ", " << (s1 == s3) << std::endl;
}

void test_set( void )
{
	ft::set<char> s1;
	ft::set<char> s2;
	char ascii_lowercase[] = "abcdefghijklmnopqrstuvwxyz";
	
	s1.insert('a');
	s1.insert(ascii_lowercase, ascii_lowercase+26);
	print_content(s1);
}

void test_map( void )
{
	test_insert();
	test_constructor();
	test_map_access();
	test_map_iterators();
	test_map_capacity();
	test_map_modifiers();
}

void test_vector(void){
	test_constructors();
	test_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_non_member();
}

int main(int argc, char** argv)
{
	std::time_t tic, toc;
	(void)argv;

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	{
		std::cout << "====================\n";
		std::cout << "===   FT_TESTS   ===\n";
		std::cout << "====================\n";
		time(&tic);
		ft_main(atoi(argv[1]));
		time(&toc);
		std::cout << "\nFT_TESTS: end\n";
		std::cout << "ft_tests time: " << std::difftime(toc, tic) << std::endl;
	}
	{
		std::cout << "===================\n";
		std::cout << "===   VECTOR   ===\n";
		std::cout << "===================\n";
		time(&tic);
		test_vector();
		time(&toc);
		std::cout << "\nVECTOR: end\n";
		std::cout << "vector time: " << std::difftime(toc, tic) << "\n\n";
	}
	{
		std::cout << "==================\n";
		std::cout << "===    MAP    ===\n";
		std::cout << "==================\n";
		time(&tic);
		test_map();
		time(&toc);
		std::cout << "\nMAP: end\n";
		std::cout << "map time: " << std::difftime(toc, tic) << "\n\n";
	}
	{
		std::cout << "=================\n";
		std::cout << "===   STACK   ===\n";
		std::cout << "=================\n";
		time(&tic);
		test_stack();
		time(&toc);
		std::cout << "\nSTACK: end\n";
		std::cout << "stack time: " << std::difftime(toc, tic) << "\n\n";
	}
	{
		std::cout << "=================\n";
		std::cout << "===    SET    ===\n";
		std::cout << "=================\n";
		time(&tic);
		test_set();
		time(&toc);
		std::cout << "\nSET: end\n";
		std::cout << "set time: " << std::difftime(toc, tic) << "\n\n";
	}
	return (0);
}
