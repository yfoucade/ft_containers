/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:39 by yfoucade          #+#    #+#             */
/*   Updated: 2023/02/01 16:33:12 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"

int main(void){
	test_constructors();
	test_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_non_member();
}