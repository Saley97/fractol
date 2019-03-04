# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/31 20:35:25 by sbednar           #+#    #+#              #
#    Updated: 2019/03/04 09:08:18 by edraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libll3d.a

SRC_DIR		=	./src
OBJ_DIR		=	./obj

SRC			=	vec2_init.c \
				vec2_new.c \
				vec2_sum.c \
				vec2_mult.c \
				vec2_copy.c \
				vec2_print.c \
				vec3_init.c \
				vec3_new.c \
				vec3_sum.c \
				vec3_mult.c \
				vec3_copy.c \
				vec3_eq.c \
				vec3_print.c \
				vec4_init.c \
				vec4_new.c \
				vec4_sum.c \
				vec4_mult.c \
				vec4_copy.c \
				vec4_print.c \
				ft_abs.c \
				ft_fabs.c \
				ft_sign.c \
				mtx4_init.c \
				mtx4_clear.c \
				mtx4_copy.c \
				mtx4_print.c \
				mtx4x3_mult.c \
				mtx4x4_mult.c \
				mtx4_get_rotation.c \
				camera_init.c \
				camera_move_x.c \
				camera_move_y.c \
				camera_move_z.c \
				camera_rotate_x.c \
				camera_rotate_y.c \
				camera_rotate_custom.c \
				camera_per_calc_piv.c \
				dots_fill_cb.c \
				dots_fill_sb_iso.c \
				dots_fill_sb_per.c \
				dots_init.c \
				dots_scale.c \
				dots_color_update.c \
				image_clear.c \
				image_init.c \
				image_set_pixel.c \
				image_draw_line.c \
				image_draw_line2.c \
				mlx_init_ll3d.c \
				color_lerp.c \
				color_set_br.c \
				vec2_set.c \
				ft_min_max.c \
				vec3_set.c \
				oclude_x.c \
				oclude_y.c \
				oclude_z.c \
				oclusion_draw_line.c \
				oclusion_utils.c \
				image_free.c

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
INC			=	-I. -I../libft -I../minilibx

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -o3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/camera/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/color/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/oclusion/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/dots/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/image/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/math/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/mlx/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/mtx4/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/vec2/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/vec3/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/vec4/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
