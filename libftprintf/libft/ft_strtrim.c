/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:05:27 by jaimmart          #+#    #+#             */
/*   Updated: 2022/10/13 13:06:25 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
#include <string.h>*/

int	ident_char(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		if (s1[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new;
	size_t	len;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (ident_char(set, s1[i]) && s1[i])
		i++;
	while (ident_char(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (!new)
		return (NULL);
	while (i < len)
		new[j++] = s1[i++];
	new[j] = '\0';
	return (new);
}

/*int	main(void)
{
	printf("%s", ft_strtrim("     algo   fr    ", " "));
	return (0);
}
*/