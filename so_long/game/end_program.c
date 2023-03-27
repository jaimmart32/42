#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	exit(0);
}