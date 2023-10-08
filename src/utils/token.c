/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:02:42 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/26 16:02:42 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*get_next_token(t_token *token, int next)
{
	if (token && next)
		token = token->next;
	while (token && token->type < PIPE)
		token = token->next;
	return (token);
}

t_token	*get_prev_token(t_token *token, int prev)
{
	if (token && prev)
		token = token->prev;
	while (token && token->type < PIPE)
		token = token->prev;
	return (token);
}

int	token_is_pipe(t_token *token)
{
	while (token && check_token(token, END) == 0)
	{
		if (check_token(token, PIPE) == SUCCESS)
			return (SUCCESS);
		token = token->next;
	}
	return (FAILURE);
}

int	check_token(t_token *token, int type)
{
	if (token && token->type == type)
		return (SUCCESS);
	else
		return (FAILURE);
}

t_token	*iter_token_cmd(t_token *token, int iter)
{
	if (token && iter)
		token = token->next;
	while (token && token->type != CMD)
	{
		token = token->next;
		if (token && token->type == CMD && !token->prev)
			;
		else if (token && token->type == CMD && token->prev->type != END)
			token = token->next;
	}
	return (token);
}
