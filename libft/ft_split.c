/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:40:50 by jaimmart          #+#    #+#             */
/*   Updated: 2022/09/25 17:56:54 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	wordlen(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (*s)
	{
		index++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			index--;
		while (*s && *s != c)
			s++;
	}
	return (index);
}

static	char	**fill_string(char **store, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**split_string;
	size_t	len_words;

	if (!s)
		return (NULL);
	len_words = wordlen(s, c);
	split_string = malloc(sizeof(char *) * (len_words + 1));
	if (!split_string)
		return (NULL);
	split_string = fill_string(split_string, s, c);
	return (split_string);
}

/*int	main()
{
	char **frases = ft_split("va para su casa, se sabe o no", 'a');
	
	while (**frases != '\0')
	{
		printf("%s\n", *frases);
		frases++;;
	}
}*/