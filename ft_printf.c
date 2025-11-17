/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:50:18 by g-alves-          #+#    #+#             */
/*   Updated: 2025/11/17 18:00:18 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	char		*pointer;
	va_list		args;
	size_t		count;

	count = 0;
	va_start(args, format);
	pointer = (char *)format;
	while (*pointer)
	{
		if (*pointer == '%')
		{
			count += (validate_conversion(*(pointer + 1), args));
			pointer += 2;
		}
		count += write(1, pointer++, 1);
	}
	return (count);
}

int	validate_conversion(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 'c' || type == 's')
		return (ft_printcstr(type, args));
	if (type == 'p')
		return (ft_pointer(va_arg(args, unsigned long)));
	if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (type == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_puthex("0123456789abcdef", args));
	if (type == 'X')
		return (ft_puthex("0123456789ABCDEF", args));
	if (type == '%')
		return (write(1, &"%", 1));
	return (0);
}

int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;
	int	o;
	int	p;
	int	q;
	int	r;

	i = ft_printf("%d\n", 0);
	j = ft_printf("%u\n", 0);
	k = ft_printf("%x\n", 0);
	l = ft_printf("%X\n", 0);
	m = ft_printf("%u\n", 4294967295u);

	n = printf("%d\n", 0);
	o = printf("%u\n", 0);
	p = printf("%x\n", 0);
	q = printf("%X\n", 0);
	r = printf("%u\n", 4294967295u);
	printf("i: %i, j: %i, k: %i, l: %i, m: %i, n: %i, o: %i, p: %i, q: %i, r: %i", i, j, k, l, m, n, o, p, q, r);
}
