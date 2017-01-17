/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:43:36 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/17 17:43:38 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	move_left(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->origin_x -= 10;
	draw_graph(data);
	return (0);
}

int	move_right(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->origin_x += 10;
	draw_graph(data);
	return (0);
}

int	move_up(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->origin_y -= 10;
	draw_graph(data);
	return (0);
}

int	move_down(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->origin_y += 10;
	draw_graph(data);
	return (0);
}
