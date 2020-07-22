/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:59:35 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "doom_nukem.h"

# define NB_THREAD 8

typedef union		u_color
{
	Uint32			number;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_parse
{
	int				i;
	int				col;
	int				tmp;
}					t_parse;

typedef struct		s_d_point
{
	double			x;
	double			y;
}					t_d_point;

typedef struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef struct		s_ray
{
	t_d_point		pos;
	t_d_point		dir;
}					t_ray;

typedef struct		s_player
{
	double			angle;
	t_d_point		plane;
	t_d_point		pos;
	t_d_point		dir;
	double			walkspeed;
	double			sprintspeed;
	double			rspeed;
	short			hp;
	short			armor;
	short			key;
	short			bullets;
	short			shells;
	short			rockets;
	short			cells;
	short			selected_weapon;
	short			is_firing;
	short			has_fired;
	short			shot_fired;
	short			swap_weapon;
}					t_player;

typedef struct		s_raycast
{
	t_ray			ray;
	double			camera;
	t_point			m_pos;
	t_d_point		sidedist;
	t_d_point		deltadist;
	t_point			step;
	int				hit;
	double			wall;
	int				side;
	int				texh;
	int				texw;
	int				texnum;
	t_point			tex;
	int				lineheight;
	Uint32			color;
	int				drawstart;
	int				drawend;
	double			walldist;
}					t_raycast;

typedef struct		s_floorcast
{
	t_d_point		floor;
	t_d_point		currentfloor;
	t_point			floortex;
	double			currentdist;
	double			weight;
}					t_floorcast;

typedef struct		s_skybox
{
	double			dir;
	double			col;
	double			col_step;
	int				cur_col;
}					t_skybox;

typedef struct		s_objcast
{
	t_d_point		relative_pos;
	double			invdet;
	int				screen_x;
	t_d_point		pos;
	int				movescreen;
	int				height;
	int				width;
	t_point			drawstart;
	t_point			drawend;
	t_point			tex;
	Uint32			color;
}					t_objcast;

typedef struct		s_object
{
	int				id_key;
	int				obj_type;
	short			state;
	t_d_point		pos;
	double			move_speed;
	double			dist_to_player;

	short			sprite_pos;

	int				first_sprite_walk;
	int				num_of_sprites_walk;
	int				first_sprite_attack;
	int				num_of_sprites_attack;
	int				first_sprite_death;
	int				num_of_sprites_death;
	int				lastframe;
	double			lastupdate;
	int				current_sprite;

	int				pix_mid_x;
	short			is_aggro;
	int				pix_mid_y;
	short			hp;
	short			visible;
	double			hl_time;
	struct s_object	*next;
	struct s_object	*prev;
}					t_object;

typedef struct		s_sprite
{
	SDL_Surface		*surf;
	t_d_point		scale;
}					t_sprite;

typedef struct		s_hud
{
	TTF_Font		*font;
	SDL_Color		text_color;
	SDL_Texture		*hud_texture;
	SDL_Rect		hud_pos;
	SDL_Texture		*face_texture;
	SDL_Rect		face_pos;
	SDL_Texture		*hp_text;
	SDL_Texture		*armor_text;
	SDL_Texture		*bullets_text;
	SDL_Texture		*shells_text;
	SDL_Texture		*cells_text;
	SDL_Texture		*infinite_text;
	SDL_Texture		*ammo_text;
}					t_hud;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
	short			ceiling;
	short			night;
}					t_map;

typedef struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		**surface;
	pthread_t		thread[NB_THREAD];
	t_sprite		*obj_sprite;
	SDL_Texture		**sprites;
	SDL_Texture		*weapon_texture;
	Uint32			*pixels;
	t_point			mouse;
	double			ftime;
	double			time;
	int				yaw;
	double			mouse_sens;
	t_player		p;
	t_map			cur_map;
	t_map			maps[4];
	short			toggle_minimap;
	short			quit;

	short			shaded;
	short			ceiling;

	double			*zbuffer;
	double			*e_zbuffer;
	t_object		*obj;
	t_hud			hud;

	Uint32			p_dmgtime;
	Uint32			p_healtime;
	Uint32			p_armortime;

	short			custom_map;
	short			menu;
	short			menu_sel;
	short			has_menued;
	short			enter_screen;
	short			exit_screen;
	short			death_screen;

	t_point			is_window;
	short			hit_window;
	double			window_dist;
}					t_data;

#endif
