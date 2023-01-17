/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:08:44 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/17 12:48:49 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <functional>

namespace ft
{

// template parameter: class BinarySearchTree, then define member types in terms
// of those of the parameter.
template<
	typename BST
> class BSTIterator{
	private:
		BST* _node;

	public:
		typedef void difference_type;
		typedef BST value_type;
		typedef BST* pointer;
		typedef BST& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename BST::indirection_type indirection_type;
		typedef typename BST::member_of_pointer_type member_of_pointer_type;
		BSTIterator( void );
		BSTIterator( BST* node );
		BSTIterator( const BSTIterator& other );
		BSTIterator& operator=( const BSTIterator& other );
		~BSTIterator( void );
		template< typename A >
		friend bool operator==( const BSTIterator< A >&, const BSTIterator< A >& );
		template< typename A >
		friend bool operator!=( const BSTIterator< A >&, const BSTIterator< A >& );
		// reference operator*( void );
		indirection_type operator*( void );
		member_of_pointer_type operator->( void );
		BSTIterator& operator++( void );
		BSTIterator operator++( int );
		BSTIterator& operator--( void );
		BSTIterator operator--( int );
};

template< typename BST >
BSTIterator< BST >::BSTIterator( void ):
_node(NULL){}

template< typename BST >
BSTIterator< BST >::BSTIterator( BST* node ):
_node(node){}

template< typename BST >
BSTIterator< BST >::BSTIterator( const BSTIterator& other ):
_node(other._node){}

template< typename BST >
BSTIterator< BST >&
BSTIterator< BST >::operator=( const BSTIterator& other )
{
	if ( this == &other )
		return *this;
	_node = other._node;
}

template< typename BST >
BSTIterator< BST >::~BSTIterator( void )
{}

template< typename BST >
// typename BSTIterator< BST >::reference
typename BSTIterator< BST >::indirection_type
BSTIterator< BST >::operator*( void )
{
	return _node->indirection();
}

template< typename BST >
typename BSTIterator< BST >::member_of_pointer_type
BSTIterator< BST >::operator->( void )
{
	return _node.member_of_pointer();
}

template< typename BST >
BSTIterator< BST >&
BSTIterator< BST >::operator++( void )
{
	_node = _node->successor();
	return *this;
}

template< typename BST >
BSTIterator< BST >
BSTIterator< BST >::operator++( int )
{
	BSTIterator ret = *this;
	_node = _node->successor();
	return ret;
}

template< typename BST >
BSTIterator< BST >&
BSTIterator< BST >::operator--( void )
{
	_node = _node->predecessor();
	return *this;
}

template< typename BST >
BSTIterator< BST >
BSTIterator< BST >::operator--( int )
{
	BSTIterator ret = *this;
	_node = _node->predecessor();
	return ret;
}

} // namespace ft

// non-member functions
namespace ft
{

template< typename BST >
bool
operator==( const BSTIterator< BST >& lhs, const BSTIterator< BST >& rhs )
{
	return ( lhs._node == rhs._node );
}

template< typename BST >
bool
operator!=( const BSTIterator< BST >& lhs, const BSTIterator< BST >& rhs )
{
	return !( lhs._node == rhs._node );
}

} // namespace ft
