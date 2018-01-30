/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 23:50:45 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/27 23:50:46 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_one(t_fdf *fdf, t_bre *bre)
{
	ft_fill_pixel(fdf, bre->x, bre->y, fdf->color);
	bre->e = 2 * bre->dy - bre->dx;
	bre->inc1 = 2 * (bre->dy - bre->dx);
	bre->inc2 = 2 * bre->dy;
	bre->i = 0;
	while (bre->i < bre->dx)
	{
		if (bre->e >= 0)
		{
			bre->y += bre->incy;
			bre->e += bre->inc1;
		}
		else
			bre->e += bre->inc2;
		bre->x += bre->incx;
		ft_fill_pixel(fdf, bre->x, bre->y, fdf->color);
		bre->i++;
	}
}

void	ft_two(t_fdf *fdf, t_bre *bre)
{
	ft_fill_pixel(fdf, bre->x, bre->y, fdf->color);
	bre->e = 2 * bre->dx - bre->dy;
	bre->inc1 = 2 * (bre->dx - bre->dy);
	bre->inc2 = 2 * bre->dx;
	bre->i = 0;
	while (bre->i < bre->dy)
	{
		if (bre->e >= 0)
		{
			bre->x += bre->incx;
			bre->e += bre->inc1;
		}
		else
			bre->e += bre->inc2;
		bre->y += bre->incy;
		ft_fill_pixel(fdf, bre->x, bre->y, fdf->color);
		bre->i++;
	}
}

void	ft_links(t_pixel *src, t_pixel *dst, t_fdf *fdf)
{
	t_bre bre;

	if (fdf->links == 0)
		return ;
	bre.dx = (dst->x - src->x < 0) ? -(dst->x - src->x) : dst->x - src->x;
	bre.dy = (dst->y - src->y < 0) ? -(dst->y - src->y) : dst->y - src->y;
	bre.incx = (dst->x < src->x) ? -1 : 1;
	bre.incy = (dst->y < src->y) ? -1 : 1;
	bre.x = src->x;
	bre.y = src->y;
	if (bre.dx > bre.dy)
		ft_one(fdf, &bre);
	else
		ft_two(fdf, &bre);
}
