/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:44:18 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/07 21:39:42 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_arg(t_env *e, long *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], long);
		return ;
	}
	*tmp = va_arg(e->ap[0], long);
}

void	int_sign(t_env *e)
{
	if (e->flag->plus || e->flag->space)
		e->ret += (e->flag->plus == 1 ?
		write(e->fd, "+", 1) : write(e->fd, " ", 1));
	else if (e->flag->neg)
		e->ret += write(e->fd, "-", 1);
}

void	int_check(t_env *e)
{
	char *tmp;

	if (e->output[0] == '-')
	{
		tmp = ft_strdup(e->output + 1);
		free(e->output);
		e->output = tmp;
		e->flag->space = 0;
		e->flag->plus = 0;
		e->flag->neg = 1;
	}
}

void	int_prec(t_env *e)
{
	char	*tmp;
	char	*res;
	int		i;
	
	int_check(e);
	e->len = (int)ft_strlen(e->output);
	if (e->flag->prec == 0 && e->output[0] == '0')
		e->output[0] = '\0';
	else if (e->flag->prec > e->len)
	{
		i = e->flag->prec - e->len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->output);
		free(tmp);
		free(e->output);
		e->output = res;
	}
}

void	int_width(t_env *e)
{
	int i;

	i = -1;
	e->len = ((int)ft_strlen(e->output) > e->flag->prec ?
	(int)ft_strlen(e->output) : e->flag->prec);
	(e->flag->plus + e->flag->space + e->flag->neg) >= 1 ? e->flag->width-- : 0;
	if (e->flag->prec >= 0)
	{
		while (e->flag->width - ++i > e->len)
			e->ret += write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->output) < e->len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag->width - ++i > e->len)
			e->ret += (e->flag->zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	int_print(t_env *e)
{
	int_prec(e);
	if (e->flag->zero)
	{
		int_sign(e);
		int_width(e);
		e->ret += write(e->fd, e->output, ft_strlen(e->output));
	}
	else if (e->flag->minus)
	{
		int_sign(e);
		e->ret += write(e->fd, e->output, ft_strlen(e->output));
		int_width(e);
	}
	else
	{
		int_width(e);
		int_sign(e);
		e->ret += write(e->fd, e->output, ft_strlen(e->output));
	}
	++e->i;
	free(e->output);
}