/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:27:11 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/23 14:29:37 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include "BinarySearchTree.hpp"
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
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename BinarySearchTree<Key, value_type, Compare>::iterator iterator;
		typedef typename BinarySearchTree<Key, value_type, Compare>::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	// private members
	private:
		BinarySearchTree** _bst;
		key_compare _comp;
		allocator_type _alloc;
		size_type _size;
		size_type _required_alloc_size;
		void destroy_tree(BinarySearchTree<Key, value_type, Compare>* bst);
		size_type compute_ras( void );

	// member classes
	public:
		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
			public:
				typedef result_type;

			protected:
				Compare comp;
				value_compare( Compare c );

			public:
				result_type operator()(const value_type& lhs, const value_type& rhs);
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
		// lookup
		// observers
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
_bst(new BinarySearchTree<Key, value_type, Compare>*), _size(0),
_required_alloc_size(compute_ras())
{ *_bst = NULL; }

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::map( const Compare& comp, const Allocator& alloc ):
_bst(new BinarySearchTree<Key, value_type, Compare>*), _comp(comp), _alloc(alloc),
_size(0), _required_alloc_size(compute_ras())
{ *_bst = NULL; }

template< typename Key, typename T, typename Compare, typename Allocator >
template< typename InputIt >
map<Key, T, Compare, Allocator>::map(
	InputIt first, InputIt last, const Compare& comp, const Allocator& alloc ):
_bst(new BinarySearchTree<Key, value_type, Compare>*), _comp(comp), _alloc(alloc),
_size(0), _required_alloc_size(compute_ras())
{
	*_bst = NULL;
	insert(first, last);
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::map( const map& other ):
_bst(new BinarySearchTree<Key, value_type, Compare>*), _comp(other._comp), _alloc(other._alloc), _size(0)
{
	*_bst = NULL;
	*this = other;
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>::~map( void )
{
	destroy_tree(*_bst);
	*_bst = NULL;
}

template< typename Key, typename T, typename Compare, typename Allocator >
void
map<Key, T, Compare, Allocator>::destroy_tree( BinarySearchTree<Key, value_type, Compare>* bst )
{
	if (bst)
	{
		destroy_tree(bst->get_left());
		destroy_tree(bst->get_right());
		bst->get_value()->~value_type();
		_alloc->deallocate(bst->get_value(), _required_alloc_size);
		delete bst;
		--_size;
	}
}

template< typename Key, typename T, typename Compare, typename Allocator >
map<Key, T, Compare, Allocator>&
map<Key, T, Compare, Allocator>::operator=( const map& other )
{
	if (this == &other)
		return *this;
	~map();
	_comp = other._comp;
	_alloc = other._alloc;
	_size = 0;
	_required_alloc_size = other._required_alloc_size;
	value_type* tmp;
	iterator first = other.begin();
	iterator last = other.end();
	while (first != last)
	{
		tmp = reinterpret_cast<value_type*>(_alloc.allocate(_required_alloc_size));
		tmp = *first;
		insert(*tmp);
		++first;
	}
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
	BinarySearchTree<Key, value_type, Compare>* res = (*_bst).find(key);
	if (!res)
		throw std::out_of_range("Key <key> not found in map\n");
	return res->get_value()->second;
}

template< typename Key, typename T, typename Compare, typename Allocator >
const T& map<Key, T, Compare, Allocator>::at( const Key& key ) const
{
	BinarySearchTree<Key, value_type, Compare>* res = *_bst.find(key);
	if (!res)
		throw std::out_of_range("Key <key> not found in map\n");
	return res->get_value()->second;
}

template< typename Key, typename T, typename Compare, typename Allocator >
T& map<Key, T, Compare, Allocator>::operator[]( const Key& key )
{
	ft::pair<iterator, bool> ret = insert(ft::pair<key, T()>);
	return ret.first->second;
}


template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::begin( void )
{
	return iterator(_bst);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::begin( void ) const
{
	return iterator(_bst);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::end( void )
{
	if (*_bst)
		return ++iterator(*_bst.maximum());
	return iterator(_bst);
}

template< typename Key, typename T, typename Compare, typename Allocator >
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::end( void ) const
{
	if (*_bst)
		return ++iterator(*_bst.maximum());
	return iterator(_bst);
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
	return std::numeric_limits<difference_type>::max() / sizeof(value_type);
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