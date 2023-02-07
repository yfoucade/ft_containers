/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:01:21 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/08 00:39:02 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// #include <iomanip>
// #include <iostream>
// #include <vector>
// #include "vector.hpp"
// #include "map.hpp"
// #include "pair.hpp"

template< typename Container >
void	print_content( Container c, char sep = ' ' );
void	test_constructors( void );
void	test_access( void );
void	test_iterators( void );
ft::vector< int > range_vector(int min, int max);
void	test_capacity( void );
void	test_modifiers( void );
void	test_non_member( void );

// map
void test_constructor( void );
void test_map_access( void );

template< typename Container >
void print_content( Container c, char sep )
{
	typename Container::iterator start = c.begin();
	typename Container::iterator end = c.end();
	while (start != end)
		std::cout << *start++ << sep;
	std::cout << "\n";
}

template < typename T >
void test_const_access( const ft::vector< T > v )
{
	std::cout << "vector = {0, 1, 2, 3, 4}\n";
	std::cout << "v.at(1) = " << v.at(1) << std::endl;
	std::cout << "v[2] = " << v[2] << std::endl;
	std::cout << "v.front() = " << v.front() << std::endl;
	std::cout << "v.back() = " << v.back() << std::endl;
	std::cout << "*(v.data() + 3) = " << *(v.data() + 3) << std::endl;
	std::cout << std::endl;
}

template< typename T >
class EvenFirst
{
	public:
		bool operator()( const T& lhs, const T& rhs );
};

template< typename T >
bool EvenFirst<T>::operator()( const T& lhs, const T& rhs )
{
	if ( ( lhs % 2 ) != ( rhs % 2 ) )
		return (rhs % 2);
	return lhs < rhs;
}