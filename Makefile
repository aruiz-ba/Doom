# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JP <JP@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 12:42:59 by acostaz           #+#    #+#              #
#    Updated: 2020/03/25 16:07:41 by JP               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD `sdl2-config --cflags`

NAME = doom-nukem

LIBFT = libft/libft.a
MAP_EDITOR = mapeditor

SRC =	draw/display_hud.c\
		draw/drawline.c\
		draw/draw_minimap.c\
		draw/draw_rect_to_sdl.c\
		draw/show_player.c\
		exit/clean_exit.c\
		game/ammo.c\
		game/combat.c\
		game/doors.c\
		game/event_loop.c\
		game/flashing_screens.c\
		game/game_inputs.c\
		game/health.c\
		game/menu_inputs.c\
		game/movement.c\
		game/multi_thread.c\
		game/weap_hits.c\
		image/image_utils.c\
		image/load_image.c\
		image/load_media_hud.c\
		image/shading.c\
		init/create_sprites.c\
		init/get_hud_text.c\
		init/init.c\
		init/main.c\
		init/nullify.c\
		init/set_values.c\
		map/current_map.c\
		map/default_map_values.c\
		map/fill_map.c\
		map/new_map.c\
		map/new_map_utils.c\
		map/parsing.c\
		menu/menu.c\
		menu/menu_selection.c\
		objects/ammo_pickup.c\
		objects/count_enemies.c\
		objects/enemy_death.c\
		objects/enemy_vision.c\
		objects/get_obj_data.c\
		objects/hud_keys.c\
		objects/item_pickup.c\
		objects/obj_list.c\
		objects/pathfinder.c\
		objects/state_machine.c\
		objects/swap_obj.c\
		raycasting/floorcaster.c\
		raycasting/objectcasting.c\
		raycasting/raycasting.c\
		raycasting/raycast_utils.c\
		raycasting/set_objcast_values.c\
		raycasting/windowcasting.c\
		skybox/skybox.c\
		story/display_story_screen.c\
		story/text_screen_inputs.c\
		weapon/use_bfg.c\
		weapon/use_chainsaw.c\
		weapon/use_handgun.c\
		weapon/use_knuckle.c\
		weapon/use_minigun.c\
		weapon/use_plasma.c\
		weapon/use_shotgun.c\
		weapon/use_weapon.c

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = hdr/

SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ= $(SRC:.c=.o)
DPD= $(SRC:.c=.d)

OBJ_SUBDIRS= init draw map raycasting game image skybox weapon \
			 objects menu story exit
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))
LIB= `sdl2-config --libs` \
	 `sdl2-config --libs`_ttf\
	 -L libft -lft
INCLUDES=	hdr/doom_nukem.h\
			hdr/proto.h\
			hdr/struct.h

all: $(SUBDIRS)
	@$(MAKE) all -C libft
	@$(MAKE) all -C map_editor
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "\033[2K \033[A"
	@clang $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT) -lm -lpthread
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT)
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(SUBDIRS)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@clang $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C map_editor
	@rm -rf $(OBJ_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[31m[$(LIBFT)]: deleted\033[0m"
	@rm -f $(MAP_EDITOR)
	@echo "\033[31m[$(MAP_EDITOR)]: deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

installSDL:
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-ttf-dev

re : fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
