/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func_for_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:50 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:51 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_size(const char *format, t_type *type)
{
	if (format[0] == 'h' && format[1] != 'h')
		type->size = H;
	else if (format[0] == 'h' && format[1] == 'h')
		type->size = HH;
	else if (format[0] == 'l' && format[1] != 'l')
		type->size = L;
	else if (format[0] == 'l' && format[1] == 'l')
		type->size = LL;
	else if (format[0] == 'L')
		type->size = L_BIG;
	else if (format[0] == 'z')
		type->size = Z;
}

int		ft_pars_star_wid(t_type *type)
{
	int val;

	val = va_arg(type->vl, int);
	if ((type->width = val) < 0)
	{
		type->f_minus = 1;
		type->width *= -1;
	}
	return (1);
}

int		ft_pars_star_pres(t_type *type)
{
	int val;

	val = va_arg(type->vl, int);
	if (val >= 0)
	{
		type->precision = val;
		type->dot++;
	}
	return (2);
}

int		ft_is_type(char format)
{
	if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'o' || format == 'x' || format == 'X'
		|| format == 'f' || format == 'c' || format == 'p'
		|| format == 's' || format == '%')
		return (1);
	else
		return (0);
}

int		ft_parse_base(int *base, char type)
{
	if (type == 'X')
	{
		*base = 16;
		return (1);
	}
	else if (type == 'x')
		*base = 16;
	else if (type == 'o')
		*base = 8;
	else
		*base = 10;
	return (0);
}
