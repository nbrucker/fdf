/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:01:58 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/19 13:01:59 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	ft_set_movement(t_fdf *fdf, int mov)
{
	fdf->movement = mov;
	ft_putstr("pas : ");
	ft_putnbr(fdf->movement);
	ft_putchar('\n');
}

void	ft_up(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->y -= fdf->movement;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_down(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->y += fdf->movement;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_left(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->x -= fdf->movement;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}

void	ft_right(t_fdf *fdf)
{
	fdf->pixel = ft_rewind(fdf->pixel);
	while (fdf->pixel)
	{
		fdf->pixel->x += fdf->movement;
		if (fdf->pixel->next == NULL)
			break ;
		fdf->pixel = fdf->pixel->next;
	}
	ft_less_ligne(fdf);
}
