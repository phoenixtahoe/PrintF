/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:55:18 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/06 20:22:57 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# include "../includes/libft/libft.h"

# define FLAG " #*+-.0123456789Lhjltz"

typedef	struct		s_flags
{
	int				space;
	int				pos;
	int				plus;
	int				neg;
	int				minus;
	int				hash;
	int				zero;
	int				width;
	int				prec;
}					t_flags;

typedef	struct		s_tags
{
	int				tag;
	int				pos;
}					t_tags;

typedef	struct		s_env
{
	va_list			ap[2];
	t_flags			flag;
	t_tags			tag;
	char			*output;
	int				i;
	int				fd;
	int				ret;
	int				len;
}					t_env;

int		ft_printf(const char *format, ...);

/* Init Core */

void	init_flag(t_flags *flag);

/* Fetch op info */

void	get_spec(t_env *e, const char *format);
void	get_flag(t_env *e, const char *format);
void	get_width(t_env *e);
void	get_tag(t_env *e, const char *format);

/* str functions */

void	str_width(t_env *e);
void	str_null(t_env *e);
void	str_print(t_env *e);
void	str_arg(t_env *e, char **tmp);

/* char functions */

void	char_width(t_env *e);
void	char_null(t_env *e);
void	char_print(t_env *e, char c);
void	char_arg(t_env *e, int *tmp);

/* specification */

void	spec_char(t_env *e, char type);
void	spec_str(t_env *e, char type);

#endif