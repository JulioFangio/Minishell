/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:46 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:33:08 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_base(unsigned long nbr, const char *base)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (nbr >= len_base)
	{
		print_base(nbr / len_base, base);
		print_base(nbr % len_base, base);
	}
	else
		write(1, &base[nbr % len_base], 1);
}

char	*check_base(const char check)
{
	if (check == 'd' || check == 'i' || check == 'u')
		return ("0123456789");
	if (check == 'p' || check == 'x')
		return ("0123456789abcdef");
	if (check == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	convertbase_arg(va_list ap, const char convert)
{
	int		len;
	char	*base;

	len = 1;
	base = check_base(convert);
	if (convert == 'c')
		ft_putchar(va_arg(ap, int));
	else if (convert == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (convert == 'p')
		len = ft_print_ptr(va_arg(ap, unsigned long), base);
	else if (convert == 'd' || convert == 'i')
		len = ft_print_nbr(va_arg(ap, int));
	else if (convert == 'u')
		len = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (convert == 'x')
		len = ft_print_hex(va_arg(ap, unsigned int), base);
	else if (convert == 'X')
		len = ft_print_hex(va_arg(ap, unsigned int), base);
	else if (convert == '%')
		len = write(1, "%", 1);
	return (len);
}
