/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:42:16 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/27 16:10:21 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Draws the corresponding image of the tile type */
static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		mlx_put_image_to_window(game.mlx, game.window,
		game.wall_img, pos.x, pos.y);
	else if (tile.type == EXIT)
	{
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img, pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs, pos.x, pos.y);
}

/* Puts the tile map on the window */
void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
}