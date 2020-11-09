/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:29:10 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:29:11 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_n_char(int num, char c, int fd)
{
	int		count;

	count = num;
	while (num-- > 0)
		write(fd, &c, 1);
	return (count);
}

int		ft_print_long_elem(t_long_num p, int fd,
								int index, int size_num)
{
	char	*str;

	ft_putstr_fd((str = ft_itoa(p.num[index], p.c_zero)), fd);
	ft_memdel((void **)&str);
	return (p.c_zero + size_num);
}

int		ft_put_space_for_str(char *elem, t_type type)
{
	int		stlen;
	char	c;
	int		count;

	count = 0;
	if (type.width > 0 && type.width > (stlen = ft_strlen(elem)))
	{
		c = (type.f_null && !type.f_minus) ? '0' : ' ';
		count += ft_print_n_char(type.width - stlen, c, type.fd);
	}
	count += ft_strlen(elem);
	return (count);
}

void	ft_print_using_num(const t_ull_int *elem, int base,
									t_type *type, int reg)
{
	char	*str;

	str = ft_itoa_unsig_base(*elem, base, type->cnt_zero, reg);
	ft_putstr_fd(str, type->fd);
	ft_strdel(&str);
}
