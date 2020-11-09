/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:22:31 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:22:32 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_minimum(int nbr)
{
	int output;

	if (nbr == -2147483648)
	{
		ft_putchar('2');
		output = nbr % 1000000000;
	}
	else
		return (nbr);
	return (output);
}

void		ft_putnbr(int nb)
{
	int a;
	int c;

	c = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = get_minimum(nb);
		nb = nb * (-1);
	}
	a = nb;
	while ((a / 10) > 0)
	{
		a = a / 10;
		c = c * 10;
	}
	while (c > 0)
	{
		ft_putchar((nb / c) + '0');
		nb = nb % c;
		c = c / 10;
	}
}
