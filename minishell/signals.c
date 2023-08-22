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

void    sigint_handler(int signum)
{
    (void)signum;
    printf("lol\n");
    rl_on_new_line();
    rl_redisplay();
    get_prompt();
}

void    sigquit_handler(int signum)
{
    (void)signum;
    rl_on_new_line();
    rl_redisplay();
}

void    sigterm_handler(int signum)
{
    (void)signum;
    exit(0);
}

void    redir()
{
    struct sigaction si;
    struct sigaction sq;
    struct sigaction st;

    si.sa_handler = sigint_handler;
    sigemptyset(&si.sa_mask);
    si.sa_flags = 0;
    sigaction(SIGINT, &si, NULL);

    sq.sa_handler = sigquit_handler;
    sigemptyset(&sq.sa_mask);
    sq.sa_flags = 0;
    sigaction(SIGQUIT, &sq, NULL);

    st.sa_handler = sigterm_handler;
    sigemptyset(&st.sa_mask);
    st.sa_flags = 0;
    sigaction(SIGTERM, &st, NULL);
}

void run_shell_loop()
{
    using_history();

    while (1)
        get_split();
    rl_clear_history();
}
