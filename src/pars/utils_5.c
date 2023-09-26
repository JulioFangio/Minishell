/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:54:50 by juduval           #+#    #+#             */
/*   Updated: 2023/09/26 16:01:11 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_var(char *tronc)
{
	int		i;
	int		b;
	char	*var;

	i = 0;
	b = 0;
	while (tronc[i])
	{
		if (tronc[i] == 32 || (tronc[i] >= 9 && tronc[i] <= 13))
			break ;
		i++;
	}
	b = i;
	var = ft_calloc((i + 1), sizeof(char));
	i = -1;
	while (++i < b)
		var[i] = tronc[i];
	return (var);
}

char	*extract_var(char *tronc, char *var)
{
	int		lv;
	int		lg;
	int		lr;
	char	*res;
	char	*gvar;

	gvar = pick_env(var);
	lv = ft_strlen(var);
	lg = ft_strlen(gvar);
	lr = lg - lv;
	res = ft_calloc(ft_strlen(tronc) + lr + 1, sizeof(char));
	res = get_new_line(res, tronc, gvar, lv);
	free (gvar);
	free (tronc);
	return (res);
}

char	*get_new_line(char *res, char *tronc, char *gvar, int lv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (tronc[i])
	{
		if (tronc[i] == '$')
		{
			while (gvar[k])
			{
				res[j] = gvar[k];
				k++;
				j++;
			}
			i += lv;
		}
		res[j] = tronc[i];
		i++;
		j++;
	}
	return (res);
}

char	*check_for_var(char *tronc, int nb)
{
	int		i;
	char	*var;
	char	*res;

	i = -1;
	var = NULL;
	res = NULL;
	if (nb == 0)
		return (tronc);
	while (tronc[++i])
	{
		if (tronc[i] == '$')
		{
			var = get_var(tronc + i);
			res = extract_var(tronc, var);
			return (res);
		}
	}
	return (tronc);
}
