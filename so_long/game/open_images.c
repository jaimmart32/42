/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:58:19 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/27 17:29:04 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void open_wall_imgs(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs = mlx_xpm_file_to_image(game->mlx,
			"sprites/box.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/ladder2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/ladder.xpm",
			&game->img_size.x, &game->img_size.y);
}

/* Opens with the mlx all images needed in the game */
void	open_images(t_game *game)
{
    open_wall_imgs(game);
	open_collect_imgs(game);
	open_door_imgs(game);
}