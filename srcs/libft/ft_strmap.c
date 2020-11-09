/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:24:03 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:24:03 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
		str[i++] = f(*s++);
	str[i] = '\0';
	return (str);
}
