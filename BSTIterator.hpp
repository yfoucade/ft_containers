/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:08:44 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/19 19:21:28 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
		typedef void difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T& indirection_type;
		typedef T* member_of_pointer_type;

	private:
		BST* _root;
		BST* _curr;
		pointer _value;

	public:
		BSTIterator( void );
		BSTIterator( BST* node );
		BSTIterator( const BSTIterator& other );
		BSTIterator& operator=( const BSTIterator& other );
		~BSTIterator( void );
		template< typename A, typename B >
		friend bool operator==( const BSTIterator< A, B >&, const BSTIterator< A, B >& );
		template< typename A, typename B >
		friend bool operator!=( const BSTIterator< A, B >&, const BSTIterator< A, B >& );
		// reference operator*( void );
		indirection_type operator*( void );
		member_of_pointer_type operator->( void );
		BSTIterator& operator++( void );
		BSTIterator operator++( int );
		BSTIterator& operator--( void );
		BSTIterator operator--( int );
};

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( void ):
_root(NULL), _curr(NULL), _value(NULL){}

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( BST* node ):
_root(node->get_root()), _curr(node), _value(node->member_of_pointer()){}

template< typename BST, typename T >
BSTIterator< BST, T >::BSTIterator( const BSTIterator& other ):
_root(other._root), _curr(other._curr), _value(other._value){}

template< typename BST, typename T >
BSTIterator< BST, T >&
BSTIterator< BST, T >::operator=( const BSTIterator& other )
{
	if ( this == &other )
		return *this;
	_root = other._root;
	_curr = other._curr;
	_value = other._value;
	return *this;
}

template< typename BST, typename T >
BSTIterator< BST, T >::~BSTIterator( void )
{}

template< typename BST, typename T >
// typename BSTIterator< BST, T >::reference
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
	{
		_curr = _curr->successor();
		if (_curr)
			_value = _curr->member_of_pointer();
		else
			_value = NULL;
	}
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
	if (!_curr)
	{
		_curr = _root->maximum();
		_value = _curr->member_of_pointer();
		return *this;
	}
	_curr = _curr->predecessor();
	_value = _curr->member_of_pointer();
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

template< typename BST, typename T >
bool
operator==( const BSTIterator< BST, T >& lhs, const BSTIterator< BST, T >& rhs )
{
	return ((lhs._curr == rhs._curr ) && ( lhs._root == rhs._root));
}

template< typename BST, typename T >
bool
operator!=( const BSTIterator< BST, T >& lhs, const BSTIterator< BST, T >& rhs )
{
	return !( lhs == rhs );
}

} // namespace ft
