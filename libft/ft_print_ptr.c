/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:42:43 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:25:24 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		len += write(1, "0x", 2);
		print_base(n, base);
	}
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}
