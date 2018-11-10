/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/09 01:51:22 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void get_spec(t_env *e, const char *format)
{
	if (format[e->i] == 'c')
		spec_char(e);
	if (format[e->i] == 's')
		spec_str(e);
	if (format[e->i] == 'd' || format[e->i] == 'i')
		spec_int(e);
}

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
	if (e->flag->mod == 2)
		e->output = ft_itoa((char)i);
	if (e->flag->mod == 1)
		e->output = ft_itoa((short)i);
	if (e->flag->mod == 3 || e->flag->mod == 4 || e->flag->mod == 5)
		e->output = ft_ltoa((long)i);
	if (e->flag->mod == 0)
		e->output = ft_itoa((int)tmp);
	int_print(e);
}