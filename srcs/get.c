/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:40:20 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/05 12:40:20 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_line	*ft_get(char *name)
{
	int		fd;
	int		gnl;
	t_line	*new;
	t_line	*start;
	t_line	*previous;

	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error opening file !");
	previous = NULL;
	start = NULL;
	while (start == NULL || gnl > 0)
	{
		if ((new = (t_line*)malloc(sizeof(t_line))) == NULL)
			return (NULL);
		if ((gnl = get_next_line(fd, &(new->str))) == -1)
			ft_error("error reading file !");
		if (start == NULL)
			start = new;
		if (previous)
			previous->next = new;
		new->next = NULL;
		previous = new;
	}
	return (start);
}

t_pixel	*ft_rewind(t_pixel *el)
{
	while (el && el->previous)
		el = el->previous;
	return (el);
}

t_pixel	*ft_getpixel(t_line *line, t_fdf *fdf)
{
	t_pixel		*new;
	float		x;
	float		y;
	int			i;

	y = 50;
	new = NULL;
	while (line)
	{
		i = 0;
		x = 50;
		while (line->value[i])
		{
			new = ft_setpixel(x, y, ft_atoi(line->value[i]), new);
			x += fdf->step_x;
			i++;
		}
		y += fdf->step_y;
		line = line->next;
	}
	return (ft_rewind(new));
}

t_pixel	*ft_getpixeldown(t_pixel *pixel)
{
	int		i;
	float	x;

	i = 0;
	x = pixel->x;
	pixel = pixel->next;
	while (pixel && pixel->x != x)
	{
		pixel = pixel->next;
		i++;
	}
	return (pixel);
}
