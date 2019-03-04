/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:57:07 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 13:38:54 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "libft.h"
# include "ll3d.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>

# define SCREEN_NAME	"fractal"

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_C			8
# define KEY_Q			12
# define KEY_E			14
# define KEY_F			3
# define KEY_R			15
# define KEY_T			17
# define KEY_ESC		53
# define KEY_ARROWL		123
# define KEY_ARROWR		124
# define KEY_ARROWD		125
# define KEY_ARROWU		126
# define KEY_1			83
# define KEY_2			84
# define KEY_3			85
# define KEY_4			86
# define KEY_5			87
# define KEY_6			88
# define KEY_7			89
# define KEY_8			91
# define KEY_H			4
# define KEY_G			5
# define KEY_Y			16
# define KEY_9_U		25
# define KEY_0_U		29
# define KEY_PLUS		24
# define KEY_MINUS		27
# define KEY_M_L		4
# define KEY_M_R		5
# define KEY_M_M		3
# define KEY_PLUS_R		69
# define KEY_MINUS_R	78
# define KEY_L			37
# define KEY_X			7
# define KEY_Z			6
# define KEY_V			9
# define KEY_I			34

# define COLOR_RED		0xFF0000
# define COLOR_BLACK	0x000000
# define COLOR_WHITE	0xFFFFFF

/*
**	type flags for t_fconf
*/

# define JUL_MODE		0
# define MANDEL_MODE	1
# define SHIP_MODE		2

/*
**	set_m flags for t_fconf
*/

# define SET_M_STD		0
# define SET_M_MTX		1
# define SET_M_SPH		2
# define SET_M_SIN		3

/*
**	precalc_m flags for t_fconf
*/

# define PRECALC_M_STD	0
# define PRECALC_M_SIN	1
# define PRECALC_M_ABS	2
# define PRECALC_M_SPH	3
# define PRECALC_M_SINR	4
# define PRECALC_M_SWR	5
# define PRECALC_M_HRS	6
# define PRECALC_M_CRN	7
# define PRECALC_M_PDJ	8

/*
**	calc_m flags for t_fconf
*/

# define CALC_M_2		0
# define CALC_M_3		1

/*
**	lerp_m flags for t_fconf
*/

# define LERP_M_OFF		0
# define LERP_M_ON		1

/*
**	ljul_change_m flags for t_fconf
*/

# define JUL_CH_M_OFF	0
# define JUL_CH_M_ON	1

/*
**	info_m flags for t_fconf
*/

# define INFO_M_OFF		0
# define INFO_M_ON		1

/*
**	play_station_m flags for t_fconf
*/

# define PS_M_OFF		0
# define PS_M_ON		1
# define MAX_PS_N		50

# define FRAC_DDP		128
# define THREADS		16

# define CL_FILE_NAME	"src/colors"

typedef struct			s_cl_list
{
	int					color;
	struct s_cl_list	*n_cl_list;
}						t_cl_list;

typedef struct			s_fconf
{
	double				coef[3][3];
	int					type;
	int					demen;
	int					set_m;
	int					precalc_m;
	int					calc_m;
	int					cur_coef;
	double				m_x;
	double				m_y;
	int					cl_num;
	int					pallet[FRAC_DDP];
	t_cl_list			*cl_list;
	int					lerp_m;
	int					play_station_m;
	int					play_station_n;
	int					jul_change_m;
	int					info_m;
}						t_fconf;

typedef struct			s_threads t_threads;

typedef struct			s_mouse
{
	int					x;
	int					y;
	t_mlx				*mlx;
	t_cam				*cam;
	t_fconf				*f;
	t_threads			*t;
}						t_mouse;

typedef struct			s_thread
{
	int					id;
	t_mouse				*m_data;
}						t_thread;

typedef struct			s_threads
{
	pthread_t			threads[THREADS];
	t_thread			arg[THREADS];
}						t_threads;

void					redraw(t_mouse *mouse);
int						hook_mouse_move(int x, int y, t_mouse *mouse);
int						hook_key(const int key, t_mouse *mouse);
int						hook_wheel(int key, int x, int y, t_mouse *m);

int						get_color(char const *it, const int cm);
int						free_all(char **line, char ***tmp, int fd);

t_mouse					*mouse_init(t_mlx *mlx, t_cam *cam, t_fconf *f);

void					hook_camera_move_x(t_cam *cam, double const a);
void					hook_camera_move_y(t_cam *cam, double const a);
void					hook_camera_move_z(t_cam *cam, double const a);

void					hook_camera_change_speed(t_cam *cam, double const a);
void					hook_camera_change_sence(t_cam *cam, double const a);
void					hook_camera_change_focus(t_cam *cam, double const a);

void					hook_camera_rotate_x(t_cam *cam, double const a);
void					hook_camera_rotate_y(t_cam *cam, double const a);
int						hook_mouse_down(int key, int x, int y, t_mouse *mouse);
int						hook_mouse_move(int x, int y, t_mouse *mouse);

void					hook_frac_control(const int key, t_mouse *m);

int						free_helper(t_mlx **mlx, t_cam **cam, t_mouse **mouse);

void					set_frac(t_fconf *f, char *name);

void					calc_world_from_screen(const t_vec2 *s_p,
							t_vec3 *dst, const t_cam *cam);
int						get_coef(t_vec3 *p, const t_fconf *f);
void					*fill_image(void *t);
void					thread_img_filler(t_mouse *mouse);

void					set_m(t_vec3 *p, const t_fconf *f, const double r2);
void					precalc_m(t_vec3 *z, const t_fconf *f, const double r,
							const double r2);
void					calc_m(t_vec3 *z, const t_fconf *f);

t_cl_list				*set_colors(const char *file);
void					fill_pallet(t_fconf *f);
int						choose_color(const t_fconf *f, const int itter);

void					play_station_on(const t_mouse *m, int itter);

#endif
