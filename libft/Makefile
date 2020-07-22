# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 16:17:52 by acostaz           #+#    #+#              #
#    Updated: 2020/02/26 13:45:10 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD

NAME = libft.a

SRC_NAME = ft_abs.c	\
		   ft_atoi.c \
		   ft_bzero.c \
		   ft_fabs.c \
		   ft_find_next_prime.c	\
		   ft_is_prime.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_islower.c \
		   ft_isprint.c \
		   ft_isupper.c \
		   ft_itoa.c \
		   ft_lstadd.c \
		   ft_lstapp.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstlen.c \
		   ft_lstmap.c \
		   ft_lstnew.c \
		   ft_memalloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memdel.c \
		   ft_memmove.c \
		   ft_memset.c \
		   ft_padicval.c \
		   ft_printf/buff.c \
		   ft_printf/float_exponents.c \
		   ft_printf/float_utils.c \
		   ft_printf/ft_printf.c \
		   ft_printf/get_format.c \
		   ft_printf/id_utils.c \
		   ft_printf/type_c.c \
		   ft_printf/type_d.c \
		   ft_printf/type_f.c \
		   ft_printf/type_o.c \
		   ft_printf/type_p.c \
		   ft_printf/type_pct.c \
		   ft_printf/type_s.c \
		   ft_printf/type_u.c \
		   ft_printf/type_x.c \
		   ft_printf/utils.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_putnbrendl.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_sqrt.c \
		   ft_stralnum.c \
		   ft_stralpha.c \
		   ft_strascii.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdel.c \
		   ft_strdigit.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strlower.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strndup.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strnstr.c \
		   ft_strprint.c \
		   ft_strrchr.c \
		   ft_strsplit.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_strupper.c \
		   ft_tolower.c \
		   ft_toupper.c \
		   get_next_line.c\
		   ft_error.c\
		   ft_replace.c\
		   ft_strlen_chr.c\
		   ft_strrev.c\
		   ft_strtrimc.c\
		   free_tab.c\
	   	   ft_error_fd.c

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = inc

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
DPD = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.d))

INCLUDES = $(INC_DIR)/libft.h $(INC_DIR)/get_next_line.h $(INC_DIR)/ft_printf.h

opti:
	@$(MAKE) -j all

debug:
	@$(MAKE) opti DEBUG=yes

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@echo "\033[2K \033[A"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@mkdir -p obj/ft_printf
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
