/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_arrays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:29:02 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:29:03 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_count_zero_in_int_part(t_long_num *in, t_type type, int first_size)
{
	int		count;

	count = 0;
	type.precision += (type.precision || type.f_hash) ? 1 : 0;
	if (type.width)
	{
		count = type.width - 8 * in->real_size - first_size - type.precision;
		if ((type.f_space || type.f_plus) && !in->sign)
			count = (count - 1) > 0 ? --count : 0;
		if (count > 0)
		{
			if (type.f_null && !type.f_minus)
				in->c_zero = count;
			else if ((type.f_null && type.f_minus) || !type.f_null)
				ft_print_n_char(count, ' ', type.fd);
		}
	}
	return (count);
}

int		ft_put_prefix_of_float(t_long_num *in, int index, t_type type)
{
	int count;

	count = 0;
	if (in->sign == 1)
	{
		in->num[in->real_size] *= -1;
		in->num[index] ? 0 : ft_print_n_char(1, '-', type.fd);
	}
	else if (type.f_plus || type.f_space)
		count += type.f_plus ?
		ft_print_n_char(1, '+', type.fd) : ft_print_n_char(1, ' ', type.fd);
	return (count);
}

int		print_fract_array(t_long_num p, t_type type)
{
	char	*str;
	int		size_num;
	int		ind_elem;
	int		n_char;
	int		precition;

	ind_elem = p.real_size;
	precition = type.precision;
	type.print = precition;
	while (ind_elem >= 0 && precition > 0)
	{
		n_char = precition;
		size_num = ft_intlen(p.num[ind_elem]);
		if (ind_elem != p.real_size && size_num < 8)
			p.c_zero = 8 - size_num;
		if (!(str = ft_itoa(p.num[ind_elem--], p.c_zero)))
			error(1, type.vl);
		n_char = ft_put_n_line_char(str, n_char, type.fd);
		precition -= n_char;
		ft_memdel((void **)&str);
		p.c_zero = 0;
	}
	if (precition > 0)
		ft_print_n_char(precition, '0', type.fd);
	return (type.print);
}

int		ft_print_long_num(t_long_num in, t_long_num fr, t_type type)
{
	int		size_num;
	int		ind_elem;
	int		count;

	count = 0;
	ind_elem = in.real_size;
	count += ft_print_long_elem(in, type.fd, ind_elem--, in.size_fst);
	while (ind_elem >= 0)
	{
		if ((size_num = ft_intlen(in.num[ind_elem])) < 8)
			in.c_zero = 8 - size_num;
		count += ft_print_long_elem(in, type.fd, ind_elem--, size_num);
		in.c_zero = 0;
	}
	if (type.precision || type.f_hash)
		count += ft_print_n_char(1, '.', type.fd);
	if (type.precision)
		count += print_fract_array(fr, type);
	return (count);
}

int		print_int_and_fr_parts(t_long_num in, t_long_num fr,
								t_type type)
{
	int print;

	print = 0;
	in.size_fst += in.sign ? 1 : 0;
	if (type.f_minus)
	{
		print += ft_put_prefix_of_float(&in, in.real_size, type);
		print += ft_print_long_num(in, fr, type);
		print += ft_count_zero_in_int_part(&in, type, in.size_fst);
	}
	else
	{
		print += ft_count_zero_in_int_part(&in, type, in.size_fst);
		print += ft_put_prefix_of_float(&in, in.real_size, type);
		print += ft_print_long_num(in, fr, type);
	}
	return (print);
}
