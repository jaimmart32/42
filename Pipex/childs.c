/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:48:51 by jaimmart          #+#    #+#             */
/*   Updated: 2023/01/23 16:19:40 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*These functions are for executing the commands entered as arguments of the 
pipex program.

get_cmd() takes pipex.cmd_paths extracted from **envp with find_path(), appends
a '/' and pipex.cmd_args, sees if there is access to a file for that command
and returns that command route so we can execute the command with execve().

access() checks whether the calling process can access the file pathname.
execve() executes the binary files in PATH= wich are shell commands.
pipe() sends the output of the first execve() as input to the second execve().
dup2() swaps our fd's(from infile, outfile, pipe) with stdin and stdout fd´s to
redirect the stream of the process as a '|' would in the shell but in C 
programming.*/

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], STDOUT);
	close(pipex.tube[0]);
	dup2(pipex.infile, STDIN);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], STDIN);
	close(pipex.tube[1]);
	dup2(pipex.outfile, STDOUT);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
/*In EXECVE() the first argument is the program(an executable file in envp),
 the second are the arguments for executing that file("-l","-a"...),
and the third one is an array of strings representing enviroment variables.*/
