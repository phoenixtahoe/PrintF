/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:06:48 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 19:55:42 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = ft_strlen(src);
	p = (char*)malloc((i + 1) * sizeof(char));
	if (p)
		return (ft_strcpy(p, src));
	return (NULL);
}
