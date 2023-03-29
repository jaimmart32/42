/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:13:21 by jaimmart32        #+#    #+#             */
/*   Updated: 2023/03/28 20:08:03 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "basics.h"
# include <mlx.h>
#include "libft/libft.h"

/* Size of every sprite */
# define IMG_SIZE 32

// ---------- TILES

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* An image that covers the whole window */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

/* Color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/* Info about the player */
typedef struct s_player
{
	t_tile	*tile;
	void	*img;
}	t_player;

/* All info for the game run */

/* All valid input keys */

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	
	t_vector		img_size;
	
	void			*player_imgs;
	void			*door_open_img;
	void			*door_close_img;
	void			*wall_img;
	void			*collects_imgs;
	
	void			*red_panel;
	void			*white_panel;
}	t_game;

enum e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	RESET = 15,
	ESC = 65307
};

//Game Functions
t_bool	start(t_game *game, int argc, char **argv);
int		end_program(t_game *game);
int	input(int key, t_game *game);
int	key_input(int keycode, void *param);
void	render(t_game game);

// Player
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
void	pick_collect(t_game *game, t_tile *tile);
void	remove_player(t_game *game);
t_bool	move_to(t_game *game, t_tile *tile);
//Window Panel
t_color	new_color(int r, int g, int b, int a);
void	color_panel(t_panel *panel, t_color color);
void	*new_panel(t_game *game, t_color color);

// Util Functions
int	ft_strend_cmp(char *name, char *end);
void	ft_free_chartable(char **table);
int	ft_chartable_linecount(char **table);

// Images
void	open_images(t_game *game);


#endif