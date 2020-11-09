/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:28:46 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:28:46 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_skip_size(int size)
{
	int		i;

	i = 0;
	if (size == HH || size == LL)
		++i;
	return (i);
}

int		ft_zero_skip(const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i++] == '0')
		count++;
	return (count);
}
