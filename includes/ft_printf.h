/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:55:18 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 20:17:17 by pdavid           ###   ########.fr       */
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

# define FLAG " #*+-.0123456789Lhjltz"
# define PREC "fageFAGE"

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
	char				mod;
}					t_flags;

typedef	struct		s_tags
{
	int				tag;
	int				pos;
}					t_tags;

typedef	struct		s_env
{
	va_list			ap;
	t_flags			*flag;
	t_tags			*tag;
	char			*output;
	int				i;
	int				fd;
	int				ret;
	int				len;
}					t_env;

int		ft_printf(const char *format, ...);

/* Init Core */

void	init_format(t_env *e, const char *format);
void	init_flags(t_flags *flag);

/* Fetch op info */

void	get_spec(t_env *e, const char *format);
void	get_flag(t_env *e, const char *format);
void	get_width(t_env *e);
void	get_tag(t_env *e, const char *format);

/* str functions */

void	str_width(t_env *e);
void	str_null(t_env *e);
void	str_print(t_env *e);

/* char functions */

void	char_width(t_env *e);
void	char_null(t_env *e);
void	char_print(t_env *e);

/* w_char functions */

void	wutchar(t_env *e, char c);
void    print_wchar(t_env *e, wchar_t c);
void    put_wchar(t_env *e, wchar_t c);

/* w_str functions */

void	print_wstr(t_env *e, wchar_t *c);
int		wstr_width(wchar_t *c);
void    put_wstr(t_env *e, wchar_t c);

/* int functions */

void	int_sign(t_env *e);
void	int_check(t_env *e);
void	int_prec(t_env *e);
void	int_width(t_env *e);
void	int_print(t_env *e);

/* specification */

void	spec_char(t_env *e);
void	spec_str(t_env *e);
void	spec_int(t_env *e);
void	spec_percent(t_env *e);
void	spec_wchar(t_env *e, char type);
void	spec_wstr(t_env *e, char type);

/* helper functions */

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int nbr);
char	*ft_ltoa(long n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strcat(char *s1, const char *s2);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif