/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/06 15:54:14 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
#include <stdlib.h>
#include <stddef.h>
# define YELLOW        "\x1B[33m"
# define CURT		"\x1B[0m"


int main()
{
	int a;

	a = 150;
	setlocale(LC_ALL, "");
	
	printf("normal: [%C]\n", L'👼');
	ft_printf("normal: [%C]\n", L'👼');
	
	printf("width 20 = [%C]\n", L'갔');
	ft_printf("width 20 = [%C]\n", L'갔');
	
	printf("width 20 = [%20S]\n", L"@@");
	ft_printf("width 20 = [%20S]\n", L"@@");

	
	ft_printf("space: [% i]\n", 42);
	printf("space: [% i]\n", 42);
	
	ft_printf("plus: [%+i]\n", 0);
	printf("plus: [%+i]\n", 0);
	
	ft_printf("width 10: [%10i]\n", 0);
	printf("width 10: [%10i]\n", 0);
	
	ft_printf("prec 5: [%.5i]\n", 0);
	printf("prec 5: [%.5i]\n", 0);
	
	ft_printf("width 5:	[%5i]\n", 4);
	printf("width 5: [%5i]\n", 4);

	ft_printf("prec 5: [%.5i]\n", 4);
	printf("prec 5: [%.5i]\n", 4);

	ft_printf("prec 5: [%.5i]\n", 0);
	printf("prec 5: [%.5i]\n", 0);
	
	
	ft_printf("prec 0: [%.0i]\n", -1);
	printf("prec 0: [%0.i]\n", -1);
	
	
	ft_printf("width 10: [%10i]\n", +42);
	printf("width 10: [%10i]\n", +42);
	
	ft_printf("width 4: [%4i]\n", 42);
    printf("width 4: [%4i]\n", 42);
	return (0);
}
