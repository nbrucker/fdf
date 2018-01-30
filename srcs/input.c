/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:40:01 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/05 12:40:01 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	ft_less_z(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->y += fdf->pixel->init;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	fdf->pixel = ft_rewind(fdf->pixel);
	ft_back_in_black(fdf);
	ft_putpoint(fdf);
	ft_putlinks(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_text(fdf);
}

void	ft_more_z(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->y -= fdf->pixel->init;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	fdf->pixel = ft_rewind(fdf->pixel);
	ft_back_in_black(fdf);
	ft_putpoint(fdf);
	ft_putlinks(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_text(fdf);
}

void	ft_input_next_next(int key, t_fdf *fdf)
{
	if (key == 0)
		ft_left(fdf);
	else if (key == 1)
		ft_down(fdf);
	else if (key == 2)
		ft_right(fdf);
	else if (key == 12)
		ft_set_movement(fdf, fdf->movement + 1);
	else if (key == 14)
		ft_set_movement(fdf, fdf->movement - 1);
	else if (key == 86)
		ft_rot_z(fdf);
	else if (key == 88)
		ft_rot_nz(fdf);
}

void	ft_input_next(int key, t_fdf *fdf)
{
	if (key == 124)
		ft_rotation_right(fdf);
	else if (key == 40)
		ft_color(fdf, 0);
	else if (key == 91)
		ft_more_z(fdf);
	else if (key == 84)
		ft_less_z(fdf);
	else if (key == 5)
		ft_color(fdf, 0x0000FF00);
	else if (key == 15)
		ft_color(fdf, 0x00FF0000);
	else if (key == 11)
		ft_color(fdf, 0x000000FF);
	else if (key == 35)
		ft_color(fdf, 0xFF358B);
	else if (key == 49)
		ft_color(fdf, 0x00FFFFFF);
	else if (key == 13)
		ft_up(fdf);
	else
		ft_input_next_next(key, fdf);
}

int		ft_input(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 34)
		fdf->info = (fdf->info == 0) ? 1 : 0;
	if (fdf->info == 1)
	{
		ft_text(fdf);
		return (0);
	}
	else
		ft_less_ligne(fdf);
	if (key == 125)
		ft_rotation_bas(fdf);
	else if (key == 126)
		ft_rotation_haut(fdf);
	else if (key == 123)
		ft_rotation_left(fdf);
	else if (key == 65)
		fdf->links = (fdf->links == 0) ? 1 : 0;
	else
		ft_input_next(key, fdf);
	if (key == 65)
		ft_less_ligne(fdf);
	return (0);
}
