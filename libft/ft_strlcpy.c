/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:45:00 by jaimmart          #+#    #+#             */
/*   Updated: 2022/09/26 14:05:52 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	offset;

	offset = 0;
	if (dstsize > 0)
	{
		while (*src && offset + 1 < dstsize)
		{
			*dst++ = *src++;
			offset++;
		}
	}
	if (offset < dstsize)
		*dst = '\0';
	while (*src++)
		offset++;
	return (offset);
}
