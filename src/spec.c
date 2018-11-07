/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/07 04:33:50 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void get_spec(t_env *e, const char *format)
{
	if (format[e->i] == 'c')
	{
		spec_char(e, format[e->i]);
	}
	else if (format[e->i] == 's')
	{
		spec_str(e, format[e->i]);
	}
	else if (format[e->i] == 'd' || format[e->i] == 'i')
	{
		spec_int(e);
	}
}

void	spec_char(t_env *e, char type)
{
	int		tmp;

		if (type == 'c')
		{
			char_arg(e, &tmp);
			char_print(e, tmp);
		}
}

void	spec_str(t_env *e, char type)
{
	char	*tmp;

	if (type == 's')
	{
		str_arg(e, &tmp);
		if (tmp == NULL)
		{
			return (str_null(e));
		}
		e->output = ft_strdup((char*)tmp);
		str_print(e);
	}
}

void	spec_int(t_env *e)
{
	long	tmp;
	long	i;
	
	int_arg(e, &tmp);
	i = (long long)tmp;
	if (tmp == 9223372036854775807 || tmp == 	-2147483647)					/*	llong min & long min	*/
		e->output = ft_strdup("-9223372036854775808");
	else if (e->flag.mod == '0')
		e->output = ft_itoa((int)i);
	int_print(e);
}