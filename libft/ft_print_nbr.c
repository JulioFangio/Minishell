/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:03:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:30:47 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*char_nbr;

	len = 0;
	char_nbr = ft_itoa(nbr);
	len = ft_print_str(char_nbr);
	free(char_nbr);
	return (len);
}
