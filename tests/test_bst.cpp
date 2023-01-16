/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:05:08 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/14 17:11:18 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BinarySearchTree.hpp"
#include "BSTIterator.hpp"

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

	ft::BSTIterator< char > it(&bst);
	ft::BSTIterator< char > end;
	while (it != end)
	{
		std::cout << (*it) << std::endl;
		++it;
	}
}