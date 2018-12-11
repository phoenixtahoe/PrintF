/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:44:18 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/11 13:05:38 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_sign(t_env *e)
{
	if (e->flag->space)
		e->ret += write(e->fd, " ", 1);
	if (e->flag->plus == 1)
		e->ret += write(e->fd, "+", 1);
	else if (e->flag->neg)
		e->ret += write(e->fd, "-", 1);
}

void	int_width(t_env *e)
{
	int len;
	int i;

	i = -1;
	if (((int)ft_strlen(e->output) > e->flag->prec))
	{
		len = (int)ft_strlen(e->output);
	}
	else
	{
		len = e->flag->prec;
	}
	if ((e->flag->plus + e->flag->space + e->flag->neg) >= 1)
	{
		e->flag->width--;
	}
	if (e->flag->prec >= 0)
	{
		while (e->flag->width - ++i > len)
			e->ret += write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->output) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
	{
		while (e->flag->width - ++i > len)
		{
			if (e->flag->zero == 1)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		}
	}
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
	int		len;
	int		i;

	i = 0;
	int_check(e);
	len = (int)ft_strlen(e->output);
	if (e->flag->prec == 0 && e->output[0] == '0')
	{
		e->output[0] = '\0';
	}
	else if (e->flag->prec > len)
	{
		i = e->flag->prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->output);
		free(tmp);
		free(e->output);
		e->output = res;
	}
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