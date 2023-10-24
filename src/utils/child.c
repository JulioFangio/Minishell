/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:37:48 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 17:30:39 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ret_child(char **env_tab, char *path, int result)
{
	result = child_error(path);
	free_tab(env_tab);
	return (result);
}

char	*strjoin_path(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	path = NULL;
	tmp = ft_strjoin(s1, "/");
	if (!tmp)
		return (ft_exit(ERR_MALLOC), NULL);
	path = ft_strjoin(tmp, s2);
	if (!path)
		return (ft_exit(ERR_MALLOC), NULL);
	free(tmp);
	tmp = NULL;
	return (path);
}

void	clean_child_process(t_data *data, t_env *env, char *path, char **arg)
{
	int	i;

	i = 0;
	(void)env;
	(void)arg;
	(void)data;
	if (path)
	{
		free(path);
		path = NULL;
	}
	if (arg)
	{
		while (arg[i])
			free(arg[++i]);
		free(arg);
		arg = NULL;
	}
}
