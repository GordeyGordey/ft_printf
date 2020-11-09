/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:51 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:51 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*st;
	unsigned int	i;

	i = 0;
	st = (char *)s;
	if (s && (str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (st[start] && len-- > 0)
			str[i++] = st[start++];
		return (str);
	}
	return (NULL);
}
