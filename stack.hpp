/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:39:06 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/02 12:16:40 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

namespace ft
{

template< class T, class Container = ft::vector<T> >
class stack{
public:
	typedef Container container_type;
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef typename Container::reference reference;
	typedef typename Container::const_reference const_reference;

public:
	Container c;

public:
	explicit stack( const Container& cont = Container() );
	stack( const stack& other );
	~stack();
	stack& operator=( const stack& other );
	reference top();
	const_reference top() const;
	bool empty() const;
	size_type size() const;
	void push( const value_type& value );
	void pop();
};

template< class T, class Container >
stack<T, Container>::stack( const Container& cont ): c(cont){}

template< class T, class Container >
stack<T, Container>::stack( const stack& other ): c(other.c){}

template< class T, class Container >
stack<T, Container>::~stack(){}

template< class T, class Container >
stack<T, Container>& stack<T, Container>::operator=( const stack& other )
{
	if (this == &other)
		return *this;
	c = other.c;
	return *this;
}

template< class T, class Container >
typename stack<T, Container>::reference
stack<T, Container>::top()
{
	return c.back();
}

template< class T, class Container >
typename stack<T, Container>::const_reference
stack<T, Container>::top() const
{
	return c.back();
}

template< class T, class Container >
bool stack<T, Container>::empty() const
{
	return c.empty();
}

template< class T, class Container >
typename stack<T, Container>::size_type
stack<T, Container>::size() const
{
	return c.size();
}

template< class T, class Container >
void stack<T, Container>::push( const value_type& value )
{
	c.push_back(value);
}

template< class T, class Container >
void stack<T, Container>::pop()
{
	c.pop_back();
}

} // namespace ft

// non-member functions
namespace ft
{
	
template< class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c == rhs.c;
}

template< class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c != rhs.c;
}

template< class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c < rhs.c;
}

template< class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c <= rhs.c;
}

template< class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c > rhs.c;
}

template< class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c >= rhs.c;
}


} // namespace ft