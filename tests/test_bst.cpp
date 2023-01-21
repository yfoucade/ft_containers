/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:05:08 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/19 19:42:39 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pair.hpp"
#include "BinarySearchTree.hpp"

void	test_bst( void )
{
	ft::pair< const char, int> a('a', 1);
	ft::pair< const char, int> b('b', 2);
	ft::pair< const char, int> c('c', 3);
	ft::pair< const char, int> d('d', 4);
	ft::BinarySearchTree< char, int > bst_a(&a);
	ft::BinarySearchTree< char, int > bst_b(&b);
	ft::BinarySearchTree< char, int > bst_c(&c);
	ft::BinarySearchTree< char, int > bst_d(&d);

	bst_a.insert(bst_b);
	ft::BinarySearchTree< char, int >::iterator it = bst_a.minimum();
	ft::BinarySearchTree< char, int >::iterator end = bst_a.maximum();
	while (it != ++end)
	{
		std::cout << (&*it) << ": " << it->first << ", " << it->second << std::endl;
		++it->second;
		std::cout << (&*it) << ": " << it->first << ", " << it->second << std::endl;
		++it;
	}


	ft::BinarySearchTree< char, int >::const_iterator cit = bst_a.minimum();
	ft::BinarySearchTree< char, int >::const_iterator cend = bst_a.maximum();
	while (cit != ++cend)
	{
		std::cout << (&*cit) << ": " << cit->first << ", " << cit->second << std::endl;
		++cit;
	}
}

int	main( void )
{
	ft::BinarySearchTree< char > bst( 'a' );
	ft::BinarySearchTree< char > g('g');
	ft::BinarySearchTree< char > e('e');
	ft::BinarySearchTree< char > z('z');
	ft::BinarySearchTree< char > b('b');
	ft::BinarySearchTree< char > Z('Z');

	ft::BinarySearchTree< char > *tmp = bst.minimum();
	while (tmp)
	{
		std::cout << tmp->get_key() << " ";
		tmp = tmp->successor();
	}
	std::cout << std::endl;

	bst.insert(g);
	bst.insert(e);
	bst.insert(z);
	bst.insert(b);
	bst.insert(Z);

	tmp = bst.minimum();
	while (tmp)
	{
		std::cout << tmp->get_key() << " ";
		tmp = tmp->successor();
	}
	std::cout << std::endl;

	tmp = bst.maximum();
	while (tmp)
	{
		std::cout << tmp->get_key() << " ";
		tmp = tmp->predecessor();
	}
	std::cout << std::endl;

	tmp = bst.search('a');
	std::cout << tmp->get_key() << "\n";
	
	tmp = bst.search('-');
	if (tmp)
		std::cout << tmp->get_key() << "\n";
	else
		std::cout << "'-' not found\n";

	z.remove();
	tmp = bst.minimum();
	while (tmp)
	{
		std::cout << tmp->get_key() << " ";
		tmp = tmp->successor();
	}
	std::cout << std::endl << std::endl;

	ft::BinarySearchTree< char >::iterator it(&bst);
	ft::BinarySearchTree< char >::iterator end = &bst;
	while (it != ++end)
	{
		std::cout << (*it) << std::endl;
		++it;
	}
	ft::BinarySearchTree< char >::iterator it2(&bst);
	while (it2 != end)
	{
		std::cout << (*it2) << std::endl;
		++it2;
	}
	std::cout << std::endl;
	test_bst();
}
