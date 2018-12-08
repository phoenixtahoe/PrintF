# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/12/07 18:44:32 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = printf.c print_str.c print_char.c main.c print_int.c get.c spec.c print_wchar.c print_wstr.c ft_ltoa.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@
	@echo "[ft_printf - made]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[ft_printf - clean]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[ft_printf - fclean]"

re: fclean all