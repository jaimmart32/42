/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:41:55 by jaimmart          #+#    #+#             */
/*   Updated: 2023/01/23 18:07:58 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*Since we dont know how many memory we will need to store the inputs of the 
user while executing the Pipex program, we will need to work with the heap 
allocating memory. These functions serve the purpose of freeing the memory 
allocated to store the command_paths(parent_free()) and the command_arguments 
of the pipex program for executing the unix commands needed(child_free()).

Also, parent_free() is used to close the files used and child_free() for 
freeing the command route(cmd).*/

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}
