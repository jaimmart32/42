/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:38:29 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/04/11 14:35:01 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_noexit(t_game *game, t_tile *tile);

/* Move the player to <tile> doing whats needed based on its type */
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game);
	else if (tile->type == EXIT && game->collects > 0)
		move_to_noexit(game, tile);
	else
		return (FALSE);
	return (TRUE);
}

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{
	 t_bool	moved;
	 if (key == ESC)
	 	end_program(game);
	 if (game->player.tile == NULL)
	 	return (0);
	 if (key == KEY_UP)
	 	moved = move_to(game, game->player.tile->up);
	 else if (key == KEY_DOWN)
	 	moved = move_to(game, game->player.tile->down);
	 else if (key == KEY_LEFT)
	 	moved = move_to(game, game->player.tile->left);
	 else if (key == KEY_RIGHT)
	 	moved = move_to(game, game->player.tile->right);
	 else
	 	return (0);
	 if (moved)
	 	printf("Moves -> %02d\n", ++game->moves);
	//render(game);
	 return (1);
}

int	key_input(int keycode, void *param)
{
	// Llama a la función input() con el código de tecla presionado
	input(keycode, (t_game *)param);
	
	return (0);
}
