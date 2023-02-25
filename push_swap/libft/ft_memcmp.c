/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:12:38 by jaimmart          #+#    #+#             */
/*   Updated: 2023/02/25 14:31:06 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
/*The memcmp() function compares byte string s1 against byte string s2.  Both
     strings are assumed to be n bytes long.
	The memcmp() function returns zero if the two strings are identical, otherwise
     returns the difference between the first two differing bytes (treated as
     unsigned char values, so that `\200' is greater than `\0', for example).*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*y;
	unsigned char	*x;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	
	if (n)
		while (n--)
			if (*x++ != *y++)
				return (*(--x) - *(--y));
	return (0);
}
