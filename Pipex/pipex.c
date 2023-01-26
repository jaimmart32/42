/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:34:27 by jaimmart          #+#    #+#             */
/*   Updated: 2023/01/26 11:55:49 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*find_path() returns a pointer to the string PATH in the "array of
 strings" **envp,where PATH= begins, + 5 positions in the string of path because
 we want to be after PATH= . AFTER WE WILL SPLIT THIS STRING WITH SEPARATOR ':' 
 TO GET POSIBLE COMAND_PATHS*/
char	*find_path(char **envp)
{
	int	index;

	index = 0;
	while (envp[index])
	{
		if (strncmp("PATH", *envp, 4) == 0)
			break ;
		envp++;
	}
	if (envp[index] == NULL)
		return (NULL);
	return (*envp + 5);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}
/*Protect fork() and execve()!??*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		msg_error(ERR_PIPE);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
