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

int	check_token(t_token *token, int type)
{
	if (token && token->type == type)
		return (1);
	else
		return (0);
}

int	is_def_type(t_token *token, int type)
{
	if (type == NO_ARG && check_token(token, NO_ARG))
		return (1);
	else if (type == CMD && check_token(token, CMD))
		return (1);
	else if (type == ARG && check_token(token, ARG))
		return (1);
	else if (type == PIPE && check_token(token, PIPE))
		return (1);
	else if (type == CHEVRON && check_token(token, CHEVRON))
		return (1);
	else if (type == OPEN_CHEVRON && check_token(token, OPEN_CHEVRON))
		return (1);
	else if (type == DOUBLE_CHEVRON && check_token(token, DOUBLE_CHEVRON))
		return (1);
	return (0);
}

/*iterates through a list of tokens,
finds the next token of type CMD according
to the specific conditions, and returns it*/
t_token	*iter_token_cmd(t_token *token, int iter)
{
	if (token && iter)
		token = token->next;
	while (token)
	{
		if (token->type == CMD)
			return (token);
		token = token->next;
	}
	return (NULL);
}
