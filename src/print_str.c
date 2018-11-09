/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:54:24 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/08 21:43:26 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	str_width(t_env *e)
{
	e->len = ft_strlen(e->output);
	while (e->flag->width-- > e->len)
	{
		if (e->flag->zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
}

void	str_null(t_env *e)
{
	while (e->flag->width-- > e->len)
	{
		if (e->flag->zero == 1)
			e->ret += write(e->fd, "0", 1);
		else
			e->ret += write(e->fd, " ", 1);
	}
	e->ret += write(e->fd, "(null)", e->len);
	++e->i;
}

void	str_print(t_env *e)
{
	char	*tmp;
	
	if (e->flag->prec >= 0 && e->flag->prec < (int)ft_strlen(e->output))
	{
		tmp = ft_strsub(e->output, 0, (e->flag->prec));
		free(e->output);
		tmp = e->output;
	}
	if (e->flag->minus)
	{
		e->ret += write(e->fd, e->output, ft_strlen(e->output));
		str_width(e);
	}
	else
	{
		str_width(e);
		e->ret += write(e->fd, e->output, ft_strlen(e->output));
	}
	++e->i;
	free(e->output);
}