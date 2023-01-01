/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:25:25 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/01 22:32:36 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include <limits>

namespace ft{

template < typename T, typename Allocator = std::allocator<T> >
class vector{
	private:
		Allocator _allocator;
		std::size_t _size;
		std::size_t _capacity;
		T* _tab;

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		// constructor, destructor, operator=, assign, get_allocator
		vector( void );
		explicit vector( const Allocator& alloc );
		explicit vector(	size_type count,
							const T& value = value_type(),
							const Allocator& alloc = allocator_type());
		template< typename InputIt >
		vector(	InputIt,
				typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type,
				const allocator_type& = allocator_type());
		vector( const vector& other );
		vector& operator=( const vector& other );
		~vector( void );
		void assign( size_type count, const T& value );
		template< class InputIt >
		void assign( InputIt first, InputIt last );
		allocator_type get_allocator() const;

		// element access
		reference at( size_type pos );
		const_reference at( size_type pos ) const;
		reference operator[]( size_type pos );
		const_reference operator[]( size_type pos ) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		T* data();
		const T* data() const;

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
		void reserve( size_type new_cap );
		size_type capacity() const;

		// modifiers
		void clear();
		iterator insert( const_iterator pos, const T& value );
		iterator insert( const_iterator pos, size_type count, const T& value );
		template< class InputIt >
		iterator insert( const_iterator pos, InputIt first, InputIt last );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		void push_back( const T& value );
		void pop_back();
		void resize( size_type count );
		void swap( vector& other );
};

template < typename T, typename Allocator >
vector<T, Allocator>::vector( void ):_size(0), _tab(_allocator.allocate(0)){}

template < typename T, typename Allocator >
vector<T, Allocator>::vector( const allocator_type& alloc ):
			_allocator(alloc),
			_size(0),
			_capacity(0),
			_tab(_allocator.allocate(0)){}

template < typename T, typename Allocator >
vector<T, Allocator>::vector(
	size_type count,
	const value_type& value,
	const allocator_type& alloc):
	_allocator(alloc),
	_size(count),
	_capacity(count),
	_tab(_allocator.allocate(_capacity))
{
	for (size_type i = 0; i < count; i++)
		_tab[i] = T(value);
}

template< typename T, typename Allocator >
template< typename InputIt >
vector<T, Allocator>::vector( InputIt first,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last,
		const allocator_type& alloc ):
	_allocator(alloc)
	{
		_size = last - first;
		_capacity = _size;
		_tab = _allocator.allocate(_capacity);
		for (InputIt tmp = first; tmp!= last; tmp++)
			_tab[tmp - first] = T(*tmp);
	}

template< typename T, typename Allocator >
vector<T, Allocator>::vector( const vector& other ):
_tab(_allocator.allocate(0))
{
	std::cout << "Called copy constructor" << std::endl;
	*this = other;
}

template< typename T, typename Allocator >
vector<T, Allocator>& vector<T, Allocator>::operator=( const vector& other )
{
	std::cout << "Called assignment operator" << std::endl;
	if ( this == &other )
		return *this;
	delete _tab;
	_allocator = other._allocator;
	_size = other._size;
	_capacity = other._capacity;
	_tab = _allocator.allocate(_capacity);
	const_iterator start = other.begin();
	const_iterator it;
	const_iterator end = other.end();
	for ( it = start; it < end; it++ )
		_tab[it - start] = *it;
	return *this;
}

template< typename T, typename Allocator >
vector<T, Allocator>::~vector( void )
{
	delete _tab;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::assign( size_type count, const T& value )
{
	if (_capacity < count)
	{
		delete _tab;
		_capacity = count;
		_tab = _allocator.allocate(_capacity);
	}
	_size = count;
	for (int i = 0; i < count; ++i)
		_tab[i] = T(value);
}

template< typename T, typename Allocator >
template< class InputIt >
void vector<T, Allocator>::assign( InputIt first, InputIt last )
{
	if (_capacity < last - first)
	{
		delete _tab;
		_capacity = last - first;
		_tab = _allocator.allocate(_capacity);
	}
	_size = last - first;
	for (InputIt tmp = first; tmp < last; ++tmp)
		_tab[tmp - first] = T(*tmp);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator( void ) const
{
	return _allocator;
}


template< typename T, typename Allocator >
typename vector<T, Allocator>::reference vector<T, Allocator>::at( size_type pos )
{
	if (!(pos < size()))
		throw (std::out_of_range());
	return _tab + pos;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at( size_type pos ) const
{
	if (!(pos < size()))
		throw (std::out_of_range());
	return _tab + pos;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[]( size_type pos )
{
	return _tab + pos;
}
template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[]( size_type pos ) const
{
	return _tab + pos;
}

template< typename T, typename Allocator >
typename vector<T, Allocator >::reference vector<T, Allocator>::front( void )
{
	return _tab;
}
template< typename T, typename Allocator >
typename vector<T, Allocator >::const_reference vector<T, Allocator>::front( void ) const
{
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reference vector<T, Allocator>::back()
{
	return _tab + _size - 1;
}
template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
{
	return _tab + _size - 1;
}

template< typename T, typename Allocator >
T* vector<T, Allocator>::data()
{
	if (!_size)
		return NULL;
	return _tab;
}
template< typename T, typename Allocator >
const T* vector<T, Allocator>::data() const
{
	if (!_size)
		return NULL;
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin( void )
{
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin( void ) const
{
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::end( void )
{
	return _tab + _size;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end( void ) const
{
	return _tab + _size;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin( void )
{
	return _tab + _size;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin( void ) const
{
	return _tab + _size;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend( void )
{
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend( void ) const
{
	return _tab;
}

template< typename T, typename Allocator >
bool vector<T, Allocator>::empty() const
{
	return (_size == 0);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
{
	return _size;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
{
	return std::numeric_limits<difference_type>::max();
}

template< typename T, typename Allocator >
void vector<T, Allocator>::reserve( size_type new_cap )
{
	if (new_cap > max_size())
		throw (std::length_error());
	if (new_cap <= _capacity)
		return;
	T* tmp = _allocator.allocate(new_cap);
	_capacity = new_cap;
	iterator start = begin();
	iterator end = end();
	for (iterator it = start; it < end; ++it)
		tmp[it - start] = T(*it);
	delete _tab;
	_tab = tmp;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
{
	return _capacity;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::clear()
{
	for (int i = 0; i < _size; ++i)
		_tab[i].~T();
	_size = 0;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( const_iterator pos, const T& value )
{
	return insert(pos, 1, value);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( const_iterator pos, size_type count, const T& value )
{
	if (!count)
		return pos;
	reserve(_size + count);
	T* start = _tab[_size - 1];
	T* it = start;
	T* end = _tab[pos - 1];
	for (; it != end; --it)
		it[count] = *it;
	for (int i = 0; i < count; ++i)
		_tab[i + pos] = T(value);
	return _tab + pos;
}

template< typename T, typename Allocator >
template< class InputIt >
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( const_iterator pos, InputIt first, InputIt last )
{
	if (last == first)
		return pos;
	size_type count = static_cast<size_type>(last - first);
	reserve(_size + count);
	T* start = _tab[_size - 1];
	T* it = start;
	T* end = _tab[pos - 1];
	for (; it != end; --it)
		it[count] = *it;
	for (InputIt it = start; it != end; ++it)
		_tab[pos + (it - start)] = T(*it);
	return _tab + pos;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator pos )
{
	_tab[pos].~T();
	--_size;
	iterator it = pos;
	iterator ret = it;
	iterator end = end();
	while (++it != end)
		*pos++ = *it;
	return ret;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator first, iterator last )
{
	if (first == last)
		return last;
	iterator it = first;
	iterator ret = it;
	iterator end = end();
	while (it != last)
	{
		it++->~T();
		--_size;
	}
	it = first;
	while (last != end)
		*it++ = *last++;
	return ret;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::push_back( const T& value )
{
	reserve(_size + 1);
	_tab[++_size] = value;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::pop_back()
{
	_tab[_size - 1].~T();
	--_size;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::resize( size_type count )
{
	reserve(count);
	if (_size < count)
	{
		for (size_type i = _size; i < count; ++i)
			_tab[i] = T();
	}
	else
	{
		for (size_type i = count; i < _size; ++i)
			_tab[i].~T();
	}
	_size = count;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::swap( vector& other )
{
	allocator_type tmp_allocator = _allocator;
	size_type tmp_size = _size, tmp_capacity = _capacity;
	T* tmp_tab = _tab;

	_allocator = other._allocator;
	_size = other._size;
	_capacity = other._capacity;
	_tab = other._tab;

	other._allocator = tmp_allocator;
	other._size = tmp_size;
	other._capacity = tmp_capacity;
	other._tab = tmp_tab;
}

} // namespace ft

namespace ft
{

template< class T, class Alloc >
bool operator==(	const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs )
{
	typename vector<T, Alloc>::iterator first1 = lhs.begin(), last1 = lhs.end();
	typename vector<T, Alloc>::iterator first2 = rhs.begin(), last2 = rhs.end();

	if (lhs.size() != rhs.size())
		return false;
	while ((first1 != last1) && (first2 != last2))
		if (*first1++ != *first2++)
			return false;
	return (first1 == last1) && (first2 == last2);
}

template< class T, class Alloc >
bool operator!=(	const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs )
{
	return !(lhs == rhs);
}

template< class T, class Alloc >
bool operator<(	const std::vector<T,Alloc>& lhs,
				const std::vector<T,Alloc>& rhs )
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class T, class Alloc >
bool operator<=(	const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs )
{
	return !(rhs < lhs);
}

template< class T, class Alloc >
bool operator>(	const std::vector<T,Alloc>& lhs,
				const std::vector<T,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class T, class Alloc >
bool operator>=(	const std::vector<T,Alloc>& lhs,
					const std::vector<T,Alloc>& rhs )
{
	return !(lhs < rhs);
}

template< class T, class Alloc >
void swap(	std::vector<T,Alloc>& lhs,
			std::vector<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft