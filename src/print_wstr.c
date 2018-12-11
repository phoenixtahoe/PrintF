/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:49:00 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 23:45:03 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    put_wstr(t_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wchar(e, c);
	else if (c <= 0x7FF)
	{
		put_wchar(e, (c >> 6) + 0xC0);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(e, ((c >> 12) + 0xE0));
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar(e, (c >> 18) + 0xF0);
		put_wchar(e, ((c >> 12) & 0x3F) + 0x80);
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
}

int    wstr_width(wchar_t *c)
{
    int i;
    int len;

    len = 0;
    i = -1;
    while (c[++i] != 0)
	{
		if (c[i] <= 0x7F)
        {
             len++;
        }
	    else if (c[i] <= 0x7FF)
        {
            len += 2;   
        }
	    else if (c[i] <= 0xFFFF)
        {
            len += 3;
        }
	    else if (c[i] <= 0x10FFFF)
        {
            len += 4;
        }
	}
    return (len);
}

void	print_wstr(t_env *e, wchar_t *c)
{
    int i;

    i = -1;
    if (e->flag->prec < 0)
    {
        e->len = wstr_width(c);
    }
    else
    {
        e->len = e->flag->prec;
    }
    if (e->flag->minus)
    {
        if (e->flag->prec >= 0)
        {
            while (c[++i] != 0 && i < e->flag->prec)
            {
                put_wstr(e, c[i]);
            }
        }
        else
        {
            while (c[++i] != 0)
            {
                put_wstr(e, c[i]);
            }
            while (e->flag->width-- > 1)
            {
                if (e->flag->zero == 1)
                {
                    e->ret += write(e->fd, "0", 1);
                }
                else
                {
                    e->ret += write(e->fd, " ", 1);
                }
            }
        }
    }
    else
    {
        while (e->flag->width-- > 1)
        {
            if (e->flag->zero == 1)
            {
                e->ret += write(e->fd, "0", 1);
            }
            else
            {
                e->ret += write(e->fd, " ", 1);
            }
        }
        if (e->flag->prec >= 0)
        {
            while (c[++i] != 0 && i * 4 < e->flag->prec)
            {
                    put_wstr(e, c[i]);
            }
        }
        else
        {
            while (c[++i] != 0)
            {
                put_wstr(e, c[i]);
            }   
        }
        put_wstr(e, c[i]);
    }
    ++e->i;
}