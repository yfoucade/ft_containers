/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:29:57 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/01 11:49:24 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template< typename InputIt1, typename InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (!(*first1 != *first2))
			return false;
	}
	return true;
}

template< typename InputIt1, typename InputIt2, typename BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
	for (; first1 != last1; ++first1, ++first2)
	{
		if (!p(*first1, *first2))
			return false;
	}
	return true;
}

} // namespace ft