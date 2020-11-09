# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wendell <wendell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 23:25:41 by wendell           #+#    #+#              #
#    Updated: 2020/08/13 23:25:41 by wendell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_power.c ft_put_n_line_char.c ft_atoi.c ft_base_intlen.c ft_itoa_unsig_base.c ft_atoi_base.c ft_itoa_base.c ft_strindch.c ft_word.c ft_letter.c ft_freetg.c ft_dellst.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstnew.c ft_strsplit.c ft_intlen.c ft_itoa.c ft_strncmp.c ft_memset.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_strdup.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) -c $(FLAGS) $< 

$(NAME): $(OBJ)
	@ar rc $@ $^

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
