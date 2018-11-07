/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/06 20:05:21 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{

	setlocale(LC_ALL, "");
	printf("%c\n", 'c' );
	ft_printf("%c\n", 'c');
	printf("%s\n", "fuck the ops");
	ft_printf("%s\n", "fuck the ops");
	return (0);
}
