/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:21:32 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:21:32 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	if (dst != src)
	{
		s1 = (unsigned char *)dst;
		s2 = (unsigned char *)src;
		while (n--)
			*s1++ = *s2++;
	}
	return (dst);
}
