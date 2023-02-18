/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:22:31 by jaimmart          #+#    #+#             */
/*   Updated: 2022/10/13 13:06:25 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

static int	get_len(int n)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = 10;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / remainder;
	}
	return (i);
}

int	absolute_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	if (n == 0)
		*str = '0';
	if (n < 0)
		*str = '-';
	len--;
	while (len >= 0 && n != 0)
	{
		*(str + len) = absolute_val(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (str);
}
