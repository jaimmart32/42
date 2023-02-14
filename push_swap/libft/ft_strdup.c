/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:08:51 by jaimmart          #+#    #+#             */
/*   Updated: 2022/09/26 14:00:42 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
/*The strdup() function allocates sufficient memory for a copy of the string
     s1, does the copy, and returns a pointer to it.*/

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*p_s1;
	size_t	i;

	p_s1 = (char *)s1;
	i = 0;
	d = (char *)malloc(ft_strlen(p_s1) + 1);
	if (d == NULL)
		return (NULL);
	while (p_s1[i] != '\0')
	{
		d[i] = p_s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
