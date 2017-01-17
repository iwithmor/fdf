/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:24:30 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/04 19:24:31 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./libft/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>

/*
**	GLOBAL VARIABLES
*/
# define TITLE			"FDF Window"
# define WINDOW_WIDTH	1000
# define WINDOW_HEIGHT	1000

/*
**	KEYS
*/
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126
# define W		13
# define A		0
# define S		1
# define D		2
# define PLUS	69
# define MINUS	78
# define R		15

/*
**	COLORS
*/
# define RED	0xFF0000
# define YELLOW	0xFFFF00
# define WHITE	0xFFFFFF
# define PINK	0xFF66B2
# define BLUE	0x6666FF

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}				t_point;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		graph_width;
	int		graph_height;
	int		origin_x;
	int		origin_y;
	int		depth;
	int		max_z;
	int		min_z;
	int		view_x;
	int		view_y;
	t_point	*lst;
}				t_mlx;

void			fdf(t_point *lst);
void			draw_graph(t_mlx *data);
void			draw_vertical_lines(t_mlx *data);
void			draw_horizontal_lines(t_mlx *data);
int				handle_key(int keycode, t_mlx *data);
void			draw_graph(t_mlx *data);
int				rotate_left(t_mlx *data);
int				rotate_right(t_mlx *data);
int				rotate_down(t_mlx *data);
int				rotate_up(t_mlx *data);
int				move_left(t_mlx *data);
int				move_right(t_mlx *data);
int				move_down(t_mlx *data);
int				move_up(t_mlx *data);
int				reset_and_draw(t_mlx *data);
float			calculate_x(t_mlx *mlx, t_point *p1);
float			calculate_y(t_mlx *mlx, t_point *p1);
t_mlx			*reset(t_mlx *data);
void			connect_vertical(t_mlx *data, t_point *p1, t_point *p2);
void			connect_x(t_mlx *data, t_point *p1, t_point *p2);
void			connect_y(t_mlx *data, t_point *p1, t_point *p2);

#endif
