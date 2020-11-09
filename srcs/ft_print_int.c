/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:26 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:28 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_spase(t_type *type, const t_ll_int elem)
{
	int		i;
	int		count;

	count = 0;
	if (type->precision > type->length - (elem < 0 ? 1 : 0))
		i = type->width - type->precision;
	else
		i = type->width - type->length;
	if (i >= 0)
	{
		if (((type->f_plus || type->f_space) && (elem > 0
		|| (!elem && (type->precision || !type->dot))))
		|| (elem < 0 && (type->precision > (type->length - 1))))
			i--;
		if ((!type->dot && type->f_null) && !type->f_minus)
			type->cnt_zero += i;
		else
			count += ft_print_n_char(i, ' ', type->fd);
	}
	return (count);
}

int		print_precision_and_elem(t_type *type, const t_ll_int elem)
{
	int		i;
	int		count;
	char	*str;

	count = 0;
	i = type->precision - type->length + ((elem < 0) ? 1 : 0);
	if (elem > 0 || ((type->precision || !type->dot) && !elem))
	{
		if (type->f_plus)
			count += ft_print_n_char(1, '+', type->fd);
		else if (type->f_space)
			count += ft_print_n_char(1, ' ', type->fd);
	}
	if (i > 0)
		type->cnt_zero += i;
	if (!type->dot || type->precision || elem)
	{
		ft_putstr_fd((str = ft_itoa_base(elem, 10, type->cnt_zero)), type->fd);
		ft_strdel(&str);
	}
	if (!elem && !type->precision && type->dot)
		if (type->f_plus || type->f_space || type->f_minus || type->f_null
		|| (!type->f_plus && !type->f_space && !type->f_minus && type->width))
			count += ft_print_n_char(1, type->f_plus ? '+' : ' ', type->fd);
	return (count + type->cnt_zero);
}

int		ft_print_int(t_type type, t_ll_int elem)
{
	int		count;

	count = 0;
	type.length = ft_intlen(elem);
	if (elem < 0)
		type.length++;
	if (type.f_minus)
	{
		count += print_precision_and_elem(&type, elem);
		count += print_spase(&type, elem);
	}
	else
	{
		count += print_spase(&type, elem);
		count += print_precision_and_elem(&type, elem);
	}
	if (type.precision || !type.dot || (!type.precision && elem))
		return (count + type.length);
	else
		return (count);
}

int		ft_int_specifier(t_type type, t_ll_int elem)
{
	if (type.size == H)
		return (ft_print_int(type, (short)elem));
	else if (type.size == HH)
		return (ft_print_int(type, (char)elem));
	else if (type.size == L || type.size == LL)
		return (ft_print_int(type, (long int)elem));
	else
		return (ft_print_int(type, (int)elem));
}
