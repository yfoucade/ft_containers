/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:25:25 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/01 15:34:16 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <memory>
#include <cstdio>
#include <cstring>
#include <string>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"

namespace ft{

template < typename T, typename Allocator = std::allocator<T> >
class vector{
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

	private:
		Allocator _allocator;
		std::size_t _size;
		std::size_t _capacity;
		T* _tab;
		T* allocate_capacity(std::size_t target);
		std::size_t get_alloc_size( std::size_t capacity ) const;
		void	destroy_tab_elements( void );
		std::string	out_of_range_string( std::size_t pos ) const;
		void	shift( std::size_t idx, std::size_t count );
		void assign_specialization( size_type count, const T& value, ft::true_type );
		template< class InputIt >
		void assign_specialization( InputIt first, InputIt last, ft::false_type );
		void len_check( size_type n );

	public:
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
		iterator insert(
			const_iterator pos,
			typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
			InputIt last );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		void push_back( const T& value );
		void pop_back();
		void resize( size_type count, T value = T() );
		void swap( vector& other );
};

template < typename T, typename Allocator >
vector<T, Allocator>::vector( void ):_size(0), _capacity(0), _tab(NULL){}

template < typename T, typename Allocator >
vector<T, Allocator>::vector( const Allocator& alloc ):
_allocator(alloc),
_size(0),
_capacity(0),
_tab(NULL)
{}

template < typename T, typename Allocator >
vector<T, Allocator>::vector(
	size_type count,
	const value_type& value,
	const allocator_type& alloc):
_allocator(alloc),
_size(count),
_capacity(count),
_tab(allocate_capacity(_capacity))
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
	_tab = allocate_capacity(_capacity);
	for (InputIt tmp = first; tmp!= last; tmp++)
		_tab[tmp - first] = *tmp;
}

template< typename T, typename Allocator >
vector<T, Allocator>::vector( const vector& other ):
_allocator(other._allocator),
_size(other._size),
_capacity(other._size),
_tab(NULL)
{
	_tab = allocate_capacity(_capacity);
	const_iterator first = other.begin();
	const_iterator it;
	const_iterator last = other.end();
	for ( it = first; it < last; it++ )
		_tab[it - first] = *it;
}

template< typename T, typename Allocator >
vector<T, Allocator>& vector<T, Allocator>::operator=( const vector& other )
{
	if ( this == &other )
		return *this;
	if (_capacity < other._size)
	{
		this->~vector();
		_allocator = other._allocator;
		_size = other._size;
		_capacity = other._capacity;
		_tab = allocate_capacity(_capacity);
	}
	else
	{
		destroy_tab_elements();
		_allocator = other._allocator;
		_size = other._size;
	}
	const_iterator first = other.begin();
	const_iterator it;
	const_iterator last = other.end();
	for ( it = first; it < last; it++ )
		_tab[it - first] = *it;
	return *this;
}

template< typename T, typename Allocator >
vector<T, Allocator>::~vector( void )
{
	if (!_tab)
		return;
	destroy_tab_elements();
	_allocator.deallocate(
		reinterpret_cast<typename Allocator::pointer>(_tab),
		get_alloc_size(_capacity));
}

template< typename T, typename Allocator >
void vector<T, Allocator>::assign_specialization( size_type count, const T& value, ft::true_type )
{
	destroy_tab_elements();
	len_check(count);
	_size = count;
	for (size_type i = 0; i < count; ++i)
		_tab[i] = value;
}

template< typename T, typename Allocator >
template< class InputIt >
void vector<T, Allocator>::assign_specialization( InputIt first, InputIt last, ft::false_type )
{
	if (_capacity < static_cast<size_type>(last - first))
	{
		T* tmp = allocate_capacity(last - first);
		for (InputIt it = first; it != last; ++it)
			tmp[it - first] = *it;
		destroy_tab_elements();
		_allocator.deallocate(
			reinterpret_cast<typename Allocator::pointer>(_tab),
			get_alloc_size(_capacity));
		_tab = tmp;
		_capacity = last - first;
		_size = last - first;
	}
	else
	{
		InputIt it = first;
		for ( ; it != last; ++it)
			_tab[it - first] = *it;
		for ( ; static_cast<size_type>(it - first) < _size; ++it)
			_tab[it - first].T::~T();
		_size = last - first;
	}
}

template< typename T, typename Allocator >
void vector<T, Allocator>::assign( size_type count, const T& value )
{
	destroy_tab_elements();
	len_check(count);
	_size = count;
	for (size_type i = 0; i < count; ++i)
		_tab[i] = value;
}

template< typename T, typename Allocator >
template< class InputIt >
void vector<T, Allocator>::assign( InputIt first, InputIt last )
{
	assign_specialization( first, last, typename ft::is_integral<InputIt>::type() );
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
		throw (std::out_of_range(out_of_range_string(pos)));
	return *(_tab + pos);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at( size_type pos ) const
{
	if (!(pos < size()))
		throw (std::out_of_range(out_of_range_string(pos)));
	return *(_tab + pos);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[]( size_type pos )
{
	return *(_tab + pos);
}
template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[]( size_type pos ) const
{
	return *(_tab + pos);
}

template< typename T, typename Allocator >
typename vector<T, Allocator >::reference vector<T, Allocator>::front( void )
{
	return *(_tab);
}
template< typename T, typename Allocator >
typename vector<T, Allocator >::const_reference vector<T, Allocator>::front( void ) const
{
	return *(_tab);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reference vector<T, Allocator>::back()
{
	return *(_tab + _size - 1);
}
template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
{
	return *(_tab + _size - 1);
}

template< typename T, typename Allocator >
T* vector<T, Allocator>::data()
{
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
	return ft::reverse_iterator<iterator>(_tab + _size);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin( void ) const
{
	return ft::reverse_iterator<const_iterator>(_tab + _size);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend( void )
{
	return ft::reverse_iterator<iterator>(_tab);
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend( void ) const
{
	return ft::reverse_iterator<const_iterator>(_tab);
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
	return std::numeric_limits<difference_type>::max() / sizeof(T);
}

template< typename T, typename Allocator >
void vector<T, Allocator>::reserve( size_type new_cap )
{
	if (new_cap > max_size())
		throw (std::length_error("vector::reserve"));
	if (new_cap <= _capacity)
		return;
	// new_cap = (new_cap >= (max_size() >> 1) ? max_size() : 2 * new_cap);
	// if ( (_capacity << 1) > new_cap)
		// new_cap = 2 * _capacity;
	T* tmp = (allocate_capacity(new_cap));
	iterator first = begin();
	iterator last = end();
	for (iterator it = first; it < last; ++it)
		tmp[it - first] = *it;
	this->~vector();
	_capacity = new_cap;
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
	destroy_tab_elements();
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
	if ( ( _tab && !pos ) || ( !_tab && pos ) || !count)
		return const_cast<iterator>(pos);
	size_type idx = !pos ? 0 : static_cast< size_type >( pos - begin() );
	len_check(count);
	shift(idx, count);
	for (size_type i = 0; i < count; ++i)
		_tab[idx + i] = value;
	_size += count;
	return _tab + idx;
}

template< typename T, typename Allocator >
template< class InputIt >
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(
	const_iterator pos,
	typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
	InputIt last )
{
	if ( ( _tab && !pos ) || ( !_tab && pos ) || last == first)
		return const_cast<iterator>(pos);
	size_type count = static_cast<size_type>(last - first);
	size_type idx = !pos ? 0 : static_cast< size_type >( pos - begin() );
	len_check(count);
	shift(idx, count);
	for (InputIt it = first; it != last; ++it)
		_tab[idx + (it - first)] = *it;
	_size += count;
	return _tab + idx;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator pos )
{
	pos->T::~T();
	iterator it = pos;
	iterator ret = it;
	iterator last = end();
	--_size;
	while (++it != last)
	{
		new(pos++) value_type(*it);
		it->T::~T();
	}
	return ret;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator first, iterator last )
{
	if (first == last)
		return last;
	iterator it = first;
	iterator ret = it;
	iterator finish = end();
	while (it != last)
	{
		it++->T::~T();
		--_size;
	}
	it = first;
	while (last != finish)
	{
		new(it++) value_type(*last);
		last++->T::~T();
	}
	return ret;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::push_back( const T& value )
{
	len_check(1);
	_tab[_size++] = value;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::pop_back()
{
	if (!_size)
		return ;
	_tab[_size - 1].T::~T();
	--_size;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::resize( size_type count, T value )
{
	if (count > _size)
		len_check(count - _size);
	if (_size < count)
	{
		for (size_type i = _size; i < count; ++i)
			_tab[i] = value;
	}
	else
	{
		for (size_type i = count; i < _size; ++i)
			_tab[i].T::~T();
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

// private member functions
namespace ft
{

template< typename T, typename Allocator >
T* vector<T, Allocator>::allocate_capacity( std::size_t target_capacity )
{
	/*
	Args:
		target_capacity: the number of type T objects we want to be able to store.
	Returns:
		T*: a pointer to the start of the allocated array.
	*/
	if (target_capacity == 0)
		return NULL;
	size_type n_elem = get_alloc_size(target_capacity);
	T* ret = reinterpret_cast<T*>(_allocator.allocate(n_elem));
	std::memset(reinterpret_cast<void*>(ret), 0, n_elem * sizeof(typename Allocator::value_type));
	return ret;
}

template< typename T, typename Allocator >
std::size_t vector<T, Allocator>::get_alloc_size( std::size_t capacity ) const
{
	size_type required_size = capacity * sizeof(T);
	size_type n_elem = required_size / sizeof(typename Allocator::value_type);
	if (n_elem * sizeof(typename Allocator::value_type) < required_size)
		++n_elem;
	return n_elem;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::destroy_tab_elements( void )
{
	iterator	first = begin();
	iterator	last = end();

	for ( ; first != last; ++first )
		first->T::~T();
	std::memset(
		reinterpret_cast<void*>(_tab),
		0,
		get_alloc_size(_capacity) * sizeof(typename Allocator::value_type));
}

template< typename T, typename Allocator >
void	vector< T, Allocator >::shift(size_type idx, size_type count)
{
	// reserve(_size + count);
	size_type i = end() - begin();
	for ( ; i > idx; --i )
		_tab[i + count - 1] = _tab[i - 1];
}

template< typename T, typename Allocator >
std::string vector<T, Allocator>::out_of_range_string( size_type pos ) const
{
	char	buffer[100];
	int		ret;

	ret = sprintf(
		buffer,
		"vector: out of range exception. pos (which is %lu) >= this->size() (which is %lu)",
		pos,
		size()
	);
	if (ret < 0)
		return std::string("Out of range exception");
	return buffer;
}

template< typename T, typename Allocator >
void vector<T, Allocator>::len_check( size_type n )
{
	if (max_size() - _size < n)
		throw (std::length_error("vector::len_check"));
	if (_size + n <= _capacity || !n)
		return;
	size_type len = _size + ( (_size > n) ? _size : n );
	reserve( (len < _size || len > max_size()) ? max_size() : len );
}

} // namespace ft

namespace ft
{

template< class T, class Alloc >
bool operator==(	const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
{
	typename vector<T, Alloc>::const_iterator first1 = lhs.begin(), last1 = lhs.end();
	typename vector<T, Alloc>::const_iterator first2 = rhs.begin();

	if (lhs.size() != rhs.size())
		return false;
	while (first1 != last1)
		if (*first1++ != *first2++)
			return false;
	return true;
}

template< class T, class Alloc >
bool operator!=(	const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
{
	return !(lhs == rhs);
}

template< class T, class Alloc >
bool operator<(	const ft::vector<T,Alloc>& lhs,
				const ft::vector<T,Alloc>& rhs )
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class T, class Alloc >
bool operator<=(	const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
{
	return !(rhs < lhs);
}

template< class T, class Alloc >
bool operator>(	const ft::vector<T,Alloc>& lhs,
				const ft::vector<T,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class T, class Alloc >
bool operator>=(	const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs )
{
	return !(lhs < rhs);
}

template< class T, class Alloc >
void swap(	ft::vector<T,Alloc>& lhs,
			ft::vector<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
