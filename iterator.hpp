/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:45:10 by yfoucade          #+#    #+#             */
/*   Updated: 2022/12/31 21:01:09 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template< class Iter >
	struct iterator_traits{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template< class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

namespace ft
{

template< class Iter >
class reverse_iterator
{
	public:
		typedef Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;
		reverse_iterator( void );
		explicit reverse_iterator( iterator_type x );
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other );
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other );
		iterator_type base( void ) const;
		reference operator*( void ) const;
		pointer operator->( void ) const;
		reference operator[]( difference_type n ) const;
		reverse_iterator& operator++();
		reverse_iterator& operator--();
		reverse_iterator operator++( int );
		reverse_iterator operator--( int );
		reverse_iterator operator+( difference_type n ) const;
		reverse_iterator operator-( difference_type n ) const;
		reverse_iterator& operator+=( difference_type n );
		reverse_iterator& operator-=( difference_type n );
		
	protected:
		iterator_type current;
};

} // namespace ft

namespace ft
{
	template< typename Iter >
	reverse_iterator<Iter>::reverse_iterator( void ): current(Iter()){}

	template< typename Iter >
	reverse_iterator<Iter>::reverse_iterator( iterator_type x ):
		current(x){}

	template< typename Iter >
	template< typename U>
	reverse_iterator<Iter>::reverse_iterator( const reverse_iterator<U>& other ):
		current(other.base()){}

	template< typename Iter >
	template< class U >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=( const reverse_iterator<U>& other )
	{
		if (this == &other)
			return *this;
		current = other.base();
		return *this;
	}
	
	template< typename Iter >
	Iter reverse_iterator<Iter>::base( void ) const
	{
		return current;
	}
	
	template< typename Iter >
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*( void ) const
	{
		return *(current - 1);
	}

	template< typename Iter >
	typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->( void ) const
	{
		return current - 1;
	}

	template< typename Iter >
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[]( difference_type n ) const
	{
		return current - n - 1;
	}
	template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
	{
		--current;
		return *this;
	}

	template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
	{
		++current;
		return *this;
	}

	template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++( int )
	{
		reverse_iterator<Iter> old(*this);
		--current;
		return old;
	}
	template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--( int )
	{
		reverse_iterator<Iter> old(*this);
		--current;
		return old;
	}
	
	template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator+( difference_type n ) const
	{
		return reverse_iterator(current - n);
	}

	template< typename Iter >
	reverse_iterator<Iter> reverse_iterator<Iter>::operator-( difference_type n ) const
	{
		return reverse_iterator(current + n);
	}
	template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator+=( difference_type n )
	{
		current -= n;
		return *this;
	}

	template< typename Iter >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=( difference_type n )
	{
		current += n;
		return *this;
	}
} // namespace ft


namespace ft
{
	
	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() == rhs.base();
		}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() != rhs.base();
		}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() > rhs.base();
		}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() >= rhs.base();
		}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() < rhs.base();
		}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
		{
			return lhs.base() <= rhs.base();
		}
	template< class Iter >
	reverse_iterator<Iter>
		operator+( typename reverse_iterator<Iter>::difference_type n,
				const reverse_iterator<Iter>& it )
		{
			return reverse_iterator<Iter>(it.base() - n);
		}
	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type
		operator-( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs )
		{
			return rhs.base() - lhs.base();
		}
} // namespace ft
