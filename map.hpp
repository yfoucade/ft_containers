/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:27:11 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/07 12:58:50 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <functional>
#include <memory>
#include <stdexcept>
#include "lexicographical_compare.hpp"
#include "RedBlackTree.hpp"
#include "iterator.hpp"
#include "pair.hpp"

// store a pointer to the root (BST** _root), and share its address with the iterator.
// This way a past-the-end iterator (because tree is empty), can be decremented after
// tree has been grown.
namespace ft
{

template<
	typename Key,
	typename T,
	typename Compare = std::less<Key>,
	typename Allocator = std::allocator<ft::pair<const Key, T> >
> class map{
	// member types
	private:
		typedef RedBlackTree<Key, ft::pair<const Key, T>, Compare> data_struct;
		typedef typename RedBlackTree<Key, ft::pair<const Key, T>, Compare>::node_type node_type;

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename data_struct::iterator iterator;
		typedef typename data_struct::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	// private members
	private:
		// now _rbt won't change during lifetime of map instance.
		// no need for pointer to pointer. just a pointer.
		data_struct *_rbt;
		key_compare _comp;
		allocator_type _alloc;
		size_type _size;
		size_type _required_alloc_size;
		void destroy_tree();
		size_type compute_ras( void );
		size_type erase_node( node_type* );

	// member classes
	public:
		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
			public:
				typedef typename std::binary_function<value_type, value_type, bool>::result_type result_type;

			protected:
				Compare comp;
				value_compare( Compare c );

			public:
				result_type operator()(const value_type& lhs, const value_type& rhs);
				friend class map;
		};

	// member functions
	public:
		// constructor, destructor, operator=, get_allocator
		map( void );
		explicit map( const Compare&, const Allocator& = Allocator() );
		template< typename InputIt >
		map( InputIt, InputIt, const Compare& = Compare(), const Allocator& = Allocator() );
		map( const map& other );
		~map( void );
		map& operator=( const map& other );
		allocator_type get_allocator( void ) const;
		// element access
		T& at( const Key& key );
		const T& at( const Key& key ) const;
		T& operator[]( const Key& key );
		// iterators
		iterator begin( void );
		const_iterator begin( void ) const;
		iterator end( void );
		const_iterator end( void ) const;
		reverse_iterator rbegin( void );
		const_reverse_iterator rbegin( void ) const;
		reverse_iterator rend( void );
		const_reverse_iterator rend( void ) const;
		// capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		// modifiers
		void clear();
		ft::pair<iterator, bool> insert( const value_type& value );
		iterator insert( iterator pos, const value_type& value );
		template< class InputIt >
		void insert( InputIt first, InputIt last );
		void erase( iterator pos );
		void erase( iterator first, iterator last );
		size_type erase( const Key& key );
		void swap( map& other );
		// lookup
		size_type count( const Key& key ) const;
		iterator find( const Key& key );
		const_iterator find( const Key& key ) const;
		ft::pair<iterator,iterator> equal_range( const Key& key );
		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		iterator lower_bound( const Key& key );
		const_iterator lower_bound( const Key& key ) const;
		iterator upper_bound( const Key& key );
		const_iterator upper_bound( const Key& key ) const;
		// observers
		key_compare key_comp() const;
		value_compare value_comp() const;
};

} // namespace ft

namespace ft
{

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::value_compare::value_compare( Compare c ): comp(c){}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::value_compare::result_type
map<Key, T, Compare, Allocator>::value_compare::operator()(
	const value_type& lhs, const value_type& rhs
){ return comp(lhs.first, rhs.first); }

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::map( void ):
_rbt(new data_struct),
_size(0),
_required_alloc_size(compute_ras())
{}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::map( const Compare& comp, const Allocator& alloc ):
_rbt(new data_struct), _comp(comp), _alloc(alloc),
_size(0), _required_alloc_size(compute_ras())
{}

template< typename Key, typename T, typename Compare, typename Allocator >
template< typename InputIt >
map<Key, T, Compare, Allocator>::map(
	InputIt first, InputIt last, const Compare& comp, const Allocator& alloc ):
_rbt(new data_struct), _comp(comp), _alloc(alloc),
_size(0), _required_alloc_size(compute_ras())
{
	insert(first, last);
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::map( const map& other ):
_rbt(new data_struct), _comp(other._comp), _alloc(other._alloc), _size(0)
{
	*this = other;
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::~map( void )
{
	destroy_tree();
	delete _rbt;
}

template< typename Key, typename T, typename Compare, typename Allocator >
void
map<Key, T, Compare, Allocator>::destroy_tree()
{
	node_type* tmp;
	if (!_rbt)
		return;
	// while (_rbt->get_root() != _rbt->get_nil())
	while (_size)
	{
		tmp = _rbt->get_root();
		erase_node(tmp);
	}
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>&
map<Key, T, Compare, Allocator>::operator=( const map& other )
{
	if (this == &other)
		return *this;
	destroy_tree();
	_comp = other._comp;
	_alloc = other._alloc;
	_size = 0;
	_required_alloc_size = other._required_alloc_size;
	const_iterator first = other.begin();
	const_iterator last = other.end();
	while (first != last)
		insert(*first++);
	return *this;
}

template< typename Key, typename T, typename Compare, typename Allocator >
Allocator
map<Key, T, Compare, Allocator>::get_allocator( void ) const
{
	return _alloc;
}



template< typename Key, typename T, typename Compare, typename Allocator >
T& map<Key, T, Compare, Allocator>::at( const Key& key )
{
	node_type* res = _rbt->search(key);
	if (!res)
		throw std::out_of_range("map::at");
	return res->value->second;
}

template< typename Key, typename T, typename Compare, typename Allocator >
const T& map<Key, T, Compare, Allocator>::at( const Key& key ) const
{
	node_type* res = _rbt->search(key);
	if (!res)
		throw std::out_of_range("map::at");
	return res->value->second;
}

template< typename Key, typename T, typename Compare, typename Allocator >
T& map<Key, T, Compare, Allocator>::operator[]( const Key& key )
{
	ft::pair<iterator, bool> ret = insert(ft::pair<const Key, T>(key, T()));
	return ret.first->second;
}


template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::begin( void )
{
	return iterator(_rbt, _rbt->minimum());
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::begin( void ) const
{
	return const_iterator(_rbt, _rbt->minimum());
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::end( void )
{
	return iterator(_rbt);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::end( void ) const
{
	return const_iterator(_rbt);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::reverse_iterator
map<Key, T, Compare, Allocator>::rbegin( void )
{
	return ft::reverse_iterator<iterator>(end());
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_reverse_iterator
map<Key, T, Compare, Allocator>::rbegin( void ) const
{
	return ft::reverse_iterator<const_iterator>(end());
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::reverse_iterator
map<Key, T, Compare, Allocator>::rend( void )
{
	return ft::reverse_iterator<iterator>(begin());
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_reverse_iterator
map<Key, T, Compare, Allocator>::rend( void ) const
{
	return ft::reverse_iterator<const_iterator>(begin());
}

template< typename Key, typename T, typename Compare, typename Allocator >
bool map<Key, T, Compare, Allocator>::empty( void ) const
{
	return _size == 0;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::size() const
{
	return _size;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::max_size() const
{
	return std::numeric_limits<difference_type>::max() / sizeof(data_struct);
}

template< typename Key, typename T, typename Compare, typename Allocator >
void map<Key, T, Compare, Allocator>::clear( void )
{
	destroy_tree();
	_size = 0;
}

template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>
map<Key, T, Compare, Allocator>::insert( const value_type& value )
{
	iterator it = find(value.first);
	if (it != end())
	{
		return ft::pair<iterator, bool>(it, false);
	}
	value_type* new_value = reinterpret_cast<value_type*>(_alloc.allocate(_required_alloc_size));
	// _alloc.construct(new_value, value);
	new((void *)new_value) value_type(value);
	node_type* node = new node_type(RED, value.first, new_value, NULL, NULL, NULL);
	_rbt->insert(node);
	++_size;
	return ft::pair<iterator, bool>(iterator(_rbt, node), true);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::insert( iterator pos, const value_type& value )
{
	static_cast<void>(pos);
	return insert(value).first;
}

template< typename Key, typename T, typename Compare, typename Allocator >
template< class InputIt >
void map<Key, T, Compare, Allocator>::insert( InputIt first, InputIt last )
{
	while (first != last)
		insert(*first++);
}


template< typename Key, typename T, typename Compare, typename Allocator >
void map<Key, T, Compare, Allocator>::erase( iterator pos )
{
	erase_node(pos.get_node());
}

template< typename Key, typename T, typename Compare, typename Allocator >
void map<Key, T, Compare, Allocator>::erase( iterator first, iterator last )
{
	while (first != last)
	{
		erase_node(first++.get_node());
		// --_size;
	}
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::erase( const Key& key )
{
	node_type* node = _rbt->search(key);
	return erase_node(node);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::erase_node( node_type* node )
{
	if (!node)
		return 0;
	_rbt->remove(node);
	node->value->~value_type();
	_alloc.deallocate(reinterpret_cast<typename Allocator::pointer>(node->value), _required_alloc_size);
	delete node;
	--_size;
	return 1;
}

template< typename Key, typename T, typename Compare, typename Allocator >
void map<Key, T, Compare, Allocator>::swap( map& other )
{
	data_struct* tmp_rbt = _rbt;
	key_compare tmp_comp = _comp;
	allocator_type tmp_alloc = _alloc;
	size_type tmp_size = _size;
	size_type tmp_required_alloc_size = _required_alloc_size;
	
	_rbt = other._rbt;
	_comp = other._comp;
	_alloc = other._alloc;
	_size = other._size;
	_required_alloc_size = other._required_alloc_size;

	other._rbt = tmp_rbt;
	other._comp = tmp_comp;
	other._alloc = tmp_alloc;
	other._size = tmp_size;
	other._required_alloc_size = tmp_required_alloc_size;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::count( const Key& key ) const
{
	if ( _rbt->search(key) )
		return 1;
	return 0;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::find( const Key& key )
{
	return iterator(_rbt, _rbt->search(key) );
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::find( const Key& key ) const
{
	return const_iterator(_rbt, _rbt->search(key) );
}


template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator>
map<Key, T, Compare, Allocator>::equal_range( const Key& key )
{
	return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator >
map<Key, T, Compare, Allocator>::equal_range( const Key& key ) const
{
	return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
}


template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::lower_bound( const Key& key )
{
	iterator ret = end();
	node_type* tmp = _rbt->get_root();
	while ( tmp != _rbt->get_nil() )
	{
		if ( _comp(tmp->value->first, key) )
			tmp = tmp->right;
		else if ( _comp(key, tmp->value->first) )
		{
			if ( ret == end() || _comp(tmp->value->first, ret->first) )
				ret = iterator(_rbt, tmp);
			tmp = tmp->left;
		}
		else
			return iterator(_rbt, tmp);
	}
	return ret;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::lower_bound( const Key& key ) const
{
	const_iterator ret = end();
	node_type* tmp = _rbt->get_root();
	while ( tmp != _rbt->get_nil() )
	{
		if ( _comp(tmp->value->first, key) )
			tmp = tmp->right;
		else if ( _comp(key, tmp->value->first) )
		{
			if ( ret == end() || _comp(tmp->value->first, ret->first) )
				ret = const_iterator(_rbt, tmp);
			tmp = tmp->left;
		}
		else
			return const_iterator(_rbt, tmp);
	}
	return ret;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::upper_bound( const Key& key )
{
	iterator ret = end();
	node_type* tmp = _rbt->get_root();
	while ( tmp != _rbt->get_nil() )
	{
		if ( _comp(key, tmp->value->first) )
		{
			if ( ret == end() || _comp(tmp->value->first, ret->first) )
				ret = iterator(_rbt, tmp);
			tmp = tmp->left;
		}
		else
			tmp = tmp->right;
	}
	return ret;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::upper_bound( const Key& key ) const
{
	const_iterator ret = end();
	node_type* tmp = _rbt->get_root();
	while ( tmp != _rbt->get_nil() )
	{
		if ( _comp(key, tmp->value->first) )
		{
			if ( ret == end() || _comp(tmp->value->first, ret->first) )
				ret = const_iterator(_rbt, tmp);
			tmp = tmp->left;
		}
		else
			tmp = tmp->right;
	}
	return ret;
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::key_compare
map<Key, T, Compare, Allocator>::key_comp() const
{
	return key_compare(_comp);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::value_compare
map<Key, T, Compare, Allocator>::value_comp() const
{
	map<Key, T, Compare, Allocator>::value_compare res(key_comp());
	return res;
}

} // namespace ft

namespace ft
{

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::compute_ras( void )
{
	size_type alloc_size = sizeof(typename Allocator::value_type);
	size_type target = sizeof(value_type);
	if (alloc_size >= target)
		return 1;
	size_type n_elem = target / alloc_size;
	if (n_elem * alloc_size == target)
		return n_elem;
	return n_elem + 1;
}

} // namespace ft

namespace ft
{
// non-member functions

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	typename map<Key,T,Compare,Alloc>::const_iterator l1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator l2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last = lhs.end();
	
	if ( lhs.size() != rhs.size() )
		return false;
	while ( l1 != last )
	{
		if ( (l1->first != l2->first) || (l1->second != l2->second) )
			return false;
		++l1;
		++l2;
	}
	return true;
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs == rhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
{
	typename map<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename map<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
	return ft::lexicographical_compare(first1, last1, first2, last2);
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
}

template< class Key, class T, class Compare, class Alloc >
void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
