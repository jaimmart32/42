#include "../so_long.h"
#include "../map/map.h"

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;
	int		f_flag;

	f_flag = 0;
	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	f_flag = flood_init(game, map);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	if (f_flag == 0)
	{
		game->tilemap = tilemap;
		free_tilemaps(game);
		return (NULL);
	}
	return (tilemap);
}

/* Starts the mlx, opens a window, and open images */
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
}

/* Initialize the <game> struct, generate tilemap.*/
t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	game_init(game);
	return (TRUE);
}