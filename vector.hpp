/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:25:25 by yfoucade          #+#    #+#             */
/*   Updated: 2022/12/29 23:12:09 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <type_traits> /* To be removed */

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
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		vector( void );
		explicit vector( const Allocator& alloc );
		explicit vector(	size_type count,
							const T& value = value_type(),
							const Allocator& alloc = allocator_type());
		template< typename InputIt, typename = typename std::enable_if<!std::is_integral<InputIt>::value, T>::type >
		// template< typename InputIt >
		vector(	InputIt first,
				InputIt last,
				const allocator_type& alloc = allocator_type()):
			_allocator(alloc)
			{
					_size = last - first;
					_capacity = _size;
					_tab = _allocator.allocate(_capacity);
					for (InputIt tmp = first; tmp!= last; tmp++)
						_tab[tmp - first] = static_cast<value_type>(*tmp);
			}
		vector( const vector& other );
		vector& operator=( const vector& other );
		~vector( void );
		iterator begin( void ) const;
		iterator end( void ) const;
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
		_tab[i] = value;
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
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin( void ) const
{
	return _tab;
}

template< typename T, typename Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::end( void ) const
{
	return _tab + _size;
}

}


namespace ft
{
	template< class Iter >
	struct iterator_traits{
		typedef Iter::difference_type difference_type;
		typedef Iter::value_type value_type;
		typedef Iter::pointer pointer;
		typedef Iter::reference reference;
		typedef Iter::iterator_category iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}