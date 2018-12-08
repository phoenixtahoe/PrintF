/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 23:20:01 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	spec_char(t_env *e)
{
	char tmp;
	
	tmp = va_arg(e->ap, int);
	e->output = &tmp;
	char_print(e);
}

void	spec_str(t_env *e)
{
	char	*tmp;

	tmp = va_arg(e->ap, char *);
	if (tmp == NULL)
		return (str_null(e));
	e->output = ft_strdup((char*)tmp);
	str_print(e);
}

void	spec_int(t_env *e)
{
	long	tmp;
	long	i;

	tmp = va_arg(e->ap, long);
	i = (long long)tmp;
	if (e->flag->minus == 1)
		e->flag->zero = 0;
	if (e->flag->prec >= 0)
		e->flag->zero = 0;
	if (tmp == LLONG_MAX || tmp == LONG_MIN)
		e->output = ft_strdup("-9223372036854775808");
	else if (e->flag->mod == 2)
		e->output = ft_itoa((char)i);
	else if (e->flag->mod == 1)
		e->output = ft_itoa((short)i);
	else if (e->flag->mod == 3 || e->flag->mod == 4 || e->flag->mod == 5)
		e->output = ft_ltoa((long)i);
	else if (e->flag->mod == 0)
		e->output = ft_itoa((int)tmp);
	int_print(e);
}

void	spec_percent(t_env *e)
{
	if (e->flag->minus)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flag->width-- > 1)
		{
			e->ret += write(e->fd, " ", 1);
		}
	}
	else
	{
		while (e->flag->width-- > 1)
		{
			if (e->flag->zero)
			{
				e->ret += write(e->fd, "0", 1);
			}
			else
			{
				e->ret += write(e->fd, " ", 1);
			}
		}
		e->ret += write(e->fd, "%", 1);
	}
	++e->i;
}

void	spec_wchar(t_env *e, char type)
{
	wchar_t wc;

	wc = va_arg(e->ap, wchar_t);
	if (e->flag->minus)
	{
		e->flag->zero = 0;
	}
	if (type == 'C')
	{
		if (wc == 0)
		{
			return(char_null(e));
		}
		print_wchar(e, wc);
	}
}

void	spec_wstr(t_env *e, char type)
{
	wchar_t	*ws;

	ws = va_arg(e->ap, wchar_t *);
	if (e->flag->minus)
	{
		e->flag->zero = 0;
	}
	if (type == 'S' || type == 's')
	{
		if (ws == NULL)
		{
			return(str_null(e));
		}
		print_wstr(e, ws);
	}
}