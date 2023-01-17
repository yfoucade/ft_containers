/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:08:44 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/17 06:39:22 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <functional>
#include "BinarySearchTree.hpp"

namespace ft
{

// template parameter: class BinarySearchTree, then define member types in terms
// of those of the parameter.
template<
	typename Key,
	typename T = void,
	typename Compare = std::less< Key >
> class BSTIterator{
	private:
		BinarySearchTree< Key, T, Compare >* _node;

	public:
		typedef void difference_type;
		typedef BinarySearchTree< Key, T, Compare > value_type;
		typedef BinarySearchTree< Key, T, Compare >* pointer;
		typedef BinarySearchTree< Key, T, Compare >& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		BSTIterator( void );
		BSTIterator( BinarySearchTree< Key, T, Compare >* node );
		BSTIterator( const BSTIterator& other );
		BSTIterator& operator=( const BSTIterator& other );
		~BSTIterator( void );
		template< typename A, typename B, typename C>
		friend bool operator==( const BSTIterator<A, B, C >&, const BSTIterator< A, B, C>& );
		template< typename A, typename B, typename C>
		friend bool operator!=( const BSTIterator< A, B, C >&, const BSTIterator< A, B, C >& );
		// reference operator*( void );
		T* operator*( void );
		pointer operator->( void );
		BSTIterator& operator++( void );
		BSTIterator operator++( int );
		BSTIterator& operator--( void );
		BSTIterator operator--( int );
};

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >::BSTIterator( void ):
_node(NULL){}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >::BSTIterator( BinarySearchTree< Key, T, Compare >* node ):
_node(node){}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >::BSTIterator( const BSTIterator& other ):
_node(other._node){}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >&
BSTIterator< Key, T, Compare >::operator=( const BSTIterator& other )
{
	if ( this == &other )
		return *this;
	_node = other._node;
}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >::~BSTIterator( void )
{}

template< typename Key, typename T, typename Compare >
// typename BSTIterator< Key, T, Compare >::reference
T*
BSTIterator< Key, T, Compare >::operator*( void )
{
	return _node->get_value();
}

template< typename Key, typename T, typename Compare >
typename BSTIterator< Key, T, Compare >::pointer
BSTIterator< Key, T, Compare >::operator->( void )
{
	return _node.get_value();
}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >&
BSTIterator< Key, T, Compare >::operator++( void )
{
	_node = _node->successor();
	return *this;
}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >
BSTIterator< Key, T, Compare >::operator++( int )
{
	BSTIterator ret = *this;
	_node = _node->successor();
	return ret;
}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >&
BSTIterator< Key, T, Compare >::operator--( void )
{
	_node = _node->predecessor();
	return *this;
}

template< typename Key, typename T, typename Compare >
BSTIterator< Key, T, Compare >
BSTIterator< Key, T, Compare >::operator--( int )
{
	BSTIterator ret = *this;
	_node = _node->predecessor();
	return ret;
}

} // namespace ft

namespace ft
{

template<
typename Key,
typename Compare
> class BSTIterator< Key, void, Compare >{
	private:
		BinarySearchTree< Key, void, Compare >* _node;

	public:
		typedef void difference_type;
		typedef BinarySearchTree< Key, void, Compare > value_type;
		typedef BinarySearchTree< Key, void, Compare >* pointer;
		typedef BinarySearchTree< Key, void, Compare >& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		BSTIterator( void );
		BSTIterator( BinarySearchTree< Key, void, Compare >* node );
		BSTIterator( const BSTIterator& other );
		BSTIterator& operator=( const BSTIterator& other );
		~BSTIterator( void );
		template< typename A, typename C>
		friend bool operator==( const BSTIterator<A, void, C >&, const BSTIterator< A, void, C>& );
		template< typename A, typename C>
		friend bool operator!=( const BSTIterator< A, void, C >&, const BSTIterator< A, void, C >& );
		Key operator*( void );
		Key* operator->( void );
		BSTIterator& operator++( void );
		BSTIterator operator++( int );
		BSTIterator& operator--( void );
		BSTIterator operator--( int );
};

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >::BSTIterator( void ):
_node(NULL){}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >::BSTIterator( BinarySearchTree< Key, void, Compare >* node ):
_node(node){}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >::BSTIterator( const BSTIterator& other ):
_node(other._node){}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >&
BSTIterator< Key, void, Compare >::operator=( const BSTIterator& other )
{
	if ( this == &other )
		return *this;
	_node = other._node;
}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >::~BSTIterator( void )
{}

template< typename Key, typename Compare >
// typename BSTIterator< Key, void, Compare >::reference
Key
BSTIterator< Key, void, Compare >::operator*( void )
{
	return _node->get_key();
}

template< typename Key, typename Compare >
Key*
BSTIterator< Key, void, Compare >::operator->( void )
{
	return _node.get_key();
}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >&
BSTIterator< Key, void, Compare >::operator++( void )
{
	_node = _node->successor();
	return *this;
}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >
BSTIterator< Key, void, Compare >::operator++( int )
{
	BSTIterator ret = *this;
	_node = _node->successor();
	return ret;
}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >&
BSTIterator< Key, void, Compare >::operator--( void )
{
	_node = _node->predecessor();
	return *this;
}

template< typename Key, typename Compare >
BSTIterator< Key, void, Compare >
BSTIterator< Key, void, Compare >::operator--( int )
{
	BSTIterator ret = *this;
	_node = _node->predecessor();
	return ret;
}

} // namespace ft


// non-member functions
namespace ft
{

template< typename Key, typename T = void, typename Compare = std::less< Key > >
bool
operator==( const BSTIterator< Key, T, Compare >& lhs, const BSTIterator< Key, T, Compare >& rhs )
{
	return ( lhs._node == rhs._node );
}

template< typename Key, typename T = void, typename Compare = std::less< Key > >
bool
operator!=( const BSTIterator< Key, T, Compare >& lhs, const BSTIterator< Key, T, Compare >& rhs )
{
	return !( lhs._node == rhs._node );
}

template< typename Key, typename Compare = std::less< Key > >
bool
operator==( const BSTIterator< Key, void, Compare >& lhs, const BSTIterator< Key, void, Compare >& rhs )
{
	return ( lhs._node == rhs._node );
}

template< typename Key, typename Compare = std::less< Key > >
bool
operator!=( const BSTIterator< Key, void, Compare >& lhs, const BSTIterator< Key, void, Compare >& rhs )
{
	return !( lhs._node == rhs._node );
}

} // namespace ft
