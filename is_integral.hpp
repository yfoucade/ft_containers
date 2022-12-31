/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:17:24 by yfoucade          #+#    #+#             */
/*   Updated: 2022/12/31 21:37:35 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template< typename T >
struct is_integral
{
	static const bool value = false;
};

template<>
struct is_integral<bool>
{
	static const bool value = true;
};

template<>
struct is_integral<char>
{
	static const bool value = true;
};

template<>
struct is_integral<wchar_t>
{
	static const bool value = true;
};

template<>
struct is_integral<short>
{
	static const bool value = true;
};

template<>
struct is_integral<int>
{
	static const bool value = true;
};

template<>
struct is_integral<long>
{
	static const bool value = true;
};

template<>
struct is_integral<long long>
{
	static const bool value = true;
};


} // namespace ft