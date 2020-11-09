/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:58 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:59 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_color(char *color, int fd, int count)
{
	if (fd == 1)
		ft_putstr_fd(color, fd);
	return (count);
}

int		read_background_color(const char **format, t_type *type)
{
	if (ft_strnstr(*format, "{bg:red}", 8))
		return (print_color(BG_RED, type->fd, 7));
	else if (ft_strnstr(*format, "{bg:green}", 10))
		return (print_color(BG_GREEN, type->fd, 9));
	else if (ft_strnstr(*format, "{bg:blue}", 9))
		return (print_color(BG_BLUE, type->fd, 8));
	else if (ft_strnstr(*format, "{bg:cyan}", 9))
		return (print_color(BG_CYAN, type->fd, 8));
	else if (ft_strnstr(*format, "{bg:yellow}", 11))
		return (print_color(BG_YELLOW, type->fd, 10));
	else if (ft_strnstr(*format, "{bg:white}", 10))
		return (print_color(BG_WHITE, type->fd, 9));
	type->fall = 1;
	return (-1);
}

int		read_color(const char *format, t_type *type)
{
	if (ft_strnstr(format, "{red}", 5))
		return (print_color(ANSI_RED, type->fd, 4));
	else if (ft_strnstr(format, "{eoc}", 5))
		return (print_color(ANSI_RESET, type->fd, 4));
	else if (ft_strnstr(format, "{green}", 7))
		return (print_color(ANSI_GREEN, type->fd, 6));
	else if (ft_strnstr(format, "{blue}", 6))
		return (print_color(ANSI_BLUE, type->fd, 5));
	else if (ft_strnstr(format, "{cyan}", 6))
		return (print_color(ANSI_CYAN, type->fd, 5));
	else if (ft_strnstr(format, "{yellow}", 8))
		return (print_color(ANSI_YELLOW, type->fd, 7));
	else
		return (read_background_color(&format, type));
}

int		ft_parse_bonus_part(const char *format, t_type *type)
{
	if (ft_strnstr(format, "{fd}", 4))
	{
		type->fd = va_arg(type->vl, int);
		return (3);
	}
	else if (ft_strnstr(format, "{/fd}", 5))
	{
		type->fd = 1;
		return (4);
	}
	else
		return (read_color(format, type));
}
