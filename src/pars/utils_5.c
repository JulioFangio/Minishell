/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:54:50 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:42:07 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_var(char *tronc)
{
	int		i;
	int		b;
	char	*var;
	int		j;

	i = 0;
	b = 0;
	while (tronc[i] && tronc[i] != '$')
		i++;
	j = i;
	while (tronc[i] && tronc[i] != 32 && tronc[i] != 9 && tronc[i] != 13
		&& tronc[i] != '\'' && tronc[i] != '"')
		i++;
	b = i - j;
	var = ft_calloc((b + 1), sizeof(char));
	i = 0;
	while (tronc[j] && tronc[j] != 32 && tronc[j] != 9 && tronc[j] != 13
		&& tronc[j] != '\'' && tronc[j] != '"')
	{
		var[i] = tronc[j];
		i++;
		j++;
	}
	return (var);
}

char	*extract_var(t_data *data, char *tronc, char *var)
{
	int		lv;
	int		lg;
	int		lr;
	char	*res;
	char	*gvar;

	if (var[0] == '$' && var[1] == '?')
		gvar = ft_itoa(data->result);
	else
		gvar = pick_env(data, var);
	lv = ft_strlen(var);
	lg = ft_strlen(gvar);
	lr = lg - lv;
	res = ft_calloc((ft_strlen(tronc) + lr) + 1, sizeof(char));
	get_new_line(res, tronc, gvar, lv);
	if (strcmp(gvar, var))
		free (gvar);
	return (res);
}

static size_t	write_exp(char *res, char *gvar, size_t j)
{
	int	k;

	k = 0;
	while (gvar[k])
	{
		res[j] = gvar[k];
		k++;
		j++;
	}
	return (j);
}

void	get_new_line(char *res, char *tronc, char *gvar, int lv)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (tronc[i])
	{
		if (tronc[i + 1] && tronc[i] == '$')
		{
			j = write_exp(res, gvar, j);
			i += lv;
		}
		else
		{
			res[j] = tronc[i];
			i++;
			j++;
		}
	}
}

char	*check_for_var(t_data *data, char *tronc, int nb)
{
	int		i;
	char	*var;
	char	*res;

	i = -1;
	var = NULL;
	res = NULL;
	if (nb == 0 || !data->env || !tronc)
		return (tronc);
	while (tronc[++i])
	{
		if (tronc[i] == '$')
		{
			if (tronc[i + 1] == '?')
				var = ft_strdup("$?");
			else
				var = get_var(tronc);
			res = extract_var(data, tronc, var);
			free(var);
			free (tronc);
			tronc = NULL;
			return (res);
		}
	}
	return (tronc);
}
