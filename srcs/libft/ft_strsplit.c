/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:42 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:43 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tg;
	size_t	i;
	size_t	w;
	size_t	l;

	i = 0;
	if (!s || !(tg = (char **)malloc(sizeof(char*) * (ft_word(s, c) + 1))))
		return (NULL);
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			l = ft_letter(s, c, i);
			if (!(tg[w++] = ft_strsub(s, i, l)))
			{
				ft_freetg(tg, w - 1);
				return (NULL);
			}
			i = i + l - 1;
		}
		i++;
	}
	tg[w] = NULL;
	return (tg);
}
