/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:45:38 by juduval           #+#    #+#             */
/*   Updated: 2023/10/19 16:48:33 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_msg(char c)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
}
