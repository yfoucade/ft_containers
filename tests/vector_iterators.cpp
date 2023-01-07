/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:22:52 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/07 22:54:31 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

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

void	test_iterators( void )
{
	ft::vector< int > v1 = range_vector(0, 5);
	test_iterator(v1);
	test_const_iterator(v1);
	test_reverse_iterator(v1);
	test_const_reverse_iterator(v1);
}
