/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:19:02 by wendell           #+#    #+#             */
/*   Updated: 2020/08/13 23:33:30 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include "../srcs/libft/libft.h"

typedef long long				t_ll_int;
typedef unsigned long long		t_ull_int;
typedef unsigned long			t_ul_int;
typedef long double				t_l_dbl;

# define H		1
# define HH		2
# define L		3
# define LL		4
# define L_BIG	5
# define Z		6

# define MAX	100000000

# define ANSI_RED				"\x1b[31m"
# define ANSI_GREEN				"\x1b[32m"
# define ANSI_YELLOW			"\x1b[33m"
# define ANSI_BLUE				"\x1b[34m"
# define ANSI_CYAN				"\x1b[36m"
# define ANSI_RESET				"\x1b[0m"

# define BG_RED					"\x1b[41m"
# define BG_GREEN				"\x1b[42m"
# define BG_YELLOW				"\x1b[43m"
# define BG_BLUE				"\x1b[44m"
# define BG_CYAN				"\x1b[46m"
# define BG_WHITE				"\x1b[47m"

typedef struct	s_pos_to_round
{
	int			regist;
	int			ind;
	int			pow_regst;
}				t_pos_to_round;

typedef struct	s_float_param
{
	int			exp;
	__uint128_t	bits;
	int			bit;
	int			lst_mbit;
	int			min_exp;
}				t_float_param;

typedef struct	s_long_num
{
	int			num[650];
	int			real_size;
	int			c_zero;
	size_t		size_fst;
	int			sign;
}				t_long_num;

typedef struct	s_type
{
	int			f_null;
	int			f_hash;
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_pointer;
	int			width;
	int			star_w;
	int			precision;
	int			star_p;
	int			size;
	char		type;
	va_list		vl;
	unsigned	print;
	char		*types;
	char		*sizes;
	int			length;
	int			cnt_zero;
	int			dot;
	int			fd;
	int			fall;
}				t_type;

void			ft_create_typestruct(t_type *type);
void			ft_type_cleaning(t_type *type);
void			ft_del_struct(t_type *type);

int				ft_parse_type(const char *format, t_type *type);
int				ft_is_type(const char format);
void			ft_parse_size(const char *format, t_type *type);
int				ft_pars_star_wid(t_type *type);
int				ft_pars_star_pres(t_type *type);
int				ft_skip_size(int size);
int				ft_zero_skip(const char *format);

int				ft_print_char(char elem, t_type type);

int				ft_print_string(char *elem, t_type type);
int				ft_put_space_for_str(char *elem, t_type type);

int				ft_print_pointer(void *elem, t_type type);

int				ft_int_specifier(t_type type, t_ll_int num);
int				ft_print_int(t_type type, t_ll_int elem);

int				ft_unsig_specifier(t_type type, t_ull_int elem);
int				ft_print_unsig(t_type type, t_ull_int elem);
void			ft_print_using_num(const t_ull_int *elem, int base,
												t_type *type, int reg);
int				ft_parse_base(int *base, char type);

int				ft_float_specifier(t_type type);
int				ft_proc_bits_dub(t_float_param	*float_p, double elem);
int				ft_proc_bits_ldub(t_float_param	*float_p,
												t_l_dbl elem);
int				ft_print_float(t_float_param float_p,
									t_type type, int int_sign);
void			init_array(t_long_num *p);
void			ft_creat_integ_part_num(t_long_num *int_p,
											t_float_param *float_p);
void			ft_creat_fract_part_num(t_long_num *fr_p,
											t_float_param *float_p);
void			mul_long_num(t_long_num *p, int i, int value, int remain);
int				sum_long_num(t_long_num *p, int i,
										t_long_num value, int remain);
int				sum_long_short(t_long_num *p, int i, int value);
void			ft_round_a_num(t_long_num *int_p, t_long_num *fr_p,
										t_float_param fl_p, int precision);
int				ft_print_long_elem(t_long_num p, int fd,
										int index, int size_num);
int				print_int_and_fr_parts(t_long_num in, t_long_num fr,
													t_type type);

int				ft_parse_bonus_part(const char *format, t_type *type);
int				ft_print_n_char(int num, char c, int fd);
int				power(int a, int i);
void			error(int x, va_list vl);

void			test_unsig_int_arg1(t_ull_int num);
void			test_unsig_int_arg2(t_ull_int num);
void			test_int_arg1(t_ll_int num);
void			test_int_arg2(t_ll_int num);
int				ft_printf(const char *format, ...);

#endif
