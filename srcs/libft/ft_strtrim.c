/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:54 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:55 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	l;

	i = 0;
	if (s)
	{
		while (*s && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		l = ft_strlen(s) - 1;
		while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && l > i)
			l--;
		if ((str = ft_strsub(s, i, l - i + 1)))
			return (str);
	}
	return (NULL);
}
