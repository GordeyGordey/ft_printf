/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:29:06 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:29:06 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_float(t_float_param float_p, t_type type, int int_sign)
{
	t_long_num int_part;
	t_long_num fr_part;

	int_part.sign = int_sign;
	fr_part.sign = 0;
	ft_creat_integ_part_num(&int_part, &float_p);
	ft_creat_fract_part_num(&fr_part, &float_p);
	type.precision = (type.precision < 0 || !type.dot) ? 6 : type.precision;
	if (fr_part.real_size != 0 && fr_part.num[fr_part.real_size] != 0)
		ft_round_a_num(&int_part, &fr_part, float_p, type.precision);
	return (print_int_and_fr_parts(int_part, fr_part, type));
}

int		ft_print_char(char elem, t_type type)
{
	char c;

	if (type.width)
	{
		if (type.f_minus)
		{
			write(type.fd, &elem, 1);
			ft_print_n_char(type.width - 1, ' ', type.fd);
		}
		else
		{
			c = (type.f_null) ? '0' : ' ';
			ft_print_n_char(type.width - 1, c, type.fd);
			write(type.fd, &elem, 1);
		}
	}
	else
	{
		ft_putchar_fd(elem, type.fd);
		return (1);
	}
	return (type.width);
}

int		ft_print_string(char *elem, t_type type)
{
	int		count;
	char	*str;
	char	*tmp;

	count = 0;
	if (!(tmp = (elem == NULL) ? ft_strdup("(null)\0") : elem))
		error(1, type.vl);
	str = (type.precision >= 0 && type.dot) ?
	ft_strsub(tmp, 0, type.precision) : tmp;
	if (type.f_minus)
	{
		ft_putstr_fd(str, type.fd);
		count += ft_put_space_for_str(str, type);
	}
	else
	{
		count += ft_put_space_for_str(str, type);
		ft_putstr_fd(str, type.fd);
	}
	if ((type.precision >= 0 && type.dot) || elem == NULL)
		ft_strdel(&str);
	return (count);
}

int		ft_print_pointer(void *elem, t_type type)
{
	t_ul_int	a;

	a = (t_ul_int)&(*elem);
	type.type = 'x';
	type.f_hash = 1;
	type.f_pointer = 1;
	return (ft_print_unsig(type, a));
}
