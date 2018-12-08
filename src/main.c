/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:54 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/07 23:06:48 by pdavid           ###   ########.fr       */
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
	ft_printf("You can" "[%0+5d]\n", 42);
	printf("Do dis" "[%0+5d]\n", 42);
	return (0);
}
