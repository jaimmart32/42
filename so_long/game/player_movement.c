/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:46 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/29 13:55:08 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
void	move_to_empty(t_game *game, t_tile *tile)
{
    printf("%c\n", tile->type);
	tile->type = PLAYER;
    printf("%c\n", tile->type);
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
	render(*game);
}

void	pick_collect(t_game *game, t_tile *tile)
{
	printf("collect: %c\n", tile->type);
	tile->type = EMPTY;
	game->collects--;
	render(*game);
}

void	move_to_exit(t_game *game)
{
	printf("exit:\n");
	render(*game);
	sleep(1);
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	remove_player(game);
	game->collects = -1;
	mlx_loop_end(game->mlx);
}