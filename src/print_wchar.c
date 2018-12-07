/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:21:30 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/06 15:19:50 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    wutchar(t_env *e, char c)
{
    write(e->fd, &c, 1);
}

void    put_wchar(t_env *e, wchar_t c)
{
	if (c <= 0x7F)
		wutchar(e, c);
	else if (c <= 0x7FF)
	{
		wutchar(e, (c >> 6) + 0xC0);
		wutchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		wutchar(e, ((c >> 12) + 0xE0));
		wutchar(e, ((c >> 6) & 0x3F) + 0x80);
		wutchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		wutchar(e, (c >> 18) + 0xF0);
		wutchar(e, ((c >> 12) & 0x3F) + 0x80);
		wutchar(e, ((c >> 6) & 0x3F) + 0x80);
		wutchar(e, (c & 0x3F) + 0x80);
	}
    ++e->ret;
}

void    print_wchar(t_env *e, wchar_t c)
{
    if (e->flag->minus)
    {
        put_wchar(e, c);
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
        put_wchar(e, c);
    }
    ++e->i;
}
