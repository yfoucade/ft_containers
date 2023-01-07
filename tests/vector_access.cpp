/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_access.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:06:12 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/07 22:10:10 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_at( void )
{
	{
		std::cout << "test at() [std]\n";
		std::vector<int> v1(5, 42);

		std::cout << "int &p1 = v1.at(3);\n";
		int &p1 = v1.at(3);
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);

		std::cout << "const int	&p2 = v1.at(3);\n";
		const int	&p2 = v1.at(3);
		std::cout << "p2 = " << p2 << std::endl;
		// std::cout << "p2 = 10;\n";
		// p2 = 10;

		try{
			int &p3 = v1.at(1024);
			std::cout << "p3 = " << p3 << std::endl;
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
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
		std::cout << "test [] [std]\n";
		std::vector<int> v1(5, 42);

		std::cout << "int &p1 = v1.[3];\n";
		int &p1 = v1[3];
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);

		std::cout << std::endl;
	}
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
		std::cout << "test data() [std]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		std::vector< int > v1(5, 42);
		
		std::cout << "int &p1 = v1.front();\n";
		int &p1 = v1.front();
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
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
		std::cout << "test back() [std]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		std::vector< int > v1(5, 42);
		
		std::cout << "int &p1 = v1.back();\n";
		int &p1 = v1.back();
		std::cout << "p1 = " << p1 << std::endl;
		std::cout << "p1 = 21;\n";
		p1 = 21;
		std::cout << "p1 = " << p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
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
		std::cout << "test data() [std]\n";
		std::cout << "std::vector< int > v1(5, 42);\n";
		std::vector< int > v1(5, 42);
		
		std::cout << "int *p1 = v1.data();\n";
		int *p1 = v1.data();
		std::cout << "*p1 = " << *p1 << std::endl;
		std::cout << "*p1 = 21;\n";
		*p1 = 21;
		std::cout << "*p1 = " << *p1 << std::endl;
		print_content(v1);
		std::cout << std::endl;
	}
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