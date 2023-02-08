/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:08:44 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/06 21:50:00 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>

namespace ft
{

// template parameter: class BinarySearchTree, then define member types in terms
// of those of the parameter.
template<
	typename RBT,
	typename T
> class RBTIterator{
	public:
		typedef long int difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename RBT::node_type node_type;
		typedef T& indirection_type;
		typedef T* member_of_pointer_type;

	private:
		RBT* _rbt;
		node_type* _curr;

	public:
		RBTIterator( void );
		RBTIterator( RBT* root, node_type* curr = NULL );
		RBTIterator( const RBTIterator& other );
		RBTIterator& operator=( const RBTIterator& other );
		void operator=( node_type* new_curr );
		~RBTIterator( void );
		template< typename Tree, typename A, typename B >
		friend bool operator==( const RBTIterator< Tree, A >&, const RBTIterator< Tree, B >& );
		template< typename Tree, typename A, typename B >
		friend bool operator!=( const RBTIterator< Tree, A >&, const RBTIterator< Tree, B >& );
		// reference operator*( void );
		indirection_type operator*( void );
		member_of_pointer_type operator->( void );
		RBTIterator& operator++( void );
		RBTIterator operator++( int );
		RBTIterator& operator--( void );
		RBTIterator operator--( int );
		node_type* get_node( void );
		operator typename RBT::const_iterator() const;
};

template< typename RBT, typename T >
RBTIterator< RBT, T >::operator typename RBT::const_iterator() const
{
	return typename RBT::const_iterator(_rbt, _curr);
}

template< typename RBT, typename T >
RBTIterator< RBT, T >::RBTIterator( void ):
_rbt(NULL), _curr(NULL){}

template< typename RBT, typename T >
RBTIterator< RBT, T >::RBTIterator( RBT* rbt, node_type* curr ):
_rbt(rbt), _curr(curr){}

template< typename RBT, typename T >
RBTIterator< RBT, T >::RBTIterator( const RBTIterator& other ):
_rbt(other._rbt), _curr(other._curr){}

template< typename RBT, typename T >
RBTIterator< RBT, T >&
RBTIterator< RBT, T >::operator=( const RBTIterator& other )
{
	if ( this == &other )
		return *this;
	_rbt = other._rbt;
	_curr = other._curr;
	return *this;
}

template< typename RBT, typename T >
void RBTIterator< RBT, T >::operator=( node_type* new_curr )
{
	_curr = new_curr;
}

template< typename RBT, typename T >
RBTIterator< RBT, T >::~RBTIterator( void )
{}

template< typename RBT, typename T >
typename RBTIterator< RBT, T >::reference
RBTIterator< RBT, T >::operator*( void )
{
	return *(_curr->value);
}

template< typename RBT, typename T >
typename RBTIterator< RBT, T >::pointer
RBTIterator< RBT, T >::operator->( void )
{
	return _curr->value;
}

template< typename RBT, typename T >
RBTIterator< RBT, T >&
RBTIterator< RBT, T >::operator++( void )
{
	if (_curr)
		_curr = _rbt->successor(_curr);
	return *this;
}

template< typename RBT, typename T >
RBTIterator< RBT, T >
RBTIterator< RBT, T >::operator++( int )
{
	RBTIterator ret = *this;
	operator++();
	return ret;
}

template< typename RBT, typename T >
RBTIterator< RBT, T >&
RBTIterator< RBT, T >::operator--( void )
{
	node_type* tmp;

	if (!_curr)
		_curr = _rbt->maximum();
	else
	{
		tmp = _rbt->predecessor(_curr);
		if (tmp)
			_curr = tmp;
	}
	return *this;
}

template< typename RBT, typename T >
RBTIterator< RBT, T >
RBTIterator< RBT, T >::operator--( int )
{
	RBTIterator ret = *this;
	operator--();
	return ret;
}

} // namespace ft

// non-member functions
namespace ft
{

template< typename RBT, typename T, typename U >
bool
operator==( const RBTIterator< RBT, T >& lhs, const RBTIterator< RBT, U >& rhs )
{
	return ((lhs._curr == rhs._curr ) && (lhs._rbt == rhs._rbt));
}

template< typename RBT, typename T, typename U >
bool
operator!=( const RBTIterator< RBT, T >& lhs, const RBTIterator< RBT, U >& rhs )
{
	return !( lhs == rhs );
}

template< typename RBT, typename T >
typename RBTIterator<RBT, T>::node_type*
RBTIterator< RBT, T >::get_node( void )
{
	return _curr;
}

} // namespace ft
