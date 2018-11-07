/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:23:16 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/07 04:25:48 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	char_width(t_env *e)
{
	while (e->flag.width-- > 1)
	{
		if (e->flag.zero == 1)
		{
			e->ret += write(e->fd, "0", 1);
		}
		else if (e->flag.zero == 0)
		{
			e->ret += write(e->fd, " ", 1);
		}
	}
}

void	char_null(t_env *e)
{
	while (e->flag.width-- > 1)
	{
		if (e->flag.zero == 1)
		{
			e->ret += write(e->fd, "0", 1);
		}
		else if (e->flag.zero == 0)
		{
			e->ret += write(e->fd, " ", 1);
		}
		e->ret += write(e->fd, "\0", 1);
		++e->i;
	}
}

void	char_print(t_env *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c ,1);
		char_width(e);
	}
	else
	{
		char_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}

void	char_arg(t_env *e, int *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], int);
		return ;
	}
	*tmp = va_arg(e->ap[0], int);
}
