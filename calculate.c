/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 23:14:28 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/16 23:14:30 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calculate_x(t_mlx *data, t_point *p1)
{
	float x;
	float y;

	if (!data)
		return (0);
	x = (float)p1->x;
	y = (float)p1->y;
	return ((x - y) * data->view_x + data->origin_x);
}

float	calculate_y(t_mlx *data, t_point *p1)
{
	float	x;
	float	y;
	float	z;
	int		depth;

	if (!data)
		return (0);
	x = (float)p1->x;
	y = (float)p1->y;
	z = (float)p1->z;
	depth = data->depth;
	return ((x + y) * data->view_y + data->origin_y - z * depth);
}
