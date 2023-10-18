/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:34:21 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/14 22:51:48 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_to_equal(char *env)
{
	int	i;

	i = 0;
	while (env && env[i] != '=')
		i++;
	return (i);
}

/*finds the first occurrence of the '=' character in the str string
and returns a new string containing the portion
of str up to this '=' character*/
char	*ft_strchr_minishell(const char *str, char c)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[len] && str[len] != '=')
		len++;
	if (len == ft_strlen(str))
		return (NULL);
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (ft_exit(ERR_MALLOC), NULL);
	while (i++ < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

int	comp_len_val(char *arg, char *value)
{
	char	*cmp;

	cmp = ft_strchr_minishell(arg, '=');
	if (cmp == NULL)
		cmp = arg;
	if (ft_strlen(cmp) == ft_strlen(value))
		return (0);
	else
		return (1);
}

void	free_export(t_data *data, t_env *export)
{
	if (data->export == export && export->next == NULL)
	{
		ft_memdel(data->export->value);
		data->export->value = NULL;
		data->export->next = NULL;
		return ;
	}
	ft_memdel(export->value);
	ft_memdel(export);
}

/*delete an exported environment variable by browsing the list,
adjusting pointers, and handling the case where the variable to be deleted
is the first in the list*/
int	remove_export(t_data *data, char **arg, int i)
{
	t_env	*export;
	t_env	*prev_export;

	 // Pointeur vers la première variable d'environnement exportée
	export = data->export;
	// Pointeur vers la variable précédente dans la liste
	prev_export = NULL;
	while (export)
	{
		if (comp_len_val(arg[i], export->value) == 0
			&& !ft_strncmp(arg[i], export->value, ft_strlen(arg[i])))
		{
			// Si la variable à supprimer n'est pas la première dans la liste
			if (prev_export)
				prev_export->next = export->next;
			else
				data->export = export->next;
			free_export(data, export);
			return (SUCCESS);
		}
		prev_export = export;
		export = export->next;
	}
	return (FAILURE);
}
