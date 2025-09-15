/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:50:18 by g-alves-          #+#    #+#             */
/*   Updated: 2025/09/15 20:00:14 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	validate_conversion(char *pointer);

int	ft_printf(const char *format, ...)
{
	char	*pointer;

	pointer = format;
	while (*pointer)
	{
		if (*pointer == '%')
		{
			validate_conversion(pointer + 1);
		}
		pointer++;
	}
}

void	validate_conversion(char *pointer)
{
	char	string[2];
	size_t	position;

	position = 0;
	string['c'] = print_char(*pointer);
	string['s'] = print_string(*pointer);
	while (string[position] != pointer)
		position++;
	while (string[position] == pointer)
	{
		
	}
}
