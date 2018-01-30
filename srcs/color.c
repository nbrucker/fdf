/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:35:26 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/19 11:35:27 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void	ft_text_next(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 270, 0x00FFFFFF, "s : down");
	mlx_string_put(fdf->mlx, fdf->win, 10, 300, 0x00FFFFFF, "d : right");
	mlx_string_put(fdf->mlx, fdf->win, 10, 330, 0x00FFFFFF, "a : left");
	mlx_string_put(fdf->mlx, fdf->win, 10, 360, 0x00FFFFFF, "8 : z +");
	mlx_string_put(fdf->mlx, fdf->win, 10, 390, 0x00FFFFFF, "2 : z -");
	mlx_string_put(fdf->mlx, fdf->win, 10, 420, 0x00FFFFFF, ". : links");
	mlx_string_put(fdf->mlx, fdf->win, 200, 0, 0x00FFFFFF,
	"haut :rotation");
	mlx_string_put(fdf->mlx, fdf->win, 200, 30, 0x00FFFFFF,
	"bas : rotation");
	mlx_string_put(fdf->mlx, fdf->win, 200, 60, 0x00FFFFFF,
	"gauche : rotation");
	mlx_string_put(fdf->mlx, fdf->win, 200, 90, 0x00FFFFFF,
	"droite : rotation");
	mlx_string_put(fdf->mlx, fdf->win, 200, 120, 0x00FFFFFF,
	"4 : rotation");
	mlx_string_put(fdf->mlx, fdf->win, 200, 150, 0x00FFFFFF,
	"6 : rotation");
}

void	ft_text(t_fdf *fdf)
{
	if (fdf->info == 0)
		mlx_string_put(fdf->mlx, fdf->win, 10, 0, 0x00FFFFFF, "info : i");
	else
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		mlx_string_put(fdf->mlx, fdf->win, 10, 0, 0x00FFFFFF, "r : red");
		mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0x00FFFFFF, "g : green");
		mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0x00FFFFFF, "b : blue");
		mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0x00FFFFFF, "k : black");
		mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0x00FFFFFF,
		"space : white");
		mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0x00FFFFFF, "p : pink");
		mlx_string_put(fdf->mlx, fdf->win, 10, 180, 0x00FFFFFF, "q : pas +");
		mlx_string_put(fdf->mlx, fdf->win, 10, 210, 0x00FFFFFF, "e : pas -");
		mlx_string_put(fdf->mlx, fdf->win, 10, 240, 0x00FFFFFF, "w : up");
		ft_text_next(fdf);
	}
}

void	ft_color(t_fdf *fdf, int color)
{
	fdf->color = color;
	fdf->pixel = ft_rewind(fdf->pixel);
	ft_putpoint(fdf);
	ft_putlinks(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_text(fdf);
}
