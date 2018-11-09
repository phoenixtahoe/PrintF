/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:23:16 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/08 21:54:52 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	char_width(t_env *e)
{
	while (e->flag->width-- > 1)
	{
		if (e->flag->zero == 1)
		{
			e->ret += write(e->fd, "0", 1);
		}
		else if (e->flag->zero == 0)
		{
			e->ret += write(e->fd, " ", 1);
		}
	}
}

void	char_null(t_env *e)
{
	while (e->flag->width-- > 1)
	{
		if (e->flag->zero == 1)
		{
			e->ret += write(e->fd, "0", 1);
		}
		else if (e->flag->zero == 0)
		{
			e->ret += write(e->fd, " ", 1);
		}
		e->ret += write(e->fd, "\0", 1);
		++e->i;
	}
}

void	char_print(t_env *e)
{
	if (e->flag->minus)
	{
		e->ret += write(e->fd, e->output, 1);
		char_width(e);
	}
	else
	{
		char_width(e);
		e->ret += write(e->fd, e->output, 1);
	}
	++e->i;
}
