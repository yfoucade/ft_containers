/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:17:24 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/17 04:35:14 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template< class T, T v >
struct integral_constant
{
	typedef T value_type;
	typedef struct integral_constant<T, v> type;
	static const T value = v;
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template< typename T >
struct is_integral: false_type
{};

template<>
struct is_integral<bool>: true_type
{};

template<>
struct is_integral<char>: true_type
{};

template<>
struct is_integral<wchar_t>: true_type
{};

template<>
struct is_integral<short>: true_type
{};

template<>
struct is_integral<int>: true_type
{};

template<>
struct is_integral<long>: true_type
{};

template<>
struct is_integral<long long>: true_type
{};


} // namespace ft