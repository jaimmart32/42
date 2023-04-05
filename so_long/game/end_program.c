#include "../so_long.h"

void	free_tilemaps(t_game *game)
{
	t_tile	**tilemap;
	t_tile	**f_tilemap;

	tilemap = game->tilemap;
	f_tilemap = game->f_tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
	while (*game->f_tilemap != NULL)
	{
		free(*game->f_tilemap);
		game->f_tilemap++;
	}
	free (f_tilemap);
}

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_tilemaps(game);
	game->tilemap = NULL;
	game->f_tilemap = NULL;
	mlx_destroy_window(game->mlx,game->window);//destroy window?
	// mlx_destroy_image(game->mlx, game->player.img);
	// mlx_destroy_image(game->mlx, game->wall_img);
	// mlx_destroy_image(game->mlx, game->collects_imgs);
	// mlx_destroy_image(game->mlx, game->door_open_img);
	// mlx_destroy_image(game->mlx, game->door_close_img);
	mlx_destroy_display(game->mlx);//destroy mlx?
	//free(game);//free game struct? its in the stack, not on the heap so i supose no..;()
	exit(0);
}