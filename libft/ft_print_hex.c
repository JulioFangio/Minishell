/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:22:46 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:31:20 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, const char *base)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	else
		print_base(n, base);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}
