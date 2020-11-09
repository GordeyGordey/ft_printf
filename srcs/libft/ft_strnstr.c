/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:33 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:34 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *dst, size_t len)
{
	size_t l;

	if ((l = ft_strlen(dst)))
	{
		if (!(ft_strlen(str) < l || len < l))
		{
			while (*str && len-- >= l)
				if (!ft_memcmp(str++, dst, l))
					return ((char *)(str - 1));
		}
		return (NULL);
	}
	return ((char *)str);
}
