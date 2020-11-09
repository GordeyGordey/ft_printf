/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:22:56 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:22:58 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char b;

	b = (unsigned char)c;
	while (*s && *s != b)
		s++;
	if (*s == b)
		return ((char *)s);
	return (NULL);
}
