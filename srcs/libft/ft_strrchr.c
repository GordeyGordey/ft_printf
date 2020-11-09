/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:38 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:39 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			n;
	unsigned char	t;
	char			*str;

	t = (unsigned char)c;
	n = ft_strlen(s) + 1;
	str = (char *)s;
	while (n--)
		if (str[n] == t)
			return (&str[n]);
	return (NULL);
}
