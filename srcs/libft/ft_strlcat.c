/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:23:55 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:23:55 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	k;

	j = 0;
	i = 0;
	while (dst[i] && i < size)
		i++;
	k = i;
	while (src[j] && k < (size - 1) && size)
		dst[k++] = src[j++];
	if (k < size)
		dst[k] = '\0';
	return (ft_strlen(src) + i);
}
