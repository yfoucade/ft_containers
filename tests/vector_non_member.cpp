/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_non_member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:19:22 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/10 13:36:19 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_eq( void )
{
	{
		std::cout << "test equal [std]\n";
		std::vector< int > v1(5, 42);
		std::vector< int > v2(5, 42);
		std::cout << (v1 == v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 == v2) << std::endl;
		std::cout << std::endl;
	}
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
		std::cout << "test not equal [std]\n";
		std::vector< int > v1(5, 42);
		std::vector< int > v2(5, 42);
		std::cout << (v1 != v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 != v2) << std::endl;
		std::cout << std::endl;
	}
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
		std::cout << "test less than [std]\n";
		std::vector< int > v1(5, 42);
		std::vector< int > v2(5, 42);
		std::cout << (v1 < v2) << std::endl;
		v1.pop_back();
		std::cout << (v1 < v2) << std::endl;
		std::cout << std::endl;
	}
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
		std::cout << "test swap again [std]\n";
		int tab[] = {1, 2, 3, 7, 8, 9, 10};
		std::vector<int> alice(tab, tab + 3);
		std::vector<int> bob(tab + 3, tab + 6);
		std::vector<int> eve(tab, tab + 3);

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
	{
		std::cout << "test swap again [ft]\n";
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