/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:59:17 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/04 15:59:17 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	ft_putpoint(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		ft_fill_pixel(fdf, fdf->pixel->x, fdf->pixel->y, fdf->color);
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	fdf->pixel = ft_rewind(fdf->pixel);
}

void	ft_putlinks(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		if (fdf->pixel->right)
			ft_links(fdf->pixel, fdf->pixel->right, fdf);
		if (fdf->pixel->down)
			ft_links(fdf->pixel, fdf->pixel->down, fdf);
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	fdf->pixel = ft_rewind(fdf->pixel);
}

void	ft_display(t_fdf *fdf)
{
	int		bpp;
	int		s_l;
	int		endian;

	fdf->color = 0x00FFFFFF;
	ft_set_movement(fdf, 1);
	fdf->image = mlx_new_image(fdf->mlx, 700, 500);
	fdf->str = mlx_get_data_addr(fdf->image, &bpp, &s_l, &endian);
	ft_putpoint(fdf);
	ft_putlinks(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_text(fdf);
}

int		ft_exit(t_fdf *fdf)
{
	(void)fdf;
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;
	t_line	*line;

	if (argc != 2)
		ft_error("I want a file !");
	fdf.mlx = mlx_init();
	fdf.links = 1;
	fdf.info = 0;
	fdf.win = mlx_new_window(fdf.mlx, 700, 500, "fdf");
	line = ft_get(argv[1]);
	ft_setvalue(&fdf, line);
	ft_display(&fdf);
	mlx_hook(fdf.win, 2, 3, ft_input, &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, ft_exit, &fdf);
	mlx_expose_hook(fdf.win, ft_less_ligne, &fdf);
	mlx_loop(fdf.mlx);
	(void)argc;
	(void)argv;
	return (0);
}
