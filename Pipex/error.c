/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:02:28 by jaimmart          #+#    #+#             */
/*   Updated: 2023/01/23 16:52:38 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* Functions for printing diferent types of error messages to the stderr.

msg() function for "Invalid number of arguments" and "Command not found" errors.

msg_error() for printing custommized messages followed by ": "
and the errno message string.

perror() function finds the error message corresponding to the current value of
the global variable errno and writes it to the STDERR fd. If the argument is 
non-NULL and does not point to the null character, this string
is prepended to the message string and separated from it by a colon and
space (": "); otherwise, only the error message string is printed. */

int	msg(char *err)
{
	write(STDERR, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}
