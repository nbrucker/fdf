/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:40:13 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/05 12:40:14 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_back_in_black(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 700)
		{
			ft_fill_pixel(fdf, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	ft_fill_pixel(t_fdf *fdf, float x, float y, int color)
{
	int i;

	i = (((int)y * 700) + (int)x) * 4;
	if (i < 0 || i >= 700 * 500 * 4)
		return ;
	fdf->str[i] = color & 0xFF;
	fdf->str[i + 1] = (color >> 8) & 0xFF;
	fdf->str[i + 2] = (color >> 16) & 0xFF;
}
