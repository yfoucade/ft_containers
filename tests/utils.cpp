/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:45:27 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/07 22:45:37 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

ft::vector< int > range_vector(int min, int max)
{
	ft::vector< int > res;
	while (min < max)
		res.push_back(min++);
	return res;
}