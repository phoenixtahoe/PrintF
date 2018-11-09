/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:02:24 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/08 23:58:12 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_width(t_env *e)
{
	e->flag->width = va_arg(e->ap, int);
	if (e->flag->width < 0)
	{
		e->flag->width = -e->flag->width;
		e->flag->minus = 1;
	}
}

void	get_prec(t_env *e, const char *format)
{
	if (e->flag->prec >= 0)
	{
		++e->i;
		return ;
	}
	if (format[e->i] == '.' && format[e->i + 1] == '*')
	{
		e->flag->prec = va_arg(e->ap, int);
		e->i += 2;
	}
	if (format[e->i] == '.')
	{
		++e->i;
		e->flag->prec = ft_atoi(format + e->i);
		while (format[e->i] >= '0' && format[e->i] <= '9')
			++e->i;
	}
}

void	get_mod(t_env *e, const char *format)
{
	if (format[e->i] == 'h' && format[e->i] + 1 != 'h')
		e->flag->mod = 1;
	if (format[e->i] == 'h' && format[e->i + 1 == 'h'])
		e->i++;
		e->flag->mod = 2;
	if (format[e->i] == 'l' && format[e->i + 1] != 'l')
		e->flag->mod = 3;
	if (format[e->i] == 'l' && format[e->i + 1] == 'l')
		e->i++;
		e->flag->mod = 4;
	if (format[e->i] == 't')
		e->flag->mod = 5;
}

void	get_flag(t_env *e, const char *format)
{
	while (ft_strchr(FLAG, format[e->i]))
	{
		if (format[e->i] >= 'L' && format[e->i] <= 'z')
			get_mod(e, format);
		if (format[e->i] == '-')
			e->flag->minus = 1;
		if (format[e->i] == '+')
			e->flag->plus = 1;
		if (format[e->i] == ' ')
			e->flag->space = 1;
		if (format[e->i] == '#')
			e->flag->hash = 1;
		if (format[e->i] == '0')
			e->flag->zero = 1;
		if (format[e->i] == '.')
			get_prec(e, format);
		if (format[e->i] == '*')
			get_width(e);
		else if (format[e->i] >= '1' && format[e->i] <= '9' && e->flag->prec < 0)
		{
			e->flag->width = ft_atoi(format + e->i);
			while (format[e->i] >= '0' && format[e->i] <= '9')
				++e->i;
		}
		else
			++e->i;
	}
}
