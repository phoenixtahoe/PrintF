/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/07 21:42:29 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{
	int a;
	
	a = 150;
	setlocale(LC_ALL, "");
	printf("%c\n", 'c' );
	ft_printf("%c\n", 'c');
	// printf("%s\n", "fuck the ops");
	// ft_printf("%s\n", "fuck the ops");
	// printf("[%i]\n", 'a');
	// ft_printf("[%i]\n", 'a');
	return (0);
}
