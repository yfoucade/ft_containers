/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:00:51 by yfoucade          #+#    #+#             */
/*   Updated: 2022/12/31 22:01:44 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	
template< bool B, typename T = void >
struct enable_if
{
	typedef T type;
};

template< typename T >
struct enable_if<false, T>{ };

} // namespace ft
