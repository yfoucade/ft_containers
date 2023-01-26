/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:00:15 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/26 19:19:05 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template< typename T1, typename T2 >
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair( void );
	pair( const T1& x, const T2& y );
	template< class U1, class U2 >
	pair( const pair<U1, U2>& p );
	pair& operator=( const pair& other );
};

template< typename T1, typename T2 >
pair<T1, T2>::pair( void ): first(T1()), second(T2()){}

template< typename T1, typename T2 >
pair<T1, T2>::pair( const T1& x, const T2& y ): first(T1(x)), second(T2(y)){}

template< typename T1, typename T2 >
template< typename U1, typename U2 >
pair<T1, T2>::pair( const pair<U1, U2>& p ): first(T1(p.first)), second(T2(p.second)){}

template< typename T1, typename T2 >
pair<T1, T2>& pair<T1, T2>::operator=( const pair& other )
{
	if (this == &other)
		return *this;
	first.~T1();
	second.~T2();
	first = T1(other.first);
	second = T2(other.second);
	return *this;
}

} // namespace ft

namespace ft
{

template< class T1, class T2 >
bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template< class T1, class T2 >
bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	return !(lhs == rhs);
}

template< class T1, class T2 >
bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	if (lhs.first < rhs.first)
		return true;
	if (rhs.first < lhs.first)
		return false;
	if (lhs.second < rhs.second)
		return true;
	return false;
}

template< class T1, class T2 >
bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	return !(rhs < lhs);
}

template< class T1, class T2 >
bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	return (rhs < lhs);
}

template< class T1, class T2 >
bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
	return !(lhs < rhs);
}

template< class T1, class T2 >
ft::pair<T1, T2> make_pair( T1 t, T2 u )
{
	return ft::pair<T1, T2>(t, u);
}

} // namespace ft