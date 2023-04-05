#ifndef MAP_H
# define MAP_H

# include "../basics.h"
# include "../so_long.h"

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

t_tile **alloc_tilemap(char **map);
t_tile	**generate_tilemap(char **map, t_game *game);
int		flood_init(t_game *game, char **f_map);
t_tiletype	define_tiletype(char definer);
void	setup_tile(t_tile **tilemap, int x, int y);

int	valid_border(char c, t_vector point, t_vector size);
int	valid_uniquechar(char c, char checker, t_bool *bool);
int	valid_char(char c);
#endif