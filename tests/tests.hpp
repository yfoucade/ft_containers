/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:01:21 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/07 15:22:21 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "pair.hpp"

template< typename Container >
void print_content( Container c, char sep = ' ' );
void	test_constructors( void );

template< typename Container >
void print_content( Container c, char sep )
{
	typename Container::iterator start = c.begin();
	typename Container::iterator end = c.end();
	while (start != end)
		std::cout << *start++ << sep;
	std::cout << "\n";
}