/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:19:30 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:19:31 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellst(t_list **list)
{
	t_list	*tmp;

	if (list)
		while ((*list)->next)
		{
			tmp = (*list)->next;
			free((*list)->content);
			(void)((*list)->content_size);
			free(*list);
			*list = tmp;
		}
}
