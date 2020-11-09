/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:16 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:17 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_find_size(t_type *type, const char *format)
{
	int i;

	i = 0;
	while (format[0] != type->sizes[i] && type->sizes[i])
		++i;
	if (type->sizes[i] != '\0')
		ft_parse_size(format, type);
	return (ft_skip_size(type->size));
}

int		ft_modifier_processing(t_type *type, const char *format, int count_skip)
{
	int		val;

	val = 0;
	if (format[0] == '*')
		return (ft_pars_star_wid(type));
	else if ((val = ft_atoi(format)))
		return (ft_intlen(type->width = val));
	else if (format[0] == '.')
	{
		count_skip += ft_zero_skip(&format[1]);
		if (format[1] == '*')
			return (ft_pars_star_pres(type));
		if ((val = ft_atoi(&(format[1]))) > 0)
			count_skip += ft_intlen(type->precision = val);
		type->dot++;
	}
	if (format[0] == 'l' || format[0] == 'L'
			|| format[0] == 'h' || format[0] == 'z')
		count_skip += ft_find_size(type, format);
	return (count_skip);
}

int		ft_parse_format(const char *format, t_type *type)
{
	int		count_skip;

	count_skip = 1;
	if (format[0] == '#' && type->f_null == 0)
		type->f_hash = 1;
	else if (format[0] == '0' && type->f_null == 0)
		type->f_null = 1;
	else if (format[0] == '-' && type->f_minus == 0)
		type->f_minus = 1;
	else if (format[0] == '+' && type->f_plus == 0)
		type->f_plus = 1;
	else if (format[0] == ' ' && type->f_space == 0)
		type->f_space = 1;
	else if (format[0] != '0')
		return (ft_modifier_processing(type, format, count_skip));
	return (count_skip);
}

int		ft_parse_type(const char *format, t_type *type)
{
	int		i;

	i = 0;
	while (format[i] && !ft_is_type(format[i]))
	{
		i += ft_parse_format(&format[i], type);
	}
	if (format[i])
	{
		type->type = format[i];
		return (i);
	}
	return (--i);
}
