# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/06 16:23:16 by sbednar           #+#    #+#              #
#    Updated: 2019/03/04 08:56:31 by edraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC_DIR		=	./src
OBJ_DIR		=	./obj

LL3D_DIR	=	./ll3d
MLX_DIR		=	./minilibx
FT_DIR		=	./libft

SRC			= 	main.c \
				redraw.c \
				hook_key.c \
				hook_camera_move.c \
				hook_camera_rotate.c \
				hook_camera_change.c \
				mouse_init.c \
				hook_mouse.c \
				free_helper.c \
				set_frac.c \
				screen_to_wrld.c \
				renderer.c \
				set_m.c \
				precalc_m.c \
				calc_m.c \
				hook_frac_control.c \
				set_colors.c \
				color_pallets.c \
				play_station.c

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS		=	-I. -I./ll3d -I./minilibx -I./libft
LIBS		=	-L./libft -L./minilibx -L./ll3d -lft -lmlx -lll3d -framework OpenGL -framework AppKit

CC			=	gcc
CFLAGS		=	-o3 -Wall -Wextra -Werror -o3

all: $(NAME)
	@echo "\033[92m\033[1m---> ALL DONE\033[0m\033[0m"

$(NAME):
	@echo "\033[91m\033[1m[1/6] \033[97m\033[1mll3d all:\033[0m"
	@$(MAKE) -C $(LL3D_DIR) all
	@echo "\033[91m\033[1m[2/6] \033[97m\033[1mmlx all:\033[0m"
	@$(MAKE) -C $(MLX_DIR) all
	@echo "\033[91m\033[1m[3/6] \033[97m\033[1mlibft all:\033[0m"
	@$(MAKE) -C $(FT_DIR) all
	@echo "\033[91m\033[1m[4/6] \033[97m\033[1mobjects folder create:\033[0m"
	mkdir -p $(OBJ_DIR)
	@echo "\033[91m\033[1m[5/6] \033[97m\033[1mc files compile:\033[0m"
	@$(MAKE) $(OBJ)
	@echo "\033[91m\033[1m[6/6] \033[97m\033[1mexecutable compile:\033[0m"
	$(CC) $(CFLAGS) $(INCS) $(LIBS) $(OBJ) -o $(NAME)

src: clean
	@echo "\033[91m\033[1m[4/6] \033[97m\033[1mobjects folder create:\033[0m"
	mkdir -p $(OBJ_DIR)
	@echo "\033[91m\033[1m[5/6] \033[97m\033[1mc files compile:\033[0m"
	@$(MAKE) $(OBJ)
	@echo "\033[91m\033[1m[6/6] \033[97m\033[1mexecutable compile:\033[0m"
	$(CC) $(CFLAGS) $(INCS) $(LIBS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/dots/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/hooks/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/reader/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	@echo "\033[91m\033[1m[1/4] \033[97m\033[1mll3d clean:\033[0m"
	@$(MAKE) -C $(LL3D_DIR) clean
	@echo "\033[91m\033[1m[2/4] \033[97m\033[1mmlx clean:\033[0m"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[91m\033[1m[3/4] \033[97m\033[1mlibft clean:\033[0m"
	@$(MAKE) -C $(FT_DIR) clean
	@echo "\033[91m\033[1m[4/4] \033[97m\033[1mobjects folder delete:\033[0m"
	rm -rf $(OBJ_DIR)
	@echo "\033[92m\033[1m---> CLEAN DONE\033[0m\033[0m"

fclean:
	rm -rf $(OBJ_DIR)
	@echo "\033[91m\033[1m[1/4] \033[97m\033[1mll3d full clean:\033[0m"
	@$(MAKE) -C $(LL3D_DIR) fclean
	@echo "\033[91m\033[1m[2/4] \033[97m\033[1mmlx full clean:\033[0m"
	@echo "\033[91m\033[1m[3/4] \033[97m\033[1mlibft full clean:\033[0m"
	@$(MAKE) -C $(FT_DIR) fclean
	@echo "\033[91m\033[1m[4/4] \033[97m\033[1mexecutable delete:\033[0m"
	rm -f $(NAME)
	@echo "\033[92m\033[1m---> FCLEAN DONE\033[0m\033[0m"

re: fclean all
	@echo "\033[92m\033[1m---> RE DONE\033[0m\033[0m"

.PHONY: all clean fclean re
