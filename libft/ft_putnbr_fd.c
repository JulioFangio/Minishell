/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:53:22 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 18:42:57 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nmb;

	nmb = n;
	if (nmb < 0)
	{
		ft_putchar_fd('-', fd);
		nmb = -nmb;
	}
	if (nmb > 9)
	{
		ft_putnbr_fd(nmb / 10, fd);
		nmb %= 10;
	}
	ft_putchar_fd(nmb + '0', fd);
}
/*
int	main(void)
{
	int fd = 1;
	int n = 42;
	ft_putnbr_fd(n, fd);
	return (0);
}*/
