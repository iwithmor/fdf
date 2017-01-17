/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:08:45 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/19 00:08:47 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_y(t_mlx *data, double current, t_point *p1, t_point *p2)
{
	double	start;
	double	end;
	double	percent;

	if (p1->z == 0 && p2->z == 0)
		return (WHITE);
	if (p1->z == data->max_z && p2->z == data->max_z)
		return (PINK);
	start = calculate_y(data, p1);
	end = calculate_y(data, p2);
	if (start == end)
		return (PINK);
	percent = (current - start) / (end - start);
	return (percent * YELLOW + (1 - percent) * PINK);
}

int		color_x(t_mlx *data, double current, t_point *p1, t_point *p2)
{
	double	start;
	double	end;
	double	percent;

	if (p1->z == 0 && p2->z == 0)
		return (WHITE);
	if (p1->z == data->max_z && p2->z == data->max_z)
		return (PINK);
	start = calculate_x(data, p1);
	end = calculate_x(data, p2);
	if (start == end)
		return (PINK);
	percent = (current - start) / (end - start);
	return (percent * YELLOW + (1 - percent) * PINK);
}

void	connect_vertical(t_mlx *data, t_point *p1, t_point *p2)
{
	double	x;
	double	y1;
	double	y2;
	double	start;

	x = calculate_x(data, p1);
	y1 = calculate_y(data, p1);
	y2 = calculate_y(data, p2);
	start = y1;
	while (y1 != y2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y1, color_y(data, y1, p1, p2));
		++y1;
	}
	mlx_pixel_put(data->mlx, data->win, x, y1, color_y(data, y1, p1, p2));
}

void	connect_x(t_mlx *data, t_point *p1, t_point *p2)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	slope;
	double	start;

	x1 = calculate_x(data, p1);
	x2 = calculate_x(data, p2);
	y1 = calculate_y(data, p1);
	y2 = calculate_y(data, p2);
	slope = (y2 - y1) / (x2 - x1);
	start = x1;
	while (x1 != x2)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, color_x(data, x1, p1, p2));
		y1 += slope;
		++x1;
	}
	mlx_pixel_put(data->mlx, data->win, x1, y1, color_x(data, x1, p1, p2));
}

void	connect_y(t_mlx *data, t_point *p1, t_point *p2)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	slope;
	double	start;

	x1 = calculate_x(data, p1);
	x2 = calculate_x(data, p2);
	y1 = calculate_y(data, p1);
	y2 = calculate_y(data, p2);
	slope = (x2 - x1) / (y2 - y1);
	start = y1;
	while (y1 != y2)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, color_y(data, y1, p1, p2));
		x1 += slope;
		++y1;
	}
	mlx_pixel_put(data->mlx, data->win, x1, y1, color_y(data, y1, p1, p2));
}
