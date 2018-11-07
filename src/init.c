/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/06 20:22:06 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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