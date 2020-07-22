/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:50:44 by acostaz           #+#    #+#             */
/*   Updated: 2020/04/17 16:28:17 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include "/usr/local/Cellar/sdl2/2.0.12_1/include/SDL2/SDL.h"
# include "/usr/local/Cellar/sdl2_ttf/2.0.15/include/SDL2/SDL_ttf.h"
# include "struct.h"
# include "proto.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MAX_BULLETS 200
# define MAX_SHELLS 20
# define MAX_CELLS 100
# define MAX_ROCKETS 8
# define MAX_HEALTH 100
# define MAX_ARMOR 100

# define BUFF_SIZE 4096

# define BFG 2.0
# define CHAINSAW 0.2
# define HANDGUN 0.6
# define KNUCKLE 0.3
# define MINIGUN 0.1
# define PLASMA 0.2
# define SHOTGUN 0.7

# define DYING 0
# define WALKING 1
# define ATTACKING 2
# define STUNNED 3
# define IDLE 4

# define GROUND 0
# define FLOAT 1
# define ROOF 2

#endif
