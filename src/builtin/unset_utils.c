/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:34:21 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/21 14:13:10 by jaristil         ###   ########.fr       */
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
