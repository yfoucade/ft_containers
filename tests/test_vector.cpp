/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:58:39 by yfoucade          #+#    #+#             */
/*   Updated: 2022/12/28 10:42:50 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

void test_constructor(void){
	std::vector<int> v1;
	ft::vector<int> v2(5, 10);

	ft::vector<int>::iterator begin = v2.begin();
	ft::vector<int>::iterator end = v2.end();
	while (begin != end)
	{
		*begin = 42.024;
		std::cout << *begin++ << "\n";
	}
	
	ft::vector<float> v3(v2.begin(), v2.end());
	ft::vector<float>::iterator begin2 = v3.begin();
	ft::vector<float>::iterator end2 = v3.end();
	while (begin2 != end2)
	{
		*begin2 = 42.024;
		std::cout << *begin2++ << "\n";
	}
	ft::vector<int> v4 = v2;
	// v4 = v2;
	ft::vector<int>::iterator begin4 = v4.begin();
	ft::vector<int>::iterator end4 = v4.end();
	while (begin4 != end4)
	{
		*begin4 = 42.024;
		std::cout << *begin4++ << "\n";
	}
}

int main(void){
	test_constructor();
}