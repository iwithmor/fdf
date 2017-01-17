/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 02:03:11 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/12 02:03:13 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx *data, t_point *p1, t_point *p2)
{
	if (!p1 || !p2)
		return ;
	if (calculate_x(data, p1) == calculate_x(data, p2))
	{
		if (calculate_y(data, p2) > calculate_y(data, p1))
			connect_vertical(data, p1, p2);
		else
			connect_vertical(data, p2, p1);
	}
	else
	{
		if (calculate_x(data, p2) > calculate_x(data, p1))
			connect_x(data, p1, p2);
		else
			connect_x(data, p2, p1);
		if (calculate_y(data, p2) > calculate_y(data, p1))
			connect_y(data, p1, p2);
		else
			connect_y(data, p2, p1);
	}
}

void	draw_horizontal_lines(t_mlx *data)
{
	void	*mlx;
	void	*win;
	t_point *lst;

	mlx = data->mlx;
	win = data->win;
	lst = data->lst;
	while (lst->next)
	{
		if (lst->y == lst->next->y)
			draw_line(data, lst, lst->next);
		lst = lst->next;
	}
}

void	draw_vertical_lines(t_mlx *data)
{
	void	*mlx;
	void	*win;
	t_point *p1;
	t_point *p2;
	int		i;

	mlx = data->mlx;
	win = data->win;
	p1 = data->lst;
	i = 0;
	while (p1)
	{
		p2 = p1->next;
		while (p2 && p2->x != p1->x)
			p2 = p2->next;
		draw_line(data, p1, p2);
		p1 = p1->next;
	}
}

void	draw_graph(t_mlx *data)
{
	draw_vertical_lines(data);
	draw_horizontal_lines(data);
}
