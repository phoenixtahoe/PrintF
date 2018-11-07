/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:43:42 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/07 04:51:13 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flag(t_flags *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->neg = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
}

void	init_format(t_env *e, const char *format)
{
	++e->i;
	e->len = 0;
	get_tag(e, format);
	get_flag(e, format);
	get_spec(e, format);
}

int		ft_printf(const char *format, ...)
{
	t_env e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	va_start(e.ap[0], format);
	va_copy(e.ap[1], e.ap[0]);
	while (format[e.i])
	{
		if (format[e.i] == '%')
		{
			init_format(&e, format);
		}
		else if (format[e.i] == '%' && format[e.i + 1] != '%')
		{
			e.ret += write(e.fd, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(1 , &format[e.i++], 1);
	}
	va_end(e.ap[0]);
	return(e.ret);
}
