/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:43:42 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/08 21:37:26 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags(t_flags *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->neg = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->mod = 0;
	flag->pos = 0;
}

void	init_format(t_env *e, const char *format)
{
	++e->i;
	get_flag(e, format);
	get_spec(e, format);
}

int		ft_printf(const char *format, ...)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	if (!(e->flag = (t_flags *)malloc(sizeof(t_flags))))
		exit(1);
	e->i = 0;
	e->fd = 1;
	e->len = 0;
	init_flags(e->flag);
	va_start(e->ap, format);
	while (format[e->i])
	{
		if (format[e->i] == '%')
		{
			init_format(e, format);
		}
		else if (format[e->i] == '%' && format[e->i + 1] != '%')
		{
			e->ret += write(e->fd, "%", 1);
			e->i += 2;
		}
		else
			e->ret += write(1 , &format[e->i++], 1);
	}
	va_end(e->ap);
	return(e->ret);
}