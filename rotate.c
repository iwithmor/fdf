/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:51:14 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/13 21:51:16 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_left(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->view_x += 1;
	data->view_y += 1;
	draw_graph(data);
	return (0);
}

int	rotate_right(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->view_x -= 1;
	data->view_y -= 1;
	draw_graph(data);
	return (0);
}

int	rotate_up(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->view_x += 1;
	data->view_y -= 1;
	draw_graph(data);
	return (0);
}

int	rotate_down(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->view_x -= 1;
	data->view_y += 1;
	draw_graph(data);
	return (0);
}

int	reset_and_draw(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data = reset(data);
	draw_graph(data);
	return (0);
}
