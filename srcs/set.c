/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:40:24 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/19 13:40:24 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	ft_check_value(t_line *line)
{
	t_line	*start;
	int		x;
	int		i;
	char	*str;

	start = line;
	x = -1;
	while (line && line->value[0])
	{
		i = 0;
		while (line->value[i])
		{
			str = ft_itoa(ft_atoi(line->value[i]));
			if (ft_strcmp(str, line->value[i]) != 0)
				ft_error("Not a valid file !");
			free(str);
			i++;
		}
		if (x != -1 && x != i)
			ft_error("Not a valid file !");
		x = i;
		line = line->next;
	}
	if (x == -1)
		ft_error("Not a valid file !");
}

void	ft_setvalue(t_fdf *fdf, t_line *line)
{
	t_line *start;

	start = line;
	while (line)
	{
		line->value = ft_strsplit(line->str, ' ');
		line = line->next;
	}
	ft_check_value(start);
	ft_setstep(fdf, start);
	fdf->pixel = ft_getpixel(start, fdf);
	ft_setpixel_links(fdf->pixel);
}

void	ft_setstep(t_fdf *fdf, t_line *line)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (line->value[x])
		x++;
	x--;
	while (line && line->next)
	{
		y++;
		line = line->next;
	}
	y--;
	fdf->step_x = 600 / (float)x;
	fdf->step_y = 400 / (float)y;
}

void	ft_setpixel_links(t_pixel *pixel)
{
	while (pixel)
	{
		if (pixel->next != NULL && pixel->next->y == pixel->y)
			pixel->right = pixel->next;
		else
			pixel->right = NULL;
		pixel->down = ft_getpixeldown(pixel);
		pixel = pixel->next;
	}
}

t_pixel	*ft_setpixel(float x, float y, float z, t_pixel *el)
{
	t_pixel	*new;

	if ((new = (t_pixel*)malloc(sizeof(t_pixel))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->init = z;
	new->z = z;
	if (el)
	{
		el->next = new;
		new->previous = el;
	}
	else
		new->previous = NULL;
	new->next = NULL;
	return (new);
}
