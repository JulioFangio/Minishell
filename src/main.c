/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 19:14:10 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	secure_fds(void)
{
	int	i;

	i = 3;
	while (i < 1025)
	{
		close(i);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data		data;

	(void)ac;
	(void)av;
	if (env[0] == NULL)
		return (FAILURE);
	ft_bzero(&data, sizeof(t_data));
	reset_to_initial_fd(&data);
	set_env(&data, env);
	if (ac != 1)
		return (FAILURE);
	run_shell_loop(&data);
	secure_fds();
	return (data.result);
}
