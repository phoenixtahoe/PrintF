/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:02:22 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 19:55:31 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa(int nbr)
{
	int		sign;
	int		count;
	char	*str;

	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = ft_strnew(count)))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
