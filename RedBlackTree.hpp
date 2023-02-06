/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:12:40 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/06 04:03:51 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED 0
#define BLACK 1
#include "RBTIterator.hpp"

namespace ft
{

template< typename Key, typename T, typename Compare >
struct RBNode
{
	bool color;
	Key key;
	T* value;
	RBNode *parent;
	RBNode *left;
	RBNode *right;
};

template< typename Key, typename T, typename Compare >
class RedBlackTree
{
public:
	typedef Key key_type;
	typedef T value_type;
	typedef RBNode<Key, T, Compare> node_type;
	typedef value_type* value_pointer;
	typedef value_type& value_reference;
	typedef value_type& indirection_type;
	typedef value_type* member_of_pointer_type;
	typedef RBTIterator< RedBlackTree<Key, T, Compare>, value_type > iterator;
	typedef RBTIterator< RedBlackTree<Key, T, Compare>, const value_type > const_iterator;

private:
	node_type* _nil;
	node_type* _root;
	Compare key_compare;
	RedBlackTree( const RedBlackTree& other );
	RedBlackTree& operator=( const RedBlackTree& other );
	void right_rotate( node_type* node );
	void left_rotate( node_type* node );
	void insert_fixup( node_type* z );
	void remove_fixup( node_type* x );

public:
	RedBlackTree( void );
	RedBlackTree( node_type* node );
	~RedBlackTree();
	node_type* search( const Key& key ) const;
	node_type* get_root( void ) const;
	node_type* get_nil( void ) const;
	node_type* minimum( void ) const;
	node_type* minimum( node_type* node ) const;
	node_type* maximum( void ) const;
	node_type* maximum( node_type* node ) const;
	node_type* successor( node_type* node ) const;
	node_type* predecessor( node_type* node ) const;
	void insert( node_type* node );
	void transplant( node_type* old_, node_type* new_ );
	void remove( node_type* node );
};

template< typename Key, typename T, typename Compare >
RedBlackTree<Key, T, Compare>::RedBlackTree( void ):
_nil(NULL), _root(NULL)
{}

template< typename Key, typename T, typename Compare >
RedBlackTree<Key, T, Compare>::RedBlackTree( node_type* node ):
_nil(new node_type(BLACK, node->key, NULL, NULL, NULL, NULL)),
_root(node)
{}

template< typename Key, typename T, typename Compare >
RedBlackTree<Key, T, Compare>::~RedBlackTree( void )
{
	delete(_nil);
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::search( const Key& key ) const
{
	node_type* res = _root;
	while ( res != _nil )
	{
		if (key_compare(key, res->key))
			res = res->left;
		else if (key_compare(res->key, key))
			res = res->right;
		else
			break;
	}
	return (res != _nil) ? res : NULL;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::get_root( void ) const
{
	return _root;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::get_nil( void ) const
{
	return _nil;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::minimum( void ) const
{
	node_type* res = _root;

	if (!res || res == _nil)
		return NULL;
	while (res->left != _nil)
		res = res->left;
	return res;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::minimum( node_type* node ) const
{
	while (node->left != _nil)
		node = node->left;
	return node;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::maximum( void ) const
{
	node_type* res = _root;

	if (!res || res == _nil)
		return NULL;
	while (res->right != _nil)
		res = res->right;
	return res;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::maximum( node_type* node ) const
{
	while (node->right != _nil)
		node = node->right;
	return node;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::successor( node_type* node ) const
{
	node_type* y = node->parent;

	if (node->right != _nil)
		return minimum(node->right);
	while (y != _nil && node == y->right)
	{
		node = y;
		y = y->parent;
	}
	return (y != _nil) ? y : NULL;
}

template< typename Key, typename T, typename Compare >
typename RedBlackTree<Key, T, Compare>::node_type*
RedBlackTree<Key, T, Compare>::predecessor( node_type* node ) const
{
	node_type* y = node->parent;

	if (node->left != _nil)
		return maximum(node->left);
	while (y != _nil && node == y->left)
	{
		node = y;
		y = y->parent;
	}
	return (y != _nil) ? y : NULL;
}

template< typename Key, typename T, typename Compare >
void
RedBlackTree<Key, T, Compare>::transplant( node_type* old_, node_type* new_ )
{
	if (old_->parent == _nil)
		_root = new_;
	else if (old_ == old_->parent->left)
		old_->parent->left = new_;
	else
		old_->parent->right = new_;
	new_->parent = old_->parent;
}

template< typename Key, typename T, typename Compare >
void
RedBlackTree<Key, T, Compare>::insert( node_type* node )
{
	node_type* trailing = _nil;
	node_type* leading = _root;

	while (leading != _nil)
	{
		trailing = leading;
		if (key_compare(node->key, leading->key))
			leading = leading->left;
		else
			leading = leading->right;
	}
	node->parent = trailing;
	if (trailing == _nil)
		_root = node;
	else if (key_compare(node->key, trailing->key))
		trailing->left = node;
	else
		trailing->right = node;
	node->left = _nil;
	node->right = _nil;
	node->color = RED;
	insert_fixup(node);
}

template< typename Key, typename T, typename Compare >
void
RedBlackTree<Key, T, Compare>::remove( node_type* z )
{
	node_type* y = z;
	node_type* x;
	bool y_original_color = y->color;

	if (z->left == _nil)
	{
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == _nil)
	{
		x = z->left;
		transplant(z, z->left);
	}
	else
	{
		y = minimum(z->right);
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		else
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (y_original_color == BLACK)
		remove_fixup(x);
}

} // namespace ft

namespace ft
{


template< typename Key, typename T, typename Compare >
void RedBlackTree<Key, T, Compare>::right_rotate( node_type* node )
{
	node_type* y = node->left;
	node->left = y->right;
	if (y->right != _nil)
		y->right->parent = node;
	y->parent = node->parent;
	if (node->parent == _nil)
		_root = y;
	else if (node == node->parent->right)
		node->parent->right = y;
	else
		node->parent->left = y;
	y->right = node;
	node->parent = y;
}

template< typename Key, typename T, typename Compare >
void RedBlackTree<Key, T, Compare>::left_rotate( node_type* node )
{
	node_type* y = node->right;
	node->right = y->left;
	if (y->left != _nil)
		y->left->parent = node;
	y->parent = node->parent;
	if (node->parent == _nil)
		_root = y;
	else if (node == node->parent->left)
		node->parent->left = y;
	else
		node->parent->right = y;
	y->left = node;
	node->parent = y;
}

template< typename Key, typename T, typename Compare >
void RedBlackTree<Key, T, Compare>::insert_fixup( node_type* z )
{
	node_type* y;

	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					right_rotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
	}
	_root->color = BLACK;
}

template< typename Key, typename T, typename Compare >
void
RedBlackTree<Key, T, Compare>::remove_fixup( node_type* x )
{
	node_type* w;

	while ( (x != _root) && (x->color == BLACK) )
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				left_rotate(x->parent);
				x = _root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				right_rotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(x->parent);
				x = _root;
			}
		}
	}
	x->color = BLACK;
}


} // namespace ft