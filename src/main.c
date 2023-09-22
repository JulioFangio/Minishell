/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 15:55:03 by jaristil         ###   ########.fr       */
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

void	redir_exec(t_data *data, t_token *token)
{
	int		pipe;
	t_token	*prev_tok;
	t_token	*next_tok;

	//next_token = ();
	//prev_token = ();
	pipe = 0;
	if (is_type(prev_tok, CHEVRON))
		redir(data, token, CHEVRON);
	else if (is_type(prev_tok, DOUBLE_CHEVRON))
		redir(data, token, DOUBLE_CHEVRON);
	else if (is_type(prev_tok, PIPE))
		pipe = is_pipe(data);
	else if (is_type(prev_tok, OPEN_CHEVRON))
		is_open_chev(data, token);
	else if (is_type(prev_tok, DOUBLE_INPUT))
		is_here_doc(data, token);
	if (next_tok && is_type(next_tok, END) == 0 && pipe != 1)
		redir_exec(data, next_tok->next);
	if ((is_type(prev_tok, END) || is_type(prev_tok, PIPE) || !prev_tok)
		&& pipe != 1)
		exec_command(data, token);
}

void	launch_minishell(t_data *data)
{
	t_token	*token;
	int		status;

	while (data->exit == 0 && token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		redir_exec(data, token);
		waitpid(-1, &status, 0);
		WEXITSTATUS(status);
		if (data->end == 0)
			data->result = status;
	}
}

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
	run_shell_loop();
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
