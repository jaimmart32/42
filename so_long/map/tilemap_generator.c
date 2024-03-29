// #include "map.h"
// #include "../so_long.h"

// /* Allocates memory to save a tilemap with same size as <map> */
// t_tile	**alloc_tilemap(char **map)
// {
// 	t_tile	**tilemap;
// 	int		i;

// 	tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));//malloc o calloc?+ 1 o + ttile(-3errors valgrind)?
// 	if (tilemap == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (map[i] != NULL)
// 	{
// 		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(map[i]) + 1));//malloc or calloc?+ 1(menos errores)? Valgrind se queja mucho
// 		if (tilemap[i] == NULL)
// 		{
// 			while (i > 0)
// 				free(tilemap[--i]);
// 			//free(tilemap);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (tilemap);
#include "map.h"
#include "../so_long.h"
#include <string.h>

/* Allocates memory to save a tilemap with same size as <map> */
t_tile **alloc_tilemap(char **map)
{
    t_tile **tilemap;
    int i;

    tilemap = (t_tile **)malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
    if (tilemap == NULL)
        return (NULL);

    // Initialize all pointers in tilemap to NULL
    for (i = 0; i < ft_chartable_linecount(map) + 1; i++)
        tilemap[i] = NULL;

    i = 0;
    while (map[i] != NULL)
    {
        tilemap[i] = (t_tile *)malloc(sizeof(t_tile) * (ft_strlen(map[i]) + 1));
        if (tilemap[i] == NULL)
        {
            while (i > 0)
            {
                i--;
                free(tilemap[i]);
                tilemap[i] = NULL;
            }
            free(tilemap);
            return (NULL);
        }

        // Initialize all elements in tilemap[i] to zero
        memset(tilemap[i], 0, sizeof(t_tile) * (ft_strlen(map[i]) + 1));

        i++;
    }
    return (tilemap);
}

/* Returns the tiletype that corresponds to <definer> */
t_tiletype	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	return (EMPTY);
}

/* Set the size, original type and neighboors of the <x><y> tile of <tilemap> */
void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)// valgrind queja intenta tomar decision sobre valor no inciado.
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

/* Add info to the game struct if needed */
void	set_gamevars(t_tile *tile, t_game *game)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->collects++;
}

/* Returns a t_tile table filled according to <map>,
each line ends in a tile of type 0,
columns ends in a NULL pointer */
t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_error("malloc error on alloc_tilemap()"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type = define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y);
			set_gamevars(&tilemap[y][x], game);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->wndw_size.x = x * IMG_SIZE;
	game->wndw_size.y = y * IMG_SIZE;
	//for checking leaks.
	y = 0;
	x = 0;
	while (tilemap[y] != NULL)
	{
		printf("fila %d: %c",y, (char)tilemap[y][x].type);
		y++;
	}
	return (tilemap);
}
