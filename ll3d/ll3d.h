/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:56:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:01:48 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL3D_H
# define LL3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define CAM_2D			0
# define CAM_3D			1

# define CAM_DSP		1
# define CAM_DSE		5
# define CAM_DFO		4

# define CAM_SP			0.1
# define CAM_SE			1
# define CAM_FO			0.1

# define SCREEN_X		800
# define SCREEN_Y		800

typedef struct			s_vec2
{
	int					x;
	int					y;
}						t_vec2;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_vec4
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_vec4;

typedef struct			s_mtx4
{
	double				val[4][4];
}						t_mtx4;

typedef struct			s_image
{
	void				*image;
	char				*ptr;
	int					bpp;
	int					str;
	int					end;
	int					x;
	int					y;
}						t_image;

typedef struct			s_mlx
{
	int					width;
	int					height;
	t_image				*image;
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct			s_cam
{
	t_mtx4				*cam;
	t_vec3				*piv;
	int					mode;
	double				speed;
	double				ppu;
	double				sence;
	double				focus;
}						t_cam;

typedef struct			s_dots
{
	int					i;
	int					xc;
	int					yc;
	int					zmin;
	int					zmax;
	int					cm;
	t_vec4				**wb;
	t_vec3				**cb;
	t_vec2				**sb;
}						t_dots;

t_vec2					*vec2_init(void);
t_vec2					*vec2_new(const int x, const int y);
t_vec2					*vec2_sum(const t_vec2 *v1, const t_vec2 *v2);
t_vec2					*vec2_mult(const t_vec2 *v, const int s);
t_vec2					*vec2_copy(const t_vec2 *v);
void					vec2_print(const t_vec2 *v);
void					vec2_set(t_vec2 *v, const int x, const int y);

t_vec3					*vec3_init(void);
t_vec3					*vec3_new(const double x, const double y,
							const double z);
t_vec3					*vec3_sum(const t_vec3 *v1, const t_vec3 *v2);
t_vec3					*vec3_mult(const t_vec3 *v, const double s);
t_vec3					*vec3_copy(const t_vec3 *v);
void					vec3_print(const t_vec3 *v);
void					vec3_set(t_vec3 *v, const double x, const double y,
							const double z);
int						vec3_eq(const t_vec3 *v1, const t_vec3 *v2);

t_vec4					*vec4_init(void);
t_vec4					*vec4_new(const double x, const double y,
							const double z, const double w);
t_vec4					*vec4_sum(const t_vec4 *v1, const t_vec4 *v2);
t_vec4					*vec4_mult(const t_vec4 *v, const double s);
t_vec4					*vec4_copy(const t_vec4 *v);
void					vec4_print(const t_vec4 *v);
t_vec4					**dots4_cpy(const t_vec4 **src, const int xc,
						const int yc);

int						ft_abs(const int x);
int						ft_sign(const double a);
double					ft_fabs(const double x);
void					ft_swap(int *a, int *b);
double					ft_fmin(const double a, const double b);
int						ft_min(const int a, const int b);
double					ft_fmax(const double a, const double b);
int						ft_max(const int a, const int b);

t_mtx4					*mtx4_init(const double val);
void					mtx4_clear(t_mtx4 *mtx);
t_mtx4					*mtx4_copy(const t_mtx4 *src);
void					mtx4_print(const t_mtx4 *src);
t_mtx4					*mtx4x3_mult(const t_mtx4 *a, const t_mtx4 *b,
						t_mtx4 *dst);
t_mtx4					*mtx4x4_mult(const t_mtx4 *a, const t_mtx4 *b,
						t_mtx4 *dst);
t_mtx4					*mtx4_get_rotation(const double x, const double y,
						const double z, const double a);

t_cam					*camera_init(void);
void					camera_move_x(t_cam *cam, const double a);
void					camera_move_y(t_cam *cam, const double a);
void					camera_move_z(t_cam *cam, const double a);
void					camera_rotate_x(t_cam *cam, const double a);
void					camera_rotate_y(t_cam *cam, const double a);
void					camera_rotate_custom(t_cam *cam, const t_vec3 *p,
						const t_vec3 *axis, const double a);
void					camera_per_calc_piv(t_cam *cam);

void					dots_fill_cb(const t_vec4 *p, const t_mtx4 *c,
						t_vec3 *res);
void					dots_fill_sb_iso(const t_vec3 *p, t_vec2 *res,
						const double f);
void					dots_fill_sb_per(const t_vec3 *point, t_vec2 *res,
						const t_cam *cam);
t_dots					*dots_init(const int x, const int y);
int						dots_print(t_dots *res);
void					dots_scale_y(t_dots *dots, const double s);
void					dots_color_update(t_dots *dots);

void					image_clear(t_image *img);
t_image					*image_init(t_mlx *mlx, const int x, const int y);
void					image_set_pixel(t_image *img, const int x, const int y,
						const int c);
int						image_draw_line(const t_mlx *mlx, const t_vec2 *v1,
						const t_vec2 *v2, const t_vec2 *c);
int						image_draw_line2(const t_mlx *mlx, int *t,
						unsigned short *dt);
void					image_free(t_image **img);

t_mlx					*mlx_init_ll3d(const int width, const int height,
						char *header);
t_mlx					*mlx_free_ll3d(t_mlx **mlx);

void					oclude_x(t_vec2 *d1, t_vec2 *d2);
void					oclude_y(t_vec2 *d1, t_vec2 *d2);
void					oclude_z(t_vec2 *d1, t_vec2 *d2, double z1, double z2);
void					oclusion_draw_line(const t_mlx *c, t_dots *d,
							int d1, int d2);
int						check_out(const t_dots *d, const int d1, const int d2);
int						swap_if_d2_less(t_vec2 **d1, t_vec2 **d2,
							const double d1v, const double d2v);

int						color_lerp(int c1, int c2, double step);
int						color_get_default(const int z, const int cm);
int						color_set_br(const int c, double br);

#endif
