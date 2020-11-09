/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:23:24 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:23:25 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*src2;
	int		n;

	if (!(src2 = ft_strnew(ft_strlen(src))))
		return (NULL);
	n = 0;
	while (src[n])
	{
		src2[n] = src[n];
		n++;
	}
	return (src2);
}
