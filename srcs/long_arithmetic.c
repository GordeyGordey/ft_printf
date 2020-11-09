/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:54 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:54 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_array(t_long_num *p)
{
	int		i;

	i = -1;
	while (++i < 650)
		p->num[i] = 0;
	p->real_size = 0;
	p->c_zero = 0;
}

void	mul_long_num(t_long_num *p, int i, int value, int remain)
{
	int next_rem;

	while (i <= p->real_size)
	{
		if ((p->num[i] *= value) >= MAX)
		{
			p->real_size = (p->real_size < i + 1) ? i + 1 : p->real_size;
			next_rem = p->num[i] / MAX;
			p->num[i] %= MAX;
		}
		else if (p->real_size > i)
			next_rem = 0;
		p->num[i++] += remain;
		remain = next_rem;
	}
}

int		sum_long_num(t_long_num *p, int i, t_long_num value, int remain)
{
	i--;
	while (++i <= value.real_size || remain)
	{
		if ((p->num[i] += value.num[i] + remain) >= MAX)
		{
			p->real_size = (p->real_size < i + 1) ? i + 1 : p->real_size;
			remain = p->num[i] / MAX;
			p->num[i] %= MAX;
		}
		else
		{
			if (value.real_size > i)
				p->real_size = (p->real_size < i + 1) ? i + 1 : p->real_size;
			remain = 0;
		}
	}
	return (1);
}

int		sum_long_short(t_long_num *p, int i, int value)
{
	int		num;

	num = 0;
	if ((p->num[i] += value) >= MAX)
	{
		num = p->num[i] / MAX;
		p->num[i] %= MAX;
		if (i < p->real_size || p->c_zero)
		{
			if (p->real_size < i + 1)
			{
				p->real_size++;
				p->c_zero -= p->c_zero ? 1 : 0;
			}
			return (sum_long_short(p, i + 1, num));
		}
		else
			return (1);
	}
	return (0);
}
