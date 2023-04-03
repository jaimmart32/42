/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:32:13 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/31 17:36:05 by jaimmart32       ###   ########.fr       */
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
	//mlx_key_hook(game.window, input, NULL);
	// Conecta la función de callback key_input() con mlx_key_hook()
	render(game);
	mlx_key_hook(game.window, key_input, &game);
	//mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}