/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:43:03 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:24:44 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += convertbase_arg(ap, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

/*
int	main(void)
{
	ft_printf("%p\n", (void *)-1);
	printf("%p\n", (void *)-1);
	return (0);
}*/
