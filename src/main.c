/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 16:26:25 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Il faut creer des fonctions pour gerer et interagir avec mon env cad sotcker,
manipuler et afficher les var d'env :
- fonction pour trier les var d'environnement dans ordre du shell
- fonction pour afficher les var d'env
- fonction pour copier les var d'env d'une t_list dans une string
*/

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_bzero(&data, sizeof(t_data));
	if (env[0] == NULL)
		return (FAILURE);
	set_env(&data, env);
	data.export = export_env(NULL);
	if (ac != 1)
		return (FAILURE);
	run_shell_loop(&data);
	// while (data.exit == 0)
	// {
	// 	//parsing + signal
	// 	if (data.token && data.exit == 0)
	// 		// launch_minishell(&data);
	// 	data.token = free_token(data.token);
	// }
	// free_all(&data);
	return (data.result);
}
