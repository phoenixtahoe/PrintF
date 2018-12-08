# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:12:14 by pdavid            #+#    #+#              #
#    Updated: 2018/12/07 19:53:33 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

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
	@echo "[ft_printf - 모래반지 빵야빵야!]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[ft_printf - clean]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[ft_printf - fclean]"

re: fclean all