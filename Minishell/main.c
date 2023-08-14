/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:15:59 by juduval           #+#    #+#             */
/*   Updated: 2023/08/14 17:59:56 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    put_values(t_data *data)
{
	data->signals.ctrl_c = 0;
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;

    run_shell_loop();

    return 0;
}
