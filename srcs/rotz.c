/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 03:39:50 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/28 03:39:50 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_nz(t_fdf *fdf)
{
	float x;
	float y;
	float x_dif;
	float y_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	x_dif = 350 - ((350 * cos(M_PI / 30)) + (250 * sin(M_PI / 30)));
	y_dif = 250 - (-(350 * sin(M_PI / 30)) + (250 * cos(M_PI / 30)));
	while (fdf->pixel)
	{
		x = (fdf->pixel->x * cos(M_PI / 30)) + (fdf->pixel->y * sin(M_PI / 30));
		y = -(fdf->pixel->x * sin(M_PI / 30)) +
		(fdf->pixel->y * cos(M_PI / 30));
		y += y_dif;
		x += x_dif;
		fdf->pixel->x = x;
		fdf->pixel->y = y;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_rot_z(t_fdf *fdf)
{
	float x;
	float y;
	float x_dif;
	float y_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	x_dif = 350 - ((350 * cos(M_PI / 30)) - (250 * sin(M_PI / 30)));
	y_dif = 250 - ((350 * sin(M_PI / 30)) + (250 * cos(M_PI / 30)));
	while (fdf->pixel)
	{
		x = (fdf->pixel->x * cos(M_PI / 30)) - (fdf->pixel->y * sin(M_PI / 30));
		y = (fdf->pixel->x * sin(M_PI / 30)) + (fdf->pixel->y * cos(M_PI / 30));
		y += y_dif;
		x += x_dif;
		fdf->pixel->x = x;
		fdf->pixel->y = y;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}
