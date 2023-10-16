/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:36:26 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 14:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fill_it(t_data *data, t_token *tmp, int check, int optn)
{
	int	i;
	int	res;

	i = -1;
	while (tmp && data->tab[++i])
	{
		res = 0;
		if (!optn)
		{
			res = scenario(data->tab[i], check);
			exec_scenario(data, tmp, data->tab[i], res);
		}
		else
			optn = ft_optn(tmp, data->tab[i], optn);
		if (res == 11 || res == 12)
			check = 1;
		else if (res == 9)
			check = 0;
		else if (res == 7 || res == 8)
			optn = res;
		tmp = tmp->next;
	}
}

void	fill_list(t_data *data, int check)
{
	t_token		*tmp;
	int			optn;

	optn = 0;
	tmp = data->token;
	fill_it(data, tmp, check, optn);
}
// ## + prototype

void	get_token(t_data *data)
{
	t_token	*tmp;

	data->token = make_cmd(data->tab);
	fill_list(data, 0);
	tmp = data->token;
	// while (tmp)
	// {
	// 	printf(" str = %s / type = %d\n", tmp->str, tmp->type);
	// 	tmp = tmp->next;
	// }
}
// ##