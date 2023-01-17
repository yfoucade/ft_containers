/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:58:52 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/17 11:45:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>

namespace ft
{

// implement a member function get_root() that returns a reference to the root.
template<
	typename Key,
	typename T = void,
	typename Compare = std::less<Key>
> class BinarySearchTree
{
	private:
		Key _key;
		T *_value;
		BinarySearchTree *_parent;
		BinarySearchTree *_left;
		BinarySearchTree *_right;
		Compare key_compare;
		BinarySearchTree( void );

	public:
		typedef T& indirection_type;
		typedef T* member_of_pointer_type;
		BinarySearchTree( const Key& key );
		BinarySearchTree( const Key& key, T* value );
		BinarySearchTree( const BinarySearchTree& other );
		BinarySearchTree& operator=( const BinarySearchTree& other );
		~BinarySearchTree( void );
		BinarySearchTree* search( const Key& _key );
		BinarySearchTree* search( const Key& _key ) const;
		BinarySearchTree* get_root( void );
		BinarySearchTree* minimum( void );
		BinarySearchTree* minimum( void ) const;
		BinarySearchTree* maximum( void );
		BinarySearchTree* maximum( void ) const;
		BinarySearchTree* successor( void );
		BinarySearchTree* successor( void ) const;
		BinarySearchTree* predecessor( void );
		BinarySearchTree* predecessor( void ) const;
		void insert( BinarySearchTree& other );
		// void insert( const Key& key );
		// void insert( const Key& key, T* value );
		BinarySearchTree* transplant( BinarySearchTree* other );
		BinarySearchTree* remove( void );
		Key get_key( void ) const;
		T *get_value( void ) const;
		indirection_type indirection( void );
		member_of_pointer_type member_of_pointer( void );
};

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >::BinarySearchTree( const Key& key ):
_key(key),
_value(NULL),
_parent(NULL),
_left(NULL),
_right(NULL){}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >::BinarySearchTree( const Key& key, T *value ):
_key(key),
_value(value),
_parent(NULL),
_left(NULL),
_right(NULL){}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >::BinarySearchTree( const BinarySearchTree& other ):
_key(other._key),
_value(other._value),
_parent(other._parent),
_left(other._left),
_right(other._right){}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >& BinarySearchTree< Key, T, Compare >::operator=( const BinarySearchTree& other )
{
	if (this == &other)
		return *this;
	_key = other._key;
	_value = other._value;
	_parent = other._parent;
	_left = other._left;
	_right = other._right;
	return *this;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >::~BinarySearchTree( void )
{
	if (_left)
		_left->~BinarySearchTree();
	if (_right)
		_right->~BinarySearchTree();
	remove();
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::search( const Key& key )
{
	BinarySearchTree *res = this;
	while ( res )
	{
		if ( key_compare(res->_key, key) )
			res = res->_right;
		else if ( key_compare(key, res->_key) )
			res = res->_left;
		else
			break;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::search( const Key& key ) const
{
	BinarySearchTree *res = this;
	while ( res )
	{
		if ( key_compare(res->_key, key) )
			res = res->_right;
		else if ( key_compare(key, res->_key) )
			res = res->_left;
		else
			break;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::get_root( void )
{
	BinarySearchTree *ret = this;
	while ( ret->_parent )
		ret = ret->_parent;
	return ret;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::minimum( void )
{
	BinarySearchTree *res = this;
	while (res->_left)
		res = res->_left;
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::minimum( void ) const
{
	BinarySearchTree *res = this;
	while (res->_left)
		res = res->_left;
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::maximum( void )
{
	BinarySearchTree *res = this;
	while (res->_right)
		res = res->_right;
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::maximum( void ) const
{
	BinarySearchTree *res = this;
	while (res->_right)
		res = res->_right;
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::successor( void )
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _right )
		return (_right->minimum());
	while ( res && (curr == res->_right) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::successor( void ) const
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _right )
		return (_right->minimum());
	while ( res && (curr == res->_right) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::predecessor( void )
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _left )
		return (_left->maximum());
	while ( res && (curr == res->_left) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::predecessor( void ) const
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _left )
		return (_left->maximum());
	while ( res && (curr == res->_left) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename T, typename Compare >
void
BinarySearchTree< Key, T, Compare >::insert( BinarySearchTree& other )
{
	BinarySearchTree *leading = this;
	BinarySearchTree *trailing = NULL;

	while (leading)
	{
		trailing = leading;
		leading = key_compare(leading->_key, other._key) ? leading->_right : leading->_left;
	}
	other._parent = trailing;
	if ( key_compare(trailing->_key, other._key) )
		trailing->_right = &other;
	else
		trailing->_left = &other;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::transplant( BinarySearchTree* other )
{
	if (!_parent)
		;
	else if (this == _parent->_left)
		_parent->_left = other;
	else
		_parent->_right = other;
	if (other)
		other->_parent = _parent;
	_parent = NULL;
	return this;
}

template< typename Key, typename T, typename Compare >
BinarySearchTree< Key, T, Compare >*
BinarySearchTree< Key, T, Compare >::remove( void )
{
	BinarySearchTree* successor;

	if (!_left)
		transplant(_right);
	else if (!_right)
		transplant(_left);
	else
	{
		successor = minimum();
		if (successor->_parent != this)
		{
			successor->transplant(successor->_right);
			successor->_right = _right;
			successor->_right->_parent = successor;
		}
		transplant(successor);
		successor->_left = _left;
		successor->_left->_parent = successor;
	}
	return this;
}

template< typename Key, typename T, typename Compare >
Key
BinarySearchTree< Key, T, Compare >::get_key( void ) const
{
	return _key;
}

template< typename Key, typename T, typename Compare >
T*
BinarySearchTree< Key, T, Compare >::get_value( void ) const
{
	return _value;
}


template< typename Key, typename T, typename Compare >
typename BinarySearchTree<Key, T, Compare>::indirection_type
BinarySearchTree<Key, T, Compare>::indirection( void )
{
	return _value;
}

template< typename Key, typename T, typename Compare >
typename BinarySearchTree<Key, T, Compare>::member_of_pointer_type
BinarySearchTree<Key, T, Compare>::member_of_pointer( void )
{
	return _value;
}

} // namespace ft

namespace ft
{

template< typename Key, typename Compare = std::less< Key > >
bool
equiv( const Key& k1, const Key& k2 )
{
	Compare comp{};
	return (!comp(k1, k2) && !comp(k2, k1) );
}

} // namespace ft

namespace ft
{

template< typename Key, typename Compare >
class BinarySearchTree<Key, void, Compare>
{
	private:
		Key _key;
		BinarySearchTree *_parent;
		BinarySearchTree *_left;
		BinarySearchTree *_right;
		Compare key_compare;
		BinarySearchTree( void );

	public:
		typedef Key& indirection_type;
		typedef Key* member_of_pointer_type;
		BinarySearchTree( const Key& key );
		BinarySearchTree( const BinarySearchTree& other );
		BinarySearchTree& operator=( const BinarySearchTree& other );
		~BinarySearchTree( void );
		BinarySearchTree* search( const Key& _key );
		BinarySearchTree* search( const Key& _key ) const;
		BinarySearchTree* get_root( void );
		BinarySearchTree* minimum( void );
		BinarySearchTree* minimum( void ) const;
		BinarySearchTree* maximum( void );
		BinarySearchTree* maximum( void ) const;
		BinarySearchTree* successor( void );
		BinarySearchTree* successor( void ) const;
		BinarySearchTree* predecessor( void );
		BinarySearchTree* predecessor( void ) const;
		void insert( BinarySearchTree& other );
		// void insert( const Key& key );
		BinarySearchTree* transplant( BinarySearchTree* other );
		BinarySearchTree* remove( void );
		Key get_key( void ) const;
		indirection_type indirection( void );
		member_of_pointer_type member_of_pointer( void );
};

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >::BinarySearchTree( const Key& key ):
_key(key),
_parent(NULL),
_left(NULL),
_right(NULL){}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >::BinarySearchTree( const BinarySearchTree& other ):
_key(other._key),
_parent(other._parent),
_left(other._left),
_right(other._right){}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >& BinarySearchTree< Key, void, Compare >::operator=( const BinarySearchTree& other )
{
	if (this == &other)
		return *this;
	_key = other._key;
	_parent = other._parent;
	_left = other._left;
	_right = other._right;
	return *this;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >::~BinarySearchTree( void )
{
	if (_left)
		_left->~BinarySearchTree();
	if (_right)
		_right->~BinarySearchTree();
	remove();
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::search( const Key& key )
{
	BinarySearchTree *res = this;
	while ( res )
	{
		if ( key_compare(res->_key, key) )
			res = res->_right;
		else if ( key_compare(key, res->_key) )
			res = res->_left;
		else
			break;
	}
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::search( const Key& key ) const
{
	BinarySearchTree *res = this;
	while ( res )
	{
		if ( key_compare(res->_key, key) )
			res = res->_right;
		else if ( key_compare(key, res->_key) )
			res = res->_left;
		else
			break;
	}
	return res;
}

// add const version
template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::get_root( void )
{
	BinarySearchTree *ret = this;
	while ( ret->_parent )
		ret = ret->_parent;
	return ret;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::minimum( void )
{
	BinarySearchTree *res = this;
	while (res->_left)
		res = res->_left;
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::minimum( void ) const
{
	BinarySearchTree *res = this;
	while (res->_left)
		res = res->_left;
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::maximum( void )
{
	BinarySearchTree *res = this;
	while (res->_right)
		res = res->_right;
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::maximum( void ) const
{
	BinarySearchTree *res = this;
	while (res->_right)
		res = res->_right;
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::successor( void )
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _right )
		return (_right->minimum());
	while ( res && (curr == res->_right) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::successor( void ) const
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _right )
		return (_right->minimum());
	while ( res && (curr == res->_right) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::predecessor( void )
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _left )
		return (_left->maximum());
	while ( res && (curr == res->_left) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::predecessor( void ) const
{
	BinarySearchTree *curr = this;
	BinarySearchTree *res = this->_parent;

	if ( _left )
		return (_left->maximum());
	while ( res && (curr == res->_left) )
	{
		curr = res;
		res = res->_parent;
	}
	return res;
}

template< typename Key, typename Compare >
void
BinarySearchTree< Key, void, Compare >::insert( BinarySearchTree& other )
{
	BinarySearchTree *leading = this;
	BinarySearchTree *trailing = NULL;

	while (leading)
	{
		trailing = leading;
		leading = key_compare(leading->_key, other._key) ? leading->_right : leading->_left;
	}
	other._parent = trailing;
	if ( key_compare(trailing->_key, other._key) )
		trailing->_right = &other;
	else
		trailing->_left = &other;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::transplant( BinarySearchTree* other )
{
	if (!_parent)
		;
	else if (this == _parent->_left)
		_parent->_left = other;
	else
		_parent->_right = other;
	if (other)
		other->_parent = _parent;
	_parent = NULL;
	return this;
}

template< typename Key, typename Compare >
BinarySearchTree< Key, void, Compare >*
BinarySearchTree< Key, void, Compare >::remove( void )
{
	BinarySearchTree* successor;

	if (!_left)
		transplant(_right);
	else if (!_right)
		transplant(_left);
	else
	{
		successor = minimum();
		if (successor->_parent != this)
		{
			successor->transplant(successor->_right);
			successor->_right = _right;
			successor->_right->_parent = successor;
		}
		transplant(successor);
		successor->_left = _left;
		successor->_left->_parent = successor;
	}
	return this;
}

template< typename Key, typename Compare >
Key
BinarySearchTree< Key, void, Compare >::get_key( void ) const
{
	return _key;
}

template< typename Key, typename Compare >
typename BinarySearchTree<Key, void, Compare>::indirection_type
BinarySearchTree<Key, void, Compare>::indirection( void )
{
	return &_key;
}

template< typename Key, typename Compare >
typename BinarySearchTree<Key, void, Compare>::member_of_pointer_type
BinarySearchTree<Key, void, Compare>::member_of_pointer( void )
{
	return &_key;
}

} // namespace ft