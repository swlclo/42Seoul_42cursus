/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seowoo <seowoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:34:09 by seowoo            #+#    #+#             */
/*   Updated: 2021/04/06 20:23:47 by seowoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_ftag *tag)
{
	tag->minus = 0;
	tag->zero = 0;
	tag->width = 0;
	tag->dot = 0;
	tag->precision = 0;
	tag->type = 0;
	tag->padding = ' ';
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_ftag	tag;
	int		nbr_characters;

	va_start(ap, format);
	ft_init(&tag);
	nbr_characters = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format++, 1);
			nbr_characters++;
			continue;
		}
		format++;
		nbr_characters += ft_parse(&format, ap, &tag);
		format++;
		ft_init(&tag);
	}
	va_end(ap);
	return (nbr_characters);
}
