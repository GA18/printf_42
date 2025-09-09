/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g-alves- <g-alves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:50:18 by g-alves-          #+#    #+#             */
/*   Updated: 2025/09/09 14:55:43 by g-alves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	validate_conversion(const char *position);

int	ft_printf(const char *format, ...)
{
	char	*pointer;

	pointer = format;
	while (*pointer)
	{
		if (*pointer == "%")
		{
			validate_conversion(*pointer + 1);
		}
		pointer++;
	}
}

void	validate_conversion(const char *position)
{
	struct conversion {
		
	}
}