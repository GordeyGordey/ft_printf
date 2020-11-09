/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:47 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:47 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *dst)
{
	if (*dst)
	{
		while (*str)
			if (!ft_memcmp(str++, dst, ft_strlen(dst)))
				return ((char *)(str - 1));
		return (NULL);
	}
	return ((char *)str);
}
