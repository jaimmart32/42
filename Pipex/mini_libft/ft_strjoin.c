/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:45:49 by jaimmart          #+#    #+#             */
/*   Updated: 2022/12/09 17:12:43 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len + 1);
	ft_strlcat(new_str, s2, (len + 1));
	return (new_str);
}
