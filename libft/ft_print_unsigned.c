/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:59:57 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:25:24 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int		len;
	char	*char_nbr;

	len = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else
	{
		char_nbr = unsigned_itoa(nbr);
		len = ft_print_str(char_nbr);
		free(char_nbr);
	}
	return (len);
}
/*
int	main(void)
{
	ft_print_unsigned(-2);
//	printf("%u\n", -2);
	return (0);
}*/
