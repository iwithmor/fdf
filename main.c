/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:13:25 by iwithmor          #+#    #+#             */
/*   Updated: 2016/12/02 20:13:27 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	remove_lastnode(t_point *lst)
{
	while (lst->next)
	{
		if (!lst->next->next)
		{
			free(lst->next);
			lst->next = NULL;
			return ;
		}
		lst = lst->next;
	}
}

char	*move_string(char *str)
{
	while (*str > 0 && (*str < 33 || *str == 127))
	{
		if (!(*str))
			break ;
		++str;
	}
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		if (!(*str))
			break ;
		++str;
	}
	return (str);
}

t_point	*store_coordinates(t_point *lst, int y, char *arr_z)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (*arr_z && contains_digits(arr_z))
	{
		lst->x = x;
		lst->y = y;
		lst->z = ft_atoi(arr_z);
		lst->next = (t_point *)malloc(sizeof(t_point));
		if (!(lst->next))
			return (NULL);
		lst = lst->next;
		arr_z = move_string(arr_z);
		++x;
	}
	return (lst);
}

t_point	*read_and_store(int fd)
{
	char	*line;
	int		row;
	t_point	*lst;
	t_point	*lst_cpy;

	row = 0;
	if (!(lst = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	lst_cpy = lst;
	while (get_next_line(fd, &line) > 0)
	{
		lst = store_coordinates(lst, row, line);
		free(line);
		++row;
	}
	remove_lastnode(lst_cpy);
	return (lst_cpy);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putstr("usage: ./fdf file_name");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() error");
			return (1);
		}
		fdf(read_and_store(fd));
		if (close(fd) == -1)
		{
			ft_putstr("close() error");
			return (1);
		}
	}
	return (0);
}
