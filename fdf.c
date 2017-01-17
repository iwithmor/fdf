/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:26:10 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/08 17:26:12 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_width(t_point *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->x);
}

int		get_height(t_point *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->y);
}

int		get_max_z(t_point *lst)
{
	int	max_z;

	max_z = lst->z;
	while (lst->next)
	{
		max_z = (lst->next->z > max_z)? lst->next->z : max_z;
		lst = lst->next;
	}
	printf("max_z = %d\n", max_z);
	return (max_z);
}

t_mlx	*reset(t_mlx *data)
{
	data->view_x = 23;
	data->view_y = 17;
	data->origin_x = WINDOW_WIDTH / 4;
	data->origin_y = WINDOW_HEIGHT / 10;
	data->depth = 3;
	return (data);
}

void	fdf(t_point *lst)
{
	void	*mlx;
	void	*win;
	t_mlx	*data;

	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		perror(strerror(errno));
		return ;
	}
	mlx = mlx_init();
	data->mlx = mlx;
	data->graph_width = get_width(lst);
	data->graph_height = get_height(lst);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	data->win = win;
	data->lst = lst;
	data->max_z = get_max_z(lst);
	data = reset(data);
	draw_graph(data);
	mlx_key_hook(win, handle_key, data);
	mlx_loop(mlx);
}
