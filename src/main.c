/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/11/09 01:48:39 by pdavid           ###   ########.fr       */
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
	// printf("%c\n", 'c' );
	// ft_printf("%c\n", 'c');
	// printf("%s\n", "fuck the ops");
	// ft_printf("%s\n", "fuck the ops");
	// printf("' ':				[% d]\n", -12);
	// ft_printf("' ':				[% d]\n", -12);
	// printf("10.6:				[% 10.6d]\n", 12);
	// ft_printf("10.6:				[% 10.6d]\n", 12);
	// printf("%swidth 10:			[%8s]\n", YELLOW, "Hello");
	// ft_printf("%swidth 10:			[%8s]\n", YELLOW, "Hello");
	// ft_printf("%swidth 10:			[%8s]\n", CURT, "Hello");
	// printf("width 10:			[%10X]\n", 1244);
	// ft_printf("width 10:			[%10X]\n", 1244);
	// printf("' ':				[% d]\n", -12);
	// ft_printf("' ':				[% d]\n", -12);
	// printf("10.6:				[% 10.6d]\n", 12);
	// ft_printf("10.6:				[% 10.6d]\n", 12);
	// printf("0 10.6:				[%0 10.6d]\n", 12);
	// ft_printf("0 10.6:				[%0 10.6d]\n", 12);
	// printf("-+10.5:				[%-+10.5d]\n", -12);
	// ft_printf("-+10.5:				[%-+10.5d]\n", -12);
	printf("zero:	[%0i]\n", 12);
	ft_printf("zero:	[%0i]\n", 12);
	printf("width 10:	[%10i]\n", 12);
	ft_printf("width 10:	[%10i]\n", 12);
	printf("precyzja 1:	[%.1i]\n", 12);
	ft_printf("precyzja 1:	[%.1i]\n", 12);
	printf("width 10 prec 1:	[%10.1i]\n", 12);
	ft_printf("width 10 prec 1:	[%10.1i]\n", 12);
	printf("width 10 prec 6:	[%10.6i]\n", 12);
	ft_printf("width 10 prec 6:	[%10.6i]\n", 12);
	// ft_printf("- width 10 prec 6:		[%-10.6i]\n", 12);
	// printf("- width 10 prec 6:			[%-10.6i]\n", 12);
	// ft_printf("0 width 4 prec 3:		[%04.3d]\n", -1);
	// printf("0 width 4 prec 3:			[%04.3d]\n", -1);
	// ft_printf("+ width 10 prec 5:		[%+10.5d]\n", 25);
	// printf("+ width 10 prec 5:			[%+10.5d]\n", 25);
	// ft_printf("width 10 prec 5:			[%+10.5d]\n", -25);
	// printf("width 10 prec 5:			[%+10.5d]\n", -25);
	// ft_printf("0 width 3 prec 2:		[%03.2d]\n", -1);
	// printf("0 width 3 prec 2:			[%03.2d]\n", -1);
	// ft_printf("prec 10:					[%.10d]\n", -12);
	// printf("prec 10:					[%.10d]\n", -12);
	// ft_printf("width 5 prec .:			[%5.d]\n", 0);
	// printf("width 5 prec .:				[%5.d]\n", 0);
	// ft_printf("42:						[%d]\n", 42);
	// printf("42:							[%d]\n", 42);
	// ft_printf("m: 0 width 3:			[% 04d]\n", 1);
	// printf("t: 0 width 3:				[% 04d]\n", 1);
	// ft_printf("width 4 prec.:			[%4.d]\n", 0);
	// printf("width 4 prec.:				[%4.d]\n", 0);
	// ft_printf("m: 0 width 10:			[%010d]\n", 0);
	// printf("t: 0 width 10:				[%010d]\n", 0);
	// ft_printf("0 width 5:				[%05d]\n", -42);
	// printf("0 width 5:					[%05d]\n", -42);
	// ft_printf("- width 5:				[%-5d]\n", -42);
	// printf("- width 5:					[%-5d]\n", -42);
	// ft_printf("+ width 10 prec 5:		[%+10.5d]\n", 4242);
	// printf("+ width 10 prec 5:			[%+10.5d]\n", 4242);
	// ft_printf("0 width 3 prec 2:		[%03.2d]\n", 0);
	// printf("0 width 3 prec 2:			[%03.2d]\n", 0);
	// ft_printf("0 width 3 prec 2:		[%03.2d]\n", -1);
	// printf("0 width 3 prec 2:			[%03.2d]\n", -1);
	// ft_printf("space:					[% d]\n", 42);
	// printf("space:						[% d]\n", 42);
	// ft_printf("plus:					[%+d]\n", 0);
	// printf("plus:						[%+d]\n", 0);
	// ft_printf("width 10:				[%10d]\n", 0);
	// printf("width 10:					[%10d]\n", 0);
	// ft_printf("prec 5:					[%.5d]\n", 0);
	// printf("prec 5:						[%.5d]\n", 0);
	// ft_printf("' ' width 5:				[% 5d]\n", 4);
	// printf("' ' width 5:				[% 5d]\n", 4);
	// ft_printf("' ' prec 5:				[%.5d]\n", 4);
	// printf("' ' prec 5:					[%.5d]\n", 4);
	// ft_printf("' ' prec 5:				[%.5d]\n", 0);
	// printf("' ' prec 5:					[%.5d]\n", 0);
	// ft_printf("0+ width 5:				[%0+5d]\n", -1);
	// printf("0+ width 5:					[%0+5d]\n", -1);
	// ft_printf("prec 0:					[%.0d]\n", -1);
	// printf("prec 0:						[%.0d]\n", -1);
	// ft_printf("++ width 10:				[%++10d]\n", -42);
	// printf("++ width 10:				[%++10d]\n", -42);
	// ft_printf("width 10:				[%10d]\n", -42);
	// printf("width 10:					[%10d]\n", -42);
	// ft_printf("+0 width 10:				[%+010d]\n", +42);
	// printf("+0 width 10:				[%+010d]\n", +42);
	// ft_printf("+0 width 4:				[%+04d]\n", 42);
    // printf("+0 width 4:					[%+04d]\n", 42);
    // ft_printf("							[%ld]\n", 9223372036854775807);
	// printf("							[%ld]\n",  9223372036854775807);
	// ft_printf("							%.1d\n", 10);
	// printf("							%.1d\n", 10);
	// printf("' ':						[% i]\n", -12);
	// ft_printf("' ':						[% i]\n", -12);
	// printf("10.6:						[% 10.6i]\n", 12);
	// ft_printf("10.6:					[% 10.6i]\n", 12);
	// printf("0 10.6:						[%0 10.6i]\n", 12);
	// ft_printf("0 10.6:					[%0 10.6i]\n", 12);
	// printf("-+10.5:						[%-+10.5i]\n", -12);
	// ft_printf("-+10.5:					[%-+10.5i]\n", -12);
	// printf("zero:						[%0i]\n", 12);
	// ft_printf("zero:					[%0i]\n", 12);
	// printf("width 10:					[%10i]\n", 12);
	// ft_printf("width 10:				[%10i]\n", 12);
	// ft_printf("minus and width 10:		[%-10i]\n", 12);
	// printf("minus and width 10:			[%-10i]\n", 12);
	// ft_printf("precyzja 1:				[%.1i]\n", 12);
	// printf("precyzja 1:					[%.1i]\n", 12);
	// ft_printf("width 10 prec 1:			[%10.1i]\n", 12);
	// printf("width 10 prec 1:			[%10.1i]\n", 12);
	// ft_printf("width 10 prec 6:			[%10.6i]\n", 12);
	// printf("width 10 prec 6:			[%10.6i]\n", 12);
	// ft_printf("- width 10 prec 6:		[%-10.6i]\n", 12);
	// printf("- width 10 prec 6:			[%-10.6i]\n", 12);
	// ft_printf("0 width 4 prec 3:		[%04.3i]\n", -1);
	// printf("0 width 4 prec 3:			[%04.3i]\n", -1);
	// ft_printf("+ width 10 prec 5:		[%+10.5i]\n", 25);
	// printf("+ width 10 prec 5:			[%+10.5i]\n", 25);
	// ft_printf("width 10 prec 5:			[%+10.5i]\n", -25);
	// printf("width 10 prec 5:			[%+10.5i]\n", -25);
	// ft_printf("0 width 3 prec 2:		[%03.2i]\n", -1);
	// printf("0 width 3 prec 2:			[%03.2i]\n", -1);
	// ft_printf("prec 10:					[%.10i]\n", -12);
	// printf("prec 10:					[%.10i]\n", -12);
	// ft_printf("width 5 prec .:			[%5.i]\n", 0);
	// printf("width 5 prec .:				[%5.i]\n", 0);
	// ft_printf("42:						[%i]\n", 42);
	// printf("42:							[%i]\n", 42);
	// ft_printf("m: 0 width 3:			[% 04i]\n", 1);
	// printf("t: 0 width 3:				[% 04i]\n", 1);
	// ft_printf("width 4 prec.:			[%4.i]\n", 0);
	// printf("width 4 prec.:				[%4.i]\n", 0);
	// ft_printf("m: 0 width 10:			[%010i]\n", 0);
	// printf("t: 0 width 10:				[%010i]\n", 0);
	// ft_printf("0 width 5:				[%05i]\n", -42);
	// printf("0 width 5:					[%05i]\n", -42);
	// ft_printf("- width 5:				[%-5i]\n", -42);
	// printf("- width 5:					[%-5i]\n", -42);
	// ft_printf("+ width 10 prec 5:		[%+10.5i]\n", 4242);
	// printf("+ width 10 prec 5:			[%+10.5i]\n", 4242);
	// ft_printf("0 width 3 prec 2:		[%03.2i]\n", 0);
	// printf("0 width 3 prec 2:			[%03.2i]\n", 0);
	// ft_printf("0 width 3 prec 2:		[%03.2i]\n", -1);
	// printf("0 width 3 prec 2:			[%03.2i]\n", -1);
	// ft_printf("space:					[% i]\n", 42);
	// printf("space:						[% i]\n", 42);
	// ft_printf("plus:					[%+i]\n", 0);
	// printf("plus:						[%+i]\n", 0);
	// ft_printf("width 10:				[%10i]\n", 0);
	// printf("width 10:					[%10i]\n", 0);
	// ft_printf("prec 5:					[%.5i]\n", 0);
	// printf("prec 5:						[%.5i]\n", 0);
	// ft_printf("' ' width 5:				[% 5i]\n", 4);
	// printf("' ' width 5:				[% 5i]\n", 4);
	// ft_printf("' ' prec 5:				[%.5i]\n", 4);
	// printf("' ' prec 5:					[%.5i]\n", 4);
	// ft_printf("' ' prec 5:				[%.5i]\n", 0);
	// printf("' ' prec 5:					[%.5i]\n", 0);
	// ft_printf("0+ width 5:				[%0+5i]\n", -1);
	// printf("0+ width 5:					[%0+5i]\n", -1);
	// ft_printf("prec 0:					[%.0i]\n", -1);
	// printf("prec 0:						[%.0i]\n", -1);
	// ft_printf("++ width 10:				[%++10i]\n", -42);
	// printf("++ width 10:				[%++10i]\n", -42);
	// ft_printf("width 10:				[%10i]\n", -42);
	// printf("width 10:					[%10i]\n", -42);
	// ft_printf("+0 width 10:				[%+010i]\n", +42);
	// printf("+0 width 10:				[%+010i]\n", +42);
	// ft_printf("+0 width 4:				[%+04i]\n", 42);
    // printf("+0 width 4:					[%+04i]\n", 42);
    // ft_printf("							[%li]\n", 9223372036854775807);
	// printf("							[%li]\n",  9223372036854775807);
	// ft_printf("							%.1i\n", 10);
	// printf("							%.1i\n", 10);
	return (0);
}
