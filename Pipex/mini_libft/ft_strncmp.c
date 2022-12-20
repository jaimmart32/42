/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:33:02 by jaimmart          #+#    #+#             */
/*   Updated: 2022/12/09 17:12:02 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	diff;

	diff = 0;
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0')
		&& (diff == 0) && (i < n))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if ((diff == 0) && (i < n))
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
