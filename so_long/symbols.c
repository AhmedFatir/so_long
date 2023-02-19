/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:54:27 by afatir            #+#    #+#             */
/*   Updated: 2023/02/13 14:52:33 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_chekmap(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i <= 4 || str[i - 1] != 'r' || str[i - 2] != 'e' \
		|| str[i - 3] != 'b' || str[i - 4] != '.')
		return (0);
	return (1);
}

void	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free(data, 7);
}

int	ft_clct(t_data *data)
{
	if (ft_symbols(data) == 0)
	{
		ft_printf("||||||||| YOU WIN ||||||||||\n");
		ft_close(data);
	}
	return (0);
}

int	ft_symbols(t_data *data)
{
	t_var		s;

	s.e = 0;
	s.p = 0;
	s.l = 0;
	data->clct = 0;
	while (data->map[s.l])
	{
		s.c = 0;
		while (data->map[s.l][s.c])
		{
			if (data->map[s.l][s.c] == 'P')
				s.p += 1;
			else if (data->map[s.l][s.c] == 'C')
				data->clct += 1;
			else if (data->map[s.l][s.c] == 'E')
				s.e += 1;
			s.c++;
		}
		s.l++;
	}
	if (s.p != 1 || data->clct == 0 || s.e != 1)
		return (0);
	return (1);
}

int	e_valid_path(char **p)
{
	t_var	v;

	v.flag = 0;
	v.y = 0;
	while (p[v.y])
	{
		v.x = 0;
		while (p[v.y][v.x])
		{
			if (p[v.y][v.x] == 'E')
			{
				v.flag = 1;
				break ;
			}
			v.x++;
		}
		if (v.flag == 1)
			break ;
		v.y++;
	}
	if (p[v.y][v.x - 1] == '1' && p[v.y][v.x + 1] == '1' \
		&& p[v.y - 1][v.x] == '1' && p[v.y + 1][v.x] == '1')
		return (0);
	return (1);
}
