/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:50:25 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/04/05 13:53:33 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long.h"
#include <stdbool.h>

static void	flood(t_tile *tile)
{
    if (tile->type == WALL || tile->type == FLOOD) {
        return;
    }
    tile->type = FLOOD;
    flood(tile->up);
    flood(tile->down);
    flood(tile->left);
    flood(tile->right);
}

void	set_flood_ptr(t_tile *tile, t_game *game)
{
	if (tile->type == PLAYER)
		game->flood_ptr = tile;
}

/* Returns a t_tile table filled according to <map>,
each line ends in a tile of type 0,
columns ends in a NULL pointer */
t_tile	**generate_f_tilemap(char **map, t_game *game)
{
	t_tile		**f_tilemap;
	int			x;
	int			y;

	f_tilemap = alloc_tilemap(map);
	if (!f_tilemap)
		return (null_error("malloc error on alloc_tilemap()"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			f_tilemap[y][x].type = define_tiletype(map[y][x]);
			setup_tile(f_tilemap, x, y);
			set_flood_ptr(&f_tilemap[y][x], game);
			x++;
		}
		f_tilemap[y][x].type = 0;
		y++;
	}
	f_tilemap[y] = NULL;
	return (f_tilemap);
}

bool	posible_path(t_tile	**f_tilemap)
{
	for (int y = 0; f_tilemap[y]; y++)
	{
	    for (int x = 0; f_tilemap[y][x].type; x++)
		{
	        if (f_tilemap[y][x].type == COLLECTABLE || f_tilemap[y][x].type == PLAYER)
	            return (FALSE);
	    }
	}
	return (TRUE);
}

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
int	flood_init(t_game *game, char **f_map)
{
	

	game->f_tilemap = generate_f_tilemap(f_map, game);
	flood(game->flood_ptr);
	//comprobar si despues del flood hay E y C, si los hay es que es imposible completar el juego.
	if (posible_path(game->f_tilemap) == FALSE)
	{
		printf("\nError, imposible path in map!\n");
		return (0);
	}
	return (1);
}