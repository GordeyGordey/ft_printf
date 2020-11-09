/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:21:13 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:21:13 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (size == 0 || (s = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_bzero((void *)s, size);
	return ((void *)s);
}
