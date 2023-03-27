/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:38:29 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/27 15:36:32 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{

	if (key == ESC)
		end_program(game);
    return (0);
}