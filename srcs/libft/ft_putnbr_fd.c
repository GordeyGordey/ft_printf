/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:22:36 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:22:37 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	int				b;
	int				count;

	b = 1000000000;
	count = 0;
	if ((i = (unsigned int)n) == 0)
		b = 1;
	if (n < 0)
	{
		i = (unsigned int)(n * -1);
		ft_putchar_fd('-', fd);
		count++;
	}
	while (i && (i / b) == 0)
		b = b / 10;
	while (b)
	{
		ft_putchar_fd(i / b + '0', fd);
		count++;
		i = i % b;
		b = b / 10;
	}
	return (count);
}
