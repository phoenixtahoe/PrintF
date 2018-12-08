/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:39:37 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 19:55:53 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *tab;

	if (!(tab = (void *)malloc(size + 1)))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
