/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:59:10 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/04 15:59:10 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_bre
{
	int dx;
	int dy;
	int i;
	int e;
	int incx;
	int incy;
	int inc1;
	int inc2;
	int x;
	int y;
}				t_bre;

typedef struct	s_pixel
{
	float			x;
	float			y;
	float			z;
	int				init;
	struct s_pixel	*down;
	struct s_pixel	*right;
	struct s_pixel	*next;
	struct s_pixel	*previous;
}				t_pixel;

typedef struct	s_fdf
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*str;
	float			step_x;
	float			step_y;
	struct s_pixel	*pixel;
	int				color;
	int				movement;
	int				links;
	int				info;
}				t_fdf;

typedef struct	s_line
{
	char			*str;
	char			**value;
	char			**tab;
	struct s_line	*next;
}				t_line;

void			ft_fill_pixel(t_fdf *fdf, float x, float y, int color);
int				ft_input(int key, t_fdf *fdf);
t_line			*ft_get(char *name);
void			ft_setvalue(t_fdf *fdf, t_line *line);
t_pixel			*ft_rewind(t_pixel *el);
void			ft_putpoint(t_fdf *fdf);
void			ft_back_in_black(t_fdf *fdf);
void			ft_putlinks(t_fdf *fdf);
void			ft_color(t_fdf *fdf, int color);
void			ft_rotation_haut(t_fdf *fdf);
void			ft_rotation_bas(t_fdf *fdf);
void			ft_up(t_fdf *fdf);
void			ft_down(t_fdf *fdf);
void			ft_left(t_fdf *fdf);
void			ft_right(t_fdf *fdf);
int				ft_less_ligne(t_fdf *fdf);
void			ft_set_movement(t_fdf *fdf, int mov);
void			ft_rotation_left(t_fdf *fdf);
void			ft_rotation_right(t_fdf *fdf);
t_pixel			*ft_setpixel(float x, float y, float z, t_pixel *el);
t_pixel			*ft_getpixeldown(t_pixel *pixel);
void			ft_setpixel_links(t_pixel *pixel);
void			ft_setstep(t_fdf *fdf, t_line *line);
t_pixel			*ft_getpixel(t_line *line, t_fdf *fdf);
void			ft_links(t_pixel *src, t_pixel *dst, t_fdf *fdf);
void			ft_text(t_fdf *fdf);
void			ft_rot_z(t_fdf *fdf);
void			ft_rot_nz(t_fdf *fdf);

#endif
