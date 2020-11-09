/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_a_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:40 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:41 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pos_to_round	find_a_pos_to_round(t_long_num fr_p, int precision)
{
	t_pos_to_round	p_i;
	int				size;

	p_i.ind = fr_p.real_size;
	size = fr_p.size_fst + fr_p.c_zero;
	if (precision > size)
	{
		size = precision - size - 1;
		p_i.regist = 7 - size % 8;
		p_i.ind = fr_p.real_size - size / 8 - 1;
	}
	else
		p_i.regist = size - precision;
	p_i.pow_regst = ft_power(10, p_i.regist);
	return (p_i);
}

void			lift_the_int_part(t_long_num *int_p, t_long_num *fr_p, int reg)
{
	fr_p->num[fr_p->real_size] %= ft_power(10, fr_p->size_fst);
	if (!(fr_p->num[fr_p->real_size] / reg))
		fr_p->c_zero = fr_p->size_fst - 1;
	sum_long_short(int_p, 0, 1);
}

int				ft_fr_count_zero(t_long_num fr_p, t_float_param fl_p)
{
	int		count;

	count = fl_p.lst_mbit - fl_p.exp -
		8 * fr_p.real_size - fr_p.size_fst;
	return (count);
}

void			ft_round(t_long_num *int_p, t_long_num *fr_p,
								t_pos_to_round p_i)
{
	if (sum_long_short(fr_p, p_i.ind, p_i.pow_regst))
		sum_long_short(int_p, 0, 1);
	if (fr_p->size_fst < ft_intlen(fr_p->num[fr_p->real_size]))
	{
		if (fr_p->c_zero)
			fr_p->c_zero--;
		else
			lift_the_int_part(int_p, fr_p, p_i.pow_regst);
	}
}

void			ft_round_a_num(t_long_num *int_p, t_long_num *fr_p,
								t_float_param fl_p, int precision)
{
	t_pos_to_round	p_i;
	int				comparison;

	fr_p->c_zero = ft_fr_count_zero(*fr_p, fl_p);
	p_i = find_a_pos_to_round(*fr_p, precision);
	if (p_i.ind >= 0)
	{
		comparison = (int_p->num[int_p->real_size] % 2 == 0) ? 6 : 5;
		if (p_i.pow_regst == 1 && p_i.ind
					&& (fr_p->num[p_i.ind - 1] / (MAX / 10)) % 10 >= 5)
			ft_round(int_p, fr_p, p_i);
		else if (p_i.pow_regst > 1)
		{
			if (p_i.ind == fr_p->real_size && fr_p->c_zero == 0
			&& fr_p->size_fst == (size_t)p_i.regist
			&& int_p->num[int_p->real_size] % 2 == 0)
				comparison = 6;
			else
				comparison = 5;
			if ((fr_p->num[p_i.ind] / (p_i.pow_regst / 10)) % 10 >= comparison)
				ft_round(int_p, fr_p, p_i);
		}
	}
}
