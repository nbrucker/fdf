/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:51:01 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/19 11:51:02 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int		ft_less_ligne(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	ft_back_in_black(fdf);
	ft_putpoint(fdf);
	ft_putlinks(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_text(fdf);
	return (0);
}

void	ft_rotation_left(t_fdf *fdf)
{
	float x;
	float z;
	float x_dif;
	float z_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	x_dif = 350 - ((350 * cos(M_PI / 30)));
	z_dif = 0 - ((350 * sin(M_PI / 30)));
	while (fdf->pixel)
	{
		x = (fdf->pixel->x * cos(M_PI / 30)) - (fdf->pixel->z * sin(M_PI / 30));
		z = (fdf->pixel->x * sin(M_PI / 30)) + (fdf->pixel->z * cos(M_PI / 30));
		z += z_dif;
		x += x_dif;
		fdf->pixel->x = x;
		fdf->pixel->z = z;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_rotation_right(t_fdf *fdf)
{
	float x;
	float z;
	float x_dif;
	float z_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	x_dif = 350 - ((350 * cos(M_PI / 30)));
	z_dif = 0 - (-(350 * sin(M_PI / 30)));
	while (fdf->pixel)
	{
		x = (fdf->pixel->x * cos(M_PI / 30)) + (fdf->pixel->z * sin(M_PI / 30));
		z = -(fdf->pixel->x * sin(M_PI / 30)) +
		(fdf->pixel->z * cos(M_PI / 30));
		z += z_dif;
		x += x_dif;
		fdf->pixel->x = x;
		fdf->pixel->z = z;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_rotation_haut(t_fdf *fdf)
{
	float y;
	float z;
	float y_dif;
	float z_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	y_dif = 250 - ((250 * cos(M_PI / 30)));
	z_dif = 0 - (-(250 * sin(M_PI / 30)));
	while (fdf->pixel)
	{
		y = (fdf->pixel->y * cos(M_PI / 30)) + (fdf->pixel->z * sin(M_PI / 30));
		z = -(fdf->pixel->y * sin(M_PI / 30)) +
		(fdf->pixel->z * cos(M_PI / 30));
		z += z_dif;
		y += y_dif;
		fdf->pixel->y = y;
		fdf->pixel->z = z;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_rotation_bas(t_fdf *fdf)
{
	float y;
	float z;
	float y_dif;
	float z_dif;

	fdf->pixel = ft_rewind(fdf->pixel);
	y_dif = 250 - ((250 * cos(M_PI / 30)));
	z_dif = 0 - ((250 * sin(M_PI / 30)));
	while (fdf->pixel)
	{
		y = (fdf->pixel->y * cos(M_PI / 30)) - (fdf->pixel->z * sin(M_PI / 30));
		z = (fdf->pixel->y * sin(M_PI / 30)) + (fdf->pixel->z * cos(M_PI / 30));
		z += z_dif;
		y += y_dif;
		fdf->pixel->y = y;
		fdf->pixel->z = z;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}
