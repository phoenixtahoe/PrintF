/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:10:14 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/11 12:54:39 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    init_base(t_env *e, char type, long val)
{
    if (e->flag->hash && e->output[0] != '\0' && val != 0)
    {
        if (type == 'o' || type == 'O')
        {
            e->ret += write(e->fd, "0", 1);
        }
        if (type == 'x' || type == 'X')
        {
            if (type == 'x')
                e->ret += write(e->fd, "0x", 2);
            else
                e->ret += write(e->fd, "0X", 2);
        }
        if (type == 'a' || type == 'A')
        {
            e->flag->width -= 2;
        }
    }
    else if (e->flag->prec >= 0 && (type == 'o' || type == 'O'))
    {
        e->ret += write(e->fd, "0", 1);
    }
    else if (type == 'a' || type == 'A')
    {
        if (e->flag->space || e->flag->plus)
        {
            if (e->flag->space)
            {
                e->ret += write(e->fd, " ", 1);
            }
            else
            {
                e->ret += write(e->fd, "+", 1);
            }
        }
        if (type == 'a')
        {
            e->ret += write(e->fd, "0x", 2);
        }
        else
        {
            e->ret += write(e->fd, "0X", 2);
        }
        e->flag->width--;
    }
}

void    width_base(t_env *e, char type)
{
    int len;
    int i;

    i = -1;
    len = ft_strlen(e->output);
    if (e->flag->hash && (e->output[0] != '\0' && e->output[0] != '0'))
    {
        if (type == 'o' || type == 'O')
        {
            e->flag->width -= 1;
        }
        if (type == 'x' || type == 'X')
        {
            e->flag->width -= 2;
        }
    }
    if (e->flag->prec >= 0)
    {
        while (e->flag->width > e->flag->prec + ++i && e->flag->width > len + i)
        {
            e->ret += write(e->fd, " ", 1);
        }
        while (e->flag->width > len + i++)
        {
            e->ret += write(e->fd, "0", 1);
        }
    }
    else
    {
        while (e->flag->width > len + ++i)
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


void    prec_base(t_env *e, char type)
{
    char *tmp;
    char *res;
    int len;
    int i;

    i = 0;
    len = ft_strlen(e->output);
    if (e->flag->prec == 0 && e->output[0] == '0')
    {
        e->output[0] = '\0';
    }
    else if (e->flag->prec > len)
    {
        if ((type == 'o' || type == 'O') && e->flag->hash)
        {
            e->flag->prec--;
        }
        i = e->flag->prec - len;
        tmp = ft_strnew(i);
        while (--i >= 0)
            tmp[i] = '0';
        res = ft_strjoin(tmp, e->output);
        free(tmp);
        free(e->output);
        e->output = res;
    }
}


void    print_base(t_env *e, char type, long val)
{
    prec_base(e, type);
    if (e->flag->zero)
    {
        init_base(e, type, val);
        width_base(e, type);
        e->ret += write(e->fd , e->output, ft_strlen(e->output));
    }
    else if (e->flag->minus)
    {
        init_base(e, type, val);
        e->ret += write(e->fd, e->output, ft_strlen(e->output));
        width_base(e, type);
    }
    else
    {
        width_base(e, type);
        init_base(e, type, val);
        e->ret += write(e->fd, e->output, ft_strlen(e->output));
    }
    ++e->i;
    free(e->output);
}