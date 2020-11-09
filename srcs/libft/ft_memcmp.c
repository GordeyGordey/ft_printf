/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:21:27 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:21:27 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s;
	unsigned char *t;

	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (n--)
		if (*s++ != *t++)
			return (*(s - 1) - *(t - 1));
	return (0);
}
