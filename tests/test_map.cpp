/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:09 by yfoucade          #+#    #+#             */
/*   Updated: 2023/01/19 18:37:33 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

int main( void )
{
	std::map< char, int > m;

	m.insert(std::pair< char, int >('a', 1));
	m.insert(std::pair< char, int >('b', 2));
	m.insert(std::pair< char, int >('c', 3));
	m.insert(std::pair< char, int >('z', 26));
	std::map< char, int > n;
	n.insert(std::pair< char, int >('d', 4));
	m.insert(std::pair< char, int >('d', 4));

	std::map< char, int >::iterator j = ++m.begin();
	std::map< char, int >::iterator i;
	std::map< char, int >::reverse_iterator r = m.rbegin();
	for (i = m.begin(); i != m.end(); ++i)
	{
		std::cout << (&*i) << ": " << i->first << ", " << (*i).second << std::endl;
		i->second += 1;
		std::cout << (&*i) << ": " << i->first << ", " << (*i).second << std::endl;
		break;
	}
	// data is not contiguous in memory, it is not sorted in memory neither.
}
