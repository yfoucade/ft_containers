/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:29:30 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/09 17:27:43 by yfoucade         ###   ########.fr       */
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
	{
		std::cout << "test insert(pos, value) [std]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		std::vector< int > v1;
		std::cout << "v1.data() = " << v1.data() << std::endl;
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
		std::cout << "test insert(pos, value) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		std::cout << "v1.data() = " << v1.data() << std::endl;
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
		std::cout << "test insert(pos, count, value) [std]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		std::vector< int > v1;
		std::cout << "v1.data() = " << v1.data() << std::endl;
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
		std::cout << "test insert(pos, count, value) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		std::cout << "v1.data() = " << v1.data() << std::endl;
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
		std::cout << "test insert(pos, first, last) [std]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		std::vector< int > v1;
		int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << "v1.data() = " << v1.data() << std::endl;
		v1.insert(v1.begin(), tab, tab + 2);
		print_content(v1);
		v1.insert(v1.begin(), tab + 1, tab + 7);
		print_content(v1);
		v1.insert(
			v1.begin() + 1,
			std::reverse_iterator<int *>(tab+5),
			std::reverse_iterator<int *>(tab));
		print_content(v1);
		v1.insert(v1.end(), tab, tab + 1);
		print_content(v1);
		std::cout << std::endl;
	}
	{
		std::cout << "test insert(pos, first, last) [ft]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		ft::vector< int > v1;
		int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << "v1.data() = " << v1.data() << std::endl;
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
		std::cout << "test insert(pos, value) [std]\n";
		
		std::cout << "ft::vector< int > v1;\n";
		std::vector< std::vector< int > > v1;
		v1.insert(v1.begin(), std::vector< int >(42));
		v1.insert(v1.begin(), std::vector< int >(41));
		v1.insert(v1.begin() + 1, std::vector< int >(1729));
		v1.insert(v1.end(), std::vector< int >(101));
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
		std::cout << "test erase(pos) [std]\n";
		int tab[] = {0, 1, 2, 3, 4};
		std::vector< int > v1(tab, tab + 5);
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
		std::cout << std::endl;
	}
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
		std::cout << "test push_back() [std]\n";
		std::vector< int > v1;
		v1.push_back(42);
		print_content(v1);
		v1.push_back(21);
		print_content(v1);
		std::cout << std::endl;
	}
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
	test_erase_2();
	test_push_back();
	test_pop_back();
	test_resize();
	test_swap();
}