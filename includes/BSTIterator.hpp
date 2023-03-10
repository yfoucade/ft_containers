/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:08:44 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/01 17:35:39 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>

namespace ft
{

// template parameter: class BinarySearchTree, then define member types in terms
// of those of the parameter.
template<
	typename BST,
	typename T
> class BSTIterator{
	public:
		typedef long int difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T& indirection_type;
		typedef T* member_of_pointer_type;

	private:
		BST** _root;
		BST* _curr;

	public:
		BSTIterator( void );
		BSTIterator( BST** root, BST* curr = NULL );
		BSTIterator( const BSTIterator& other );
		BSTIterator& operator=( const BSTIterator& other );
		void operator=( BST* new_curr );
		~BSTIterator( void );
		template< typename Tree, typename A, typename B >
		friend bool operator==( const BSTIterator< Tree, A >&, const BSTIterator< Tree, B >& );
		template< typename Tree, typename A, typename B >
		friend bool operator!=( const BSTIterator< Tree, A >&, const BSTIterator< Tree, B >& );
		// reference operator*( void );
		indirection_type operator*( void );
		member_of_pointer_type operator->( void );
		BSTIterator& operator++( void );
		BSTIterator operator++( int );
		BSTIterator& operator--( void );
		BSTIterator operator--( int );
		BST* get_node( void );
		operator typename BST::const_iterator() const;
};

template< typename BST, typename T >
BSTIterator< BST, T >::operator typename BST::const_iterator() const
{
	return typename BST::const_iterator(_root, _curr);
}

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( void ):
_root(NULL), _curr(NULL){}

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( BST** root, BST* curr ):
_root(root), _curr(curr){}

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( const BSTIterator& other ):
_root(other._root), _curr(other._curr){}

template< typename BST, typename T >
BSTIterator< BST, T >&
BSTIterator< BST, T >::operator=( const BSTIterator& other )
{
	if ( this == &other )
		return *this;
	_root = other._root;
	_curr = other._curr;
	return *this;
}

template< typename BST, typename T >
void BSTIterator< BST, T >::operator=( BST* new_curr )
{
	_curr = new_curr;
}

template< typename BST, typename T >
BSTIterator< BST, T >::~BSTIterator( void )
{}

template< typename BST, typename T >
typename BSTIterator< BST, T >::reference
BSTIterator< BST, T >::operator*( void )
{
	return _curr->indirection();
}

template< typename BST, typename T >
typename BSTIterator< BST, T >::pointer
BSTIterator< BST, T >::operator->( void )
{
	return _curr->member_of_pointer();
}

template< typename BST, typename T >
BSTIterator< BST, T >&
BSTIterator< BST, T >::operator++( void )
{
	if (_curr)
		_curr = _curr->successor();
	return *this;
}

template< typename BST, typename T >
BSTIterator< BST, T >
BSTIterator< BST, T >::operator++( int )
{
	BSTIterator ret = *this;
	operator++();
	return ret;
}

template< typename BST, typename T >
BSTIterator< BST, T >&
BSTIterator< BST, T >::operator--( void )
{
	BST* tmp;

	if (!_curr)
		_curr = (*_root)->maximum();
	else
	{
		tmp = _curr->predecessor();
		if (tmp)
			_curr = tmp;
	}
	return *this;
}

template< typename BST, typename T >
BSTIterator< BST, T >
BSTIterator< BST, T >::operator--( int )
{
	BSTIterator ret = *this;
	operator--();
	return ret;
}

} // namespace ft

// non-member functions
namespace ft
{

template< typename BST, typename T, typename U >
bool
operator==( const BSTIterator< BST, T >& lhs, const BSTIterator< BST, U >& rhs )
{
	return ((lhs._curr == rhs._curr ) && (lhs._root == rhs._root));
}

template< typename BST, typename T, typename U >
bool
operator!=( const BSTIterator< BST, T >& lhs, const BSTIterator< BST, U >& rhs )
{
	return !( lhs == rhs );
}

template< typename BST, typename T >
BST* BSTIterator< BST, T >::get_node( void )
{
	return _curr;
}

} // namespace ft
