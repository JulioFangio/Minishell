/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/10/26 16:32:51 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	rl_replace_line("", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Minishell$ ", 1);
}

void	redir(t_data *data)
{
	(void)data;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
}
