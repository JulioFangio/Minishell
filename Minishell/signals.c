/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/08/14 18:21:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler()
{
    printf("\n");
    rl_on_new_line();
    rl_redisplay();
    get_prompt();
}

void run_shell_loop()
{
    using_history();

    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    t_data data;
    put_values(&data);
    while (1)
        ft_readline();
    clear_history();
}

// EOF pour ctrl+\
// SIGQUIT pour ctrl+d