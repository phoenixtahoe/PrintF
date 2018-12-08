# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/12/07 18:21:56 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cflags = -fsanitize=address -Wall -Wextra -Werror

lbift_src = ./includes/libft/*.c
lbift_obj = ./includes/libft/*.o

header = ./includes/ft_printf.h

includes = ./includes/libft/libft.a

SRC = ./src/printf.c ./src/print_str.c ./src/print_char.c ./src/main.c ./src/print_int.c ./src/get.c ./src/spec.c ./src/print_wchar.c ./src/print_wstr.c ./src/ft_ltoa.c

OBJ = *.o

cc = @gcc

name = libftprintf.a

all: $(name)

$(name):
	@printf "\e[1;31mMaking libft\e[0m\n"
	@printf "\e[1;31mCompiling $(name)\e[0m\n"
	gcc $(FLAGS) -c $(SRC) $(lbift_src)
	@printf "\e[1;32m$(name) Created!\e[0m\n"
	ar rcs libftprintf.a *.o
	ranlib libftprintf.a


clean:
	@printf "\e[1;32mCleaning!\e[0m\n"
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(lbift_obj)

fclean:
	@/bin/rm -rf $(name)

re : fclean clean all