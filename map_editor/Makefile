# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:02:55 by jpoulvel          #+#    #+#              #
#    Updated: 2020/03/04 22:27:44 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD `sdl2-config --cflags`

NAME = mapeditor

LIBFT = ../libft/libft.a

SRC = init/main.c \
	   draw/draw_menu.c \
	   draw/draw_blocks.c \
	   draw/print_grid.c \
	   draw/render.c \
	   draw/draw_line.c \
	   event/infinite_loop.c \
	   event/keys_controls.c \
	   event/menu_controls.c \
	   event/modify_map.c \
	   event/mouse_controls.c \
	   event/save_new_map.c \
	   parsing/check_map.c \
	   parsing/map_copy.c \
	   parsing/parsing.c \
	   tools/colorize.c \
	   tools/fix_coords.c \
	   tools/free_functions.c \
	   tools/free_path_tab.c \
	   tools/gnl_incoming_map.c \
	   init/center_map.c \
	   init/mouse_and_key_init.c \
	   init/surfaces_init.c \
	   init/structures_init.c \
	   textures/load_textures.c

SRC_DIR = ./
OBJ_DIR = obj/
INC_DIR = hdr/

SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ= $(SRC:.c=.o)
DPD= $(SRC:.c=.d)

OBJ_SUBDIRS= draw event parsing tools init textures
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))
LIB= `sdl2-config --libs` \
	 `sdl2-config --libs`_ttf\
	 -L ../libft -lft
INCLUDES= ../hdr/map_editor.h

all: $(SUBDIRS)
	@$(MAKE) -j ../$(NAME)

../$(NAME): $(OBJS) $(INCLUDES)
	@echo "\033[2K \033[A"
	@clang $(CFLAGS) -o ../$(NAME) $(OBJS) $(LIB) $(LIBFT) -lm
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT)
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(SUBDIRS)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@clang $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f ../$(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

installSDL:
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-ttf-dev

re : fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
