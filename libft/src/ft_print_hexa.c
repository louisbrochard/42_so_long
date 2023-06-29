/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:44:57 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/29 10:31:01 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../includes/ft_printf.h"

#define HEXA_UP "0123456789ABCDEF"
#define HEXA_LOW "0123456789abcdef"

void	sub_fonction(char c, int *len, long dec)
{
	char	s;

	if (c == 'X')
	{
		s = HEXA_UP[dec];
		*len += write(1, &s, 1);
	}
	else
	{
		s = HEXA_LOW[dec];
		*len += write(1, &s, 1);
	}
}

void	ft_printer_hextodec(long dec, int *len, char c)
{
	char	s;

	if (dec < 16)
		sub_fonction(c, len, dec);
	else
	{
		if (c == 'X')
		{
			ft_printer_hextodec(dec / 16, len, c);
			s = HEXA_UP[dec % 16];
			*len += write(1, &s, 1);
		}
		else
		{
			ft_printer_hextodec(dec / 16, len, c);
			s = HEXA_LOW[dec % 16];
			*len += write(1, &s, 1);
		}
	}
}

int	ft_printer_x(unsigned int nb, char c)
{
	int	len;

	len = 0;
	ft_printer_hextodec(nb, &len, c);
	return (len);
}
