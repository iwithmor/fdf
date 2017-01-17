/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 23:18:28 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/11 23:18:30 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, t_mlx *mlx_data)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT)
		move_left(mlx_data);
	else if (keycode == RIGHT)
		move_right(mlx_data);
	else if (keycode == DOWN)
		move_down(mlx_data);
	else if (keycode == UP)
		move_up(mlx_data);
	else if (keycode == W)
		rotate_up(mlx_data);
	else if (keycode == A)
		rotate_left(mlx_data);
	else if (keycode == S)
		rotate_down(mlx_data);
	else if (keycode == D)
		rotate_right(mlx_data);
	else if (keycode == R)
		reset_and_draw(mlx_data);
	return (0);
}
