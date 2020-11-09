/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:20:20 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:20:21 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen_base(t_ll_int value, int base)
{
	int i;

	i = 1;
	if (value < 0 && base == 10)
		i++;
	while (value /= base)
		i++;
	return (i);
}

static char		print_nbr(int value)
{
	char	*str;
	char	c;

	value = value < 0 ? value * -1 : value;
	str = ft_strdup("0123456789ABCDEF");
	c = str[value];
	ft_strdel(&str);
	return (c);
}

char			*ft_itoa_base(t_ll_int value, int base, int num)
{
	char	*str;
	int		count;

	count = ft_intlen_base(value, base) + (num > 0 ? num : 0);
	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	while ((value >= base && value > 0)
	|| (value <= (base * -1) && value < 0))
	{
		str[--count] = print_nbr(value % base);
		value /= base;
	}
	str[--count] = print_nbr(value % base);
	while (num-- > 0)
		str[--count] = print_nbr(0);
	if (count)
		str[--count] = '-';
	return (str);
}
