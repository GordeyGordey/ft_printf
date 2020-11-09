NAME = libftprintf.a

LIBFTA = libft.a

PRINTF_H =	-I includes/

LIBFT_H = 	-I srcs/libft/

COMP =	gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

SRC_DIR =	srcs/

OBJ_DIR =	obj/

LIB_DIR = srcs/libft/

SRCS = ft_round_a_num.c help_func_for_parse.c \
	work_with_the_type_struct.c ft_print_float.c \
	ft_printf.c long_arithmetic.c print_format.c \
	ft_skip.c ft_parse.c ft_print_int.c \
	ft_print_unsig_int.c print_function.c \
	parse_bonus_part.c print_float_arrays.c

CFIND =	$(SRCS:%=$(SRC_DIR)%)

OFILE =	$(SRCS:%.c=%.o)

OBJ =	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) 
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFTA) .
	@mv $(LIBFTA) $(NAME)
	@ar rc $(NAME) $(addprefix $(OBJ_DIR),$(OFILE))

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
