/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:32:13 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/27 16:15:11 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basics.h"
#include "map/map.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (!start(&game, argc, argv))
		return (0);
	mlx_key_hook(game.window, input, NULL);
	render(game);
	mlx_loop(game.mlx);
	return (0);
}