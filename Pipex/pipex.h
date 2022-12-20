/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:42:09 by jaimmart          #+#    #+#             */
/*   Updated: 2022/12/14 15:37:37 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*write, read, close, access, pipe, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/*malloc, free, exit*/
# include <stdlib.h>

/*open, unlink*/
# include <fcntl.h>

/*wait, waitpid */
# include <sys/wait.h>

/*strerror*/
# include <string.h>

/*perror*/
# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number off arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	msg_error(char *err);
int		msg(char *err);

void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);

void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);

/*mini_libft*/
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif