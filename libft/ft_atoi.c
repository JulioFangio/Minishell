/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:04 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:09:04 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	result;

	i = 0;
	signe = 1;
	result = 0;
	while ((nptr[i] && (nptr[i] >= 9 && nptr[i] <= 13)) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signe);
}
/*
int main(void)
{
	const char nptr[] = "   +1234";
	printf("%d\n", ft_atoi(nptr));
	return (0);
}*/
