# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/11/06 20:18:16 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cflags = -fsanitize=address -Wall -Wextra -Werror

make_libft = @make -C ./includes/libft/

header = ./includes/ft_printf.h

includes = ./includes/libft/libft.a

SRC = ./src/printf.c ./src/print_str.c ./src/print_char.c ./src/main.c ./src/init.c ./src/get.c

OBJ = *.o

cc = @gcc

name = Printf

all: $(name)

$(name):
	@printf "\e[1;31mMaking libft\e[0m\n"
	@$(make_libft)
	@printf "\e[1;31mCompiling $(name)\e[0m\n"
	@$(cc) $(cflags) -g $(SRC) $(includes) -o $(name)
	@printf "\e[1;32m$(name) Excutable Created!\e[0m\n"

clean:
	@printf "\e[1;32mCleaning!\e[0m\n"
	@make -C includes/libft/ fclean
	@/bin/rm -f $(name)

fclean:
	@make -C includes/libft/ fclean

re : clean all