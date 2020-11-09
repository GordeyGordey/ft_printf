/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:19:17 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:19:18 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		in(char c, char max)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = "0123456789abcdef\0";
	s2 = "0123456789ABCDEF\0";
	if ((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9'))
		while (s1[i] && s1[i] != (max + 33))
			if (c == s1[i++])
				return (i - 1);
	if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
		while (s2[i] && s2[i] != (max + 1))
			if (c == s2[i++])
				return (i - 1);
	return (-1);
}

static char		max_nb(int base)
{
	char *ar;

	ar = "ABCDEF\0";
	if (base > 1 && base < 11)
		return ((base - 1) - '0');
	return (ar[base - 11]);
}

static int		ft_atoi(const char *nbr, char max, int base)
{
	int i;
	int r;
	int a;

	i = 0;
	r = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i])
		if ((a = in(nbr[i++], max)) != -1)
			r = r * base + a;
		else
			break ;
	return (r);
}

int				ft_atoi_base(const char *nbr, unsigned int base)
{
	char	max;
	int		res;

	max = max_nb(base);
	res = ft_atoi(nbr, max, base);
	if (nbr[0] == '-')
		res *= -1;
	return (res);
}
