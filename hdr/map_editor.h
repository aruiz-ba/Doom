/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:12:48 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/11 11:21:27 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# include "../libft/inc/libft.h"
# include <SDL.h>
# include <SDL_ttf.h>
# include "../libft/inc/get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1400
# define HEIGHT 1000
# define NAME "MAP EDITOR"
# define OCRE 0xffa700
# define WHITE 0xf0f8ff
# define BROWN 0xcd7f32
# define GREEN 0x00ff00
# define SAND 0xfad6a5
# define LIGHT_BLUE 0xb2ffff
# define BLUE 0x21abcd
# define DEEP_BLUE 0x002fa7
# define RED 0xe32636
# define YELLOW 0xffff00
# define ZOOM_IN 1073741911
# define ZOOM_OUT 1073741910

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	SDL_Color		color;
}					t_point;

typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct		s_mouse
{
	int				posx;
	int				posy;
	int				click1[2];
	int				click;
	int				loop;
	int				mtime;
	int				mceiling;
}					t_mouse;

typedef	struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				zoom_in;
	int				zoom_out;
}					t_key;

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				ox;
	int				oy;
	float			base_gap;
	char			proj;
	int				endx;
	int				endy;
	int				light_ceiling;
}					t_map;

typedef struct		s_fdf
{
	char			*map_name;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		**texture;
	SDL_Texture		*grid;
	t_map			*map;
	int				height;
	Uint32			*pixels;
	int				*point_color;
	SDL_Color		color;
}					t_fdf;

typedef	struct		s_line
{
	char			*str;
	int				x;
	int				y;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

/*
**			PARSING
*/
t_map				*ft_parser(int fd);
t_map				*ft_map_copy(t_line *list);
t_line				*ft_list_alloc(int fd);
char				*ft_conform_line(char *str);
int					ft_conform_char(char c);

/*
**			INFINITE LOOP
*/
void				ft_fdf(t_map *map, char *map_name);

/*
**			INIT
*/
t_fdf				*ft_ptr_init(char *name);
t_map				*ft_map_init(t_line *list);
int					ft_mouse_init(t_mouse *mous);
int					ft_key_init(t_key *key);
void				nullify_textures(t_fdf *img);
short				loadmedia(t_fdf *img);

/*
**			FREE_FUNCTIONS
*/
void				free_path_tab(char **path_tab);
void				ft_free_map(t_map *map);
void				ft_free_line(t_line *list);
void				ft_free_fdf(t_fdf *fdf);
void				ft_clean_exit(t_fdf *img, char *err);

/*
**			EVENT
*/
void				loop_til_release();
void				ft_menu_event(t_mouse *mous, SDL_Event e);
void				ft_keys_event(t_fdf *img, SDL_Event e);
void				ft_mouse_event(t_fdf *img, t_mouse *mous, SDL_Event e);
void				click_to_modify_map(t_map *map, t_mouse *mous);
void				ft_save_map(t_fdf *img);

/*
**			DRAW
*/
void				ft_clear_and_render(t_fdf *img, t_mouse *mous);
void				ft_print_grid(t_fdf *img);
void				ft_render_button_squares(t_fdf *img);
void				draw_menu_squares(t_fdf *img);
void				draw_menu_textures(t_fdf *img);
void				ft_print_pressed_button(t_fdf *img, t_mouse *mous);
void				ft_print_blocks(t_pt pt, int map_value, t_fdf *img, \
					int size);
void				ft_parse_and_print_textures(t_fdf *img);
void				draw_line(t_pt pt_one, t_pt pt_two, Uint32 *pixels, \
					int colour);
void				check_and_draw_line(t_pt start, t_pt end, t_fdf *img, \
					int col);
void				ft_calculate_grid_coord_and_draw_line(t_pt a, t_pt b, \
					t_fdf *img, int col);
void				print_button_add_and_substract(t_fdf *img);

/*
**			COLORS
*/
SDL_Color			ft_hexa_to_sdl(int color);

/*
**			MOVING
*/
void				ft_zoom(t_key *key, t_map *map);
void				ft_move(t_key *key, t_map *map);

/*
**			TOOLS
*/
int					ft_gap(t_map *map);
void				ft_origin(t_map *map);
float				ft_height(t_map *map);
void				ft_fix_coords(t_map *map, int *x, int *y);
t_pt				coord_to_pt(int x, int y);
void				mk_point_and_trace_line(int x1, int y1, int x2, \
					int y2, t_fdf *img);
t_fdf				*ft_img(void);

#endif
