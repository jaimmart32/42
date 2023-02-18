/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:56:45 by jaimmart          #+#    #+#             */
/*   Updated: 2022/09/23 12:11:46 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
/*The memmove() function copies len bytes from string src to string dst.The
     two strings may overlap; the copy is always done in a non-destructive
	  manner.
	The memmove() function returns the original value of dst.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	unsigned const char	*p_src;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	p_dst = (unsigned char *)dst;
	p_src = (unsigned const char *)src;
	if (!len || dst == src)
		return (dst);
	while (len--)
		p_dst[len] = p_src[len];
	return (dst);
}
