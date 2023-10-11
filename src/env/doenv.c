/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:45:27 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/10 16:45:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*sort_env
sort the env_tab array into place in lexicographic order
using the bubble sort algorithm
not sure about making this one*/
void	bubble_sort_env(char **env_tab, int env_len)
{
	int		is_sorted;
	int		i;
	char	*tmp;

	is_sorted = 0;
	while (env_tab && is_sorted == 0)
	{
		is_sorted = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(env_tab[i], env_tab[i + 1]) > 0)
			{
				tmp = env_tab[i];
				env_tab[i] = env_tab[i + 1];
				env_tab[i + 1] = tmp;
				is_sorted = 0;
			}
			i++;
		}
		env_len--;
	}
}

/*write_tab
browse the env environment variable array,
add "declare -x" in front of each variable,
then display the variable with its value on standard output,
one variable per line*/
void	putstr_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x", 1);
		ft_putendl_fd(env[i], 1);
		i++;
	}
}

/*show_env
combines and displays environment information 
by first converting the env linked list into a single string
then dividing it into an array of strings, sorting it
and finally displaying the environment variables exported 
from the exported linked list*/
void	display_env(t_env *env, t_env *export)
{
	char	**env_tab;
	char	*str_env;
	t_env	*tmp;

	str_env = env_malloc(env);
	env_tab = ft_split(str_env, '\n');
	if (env_tab == NULL)
		return (ft_exit(ERR_SPLIT));
	free(str_env);
	str_env = NULL;
	bubble_sort_env(env_tab, tab_size(env_tab));
	putstr_env(env_tab);
	tmp = export;
	while (tmp && tmp->value != NULL)
	{
		printf("declare -x ");
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
	free_tab(env_tab);
}

/*
copies the values of environment variables stored in a linked list
into a string, adding a line feed between each value*/
//char	*dup_env(char *ptr_env, t_env *env)
char	*dup_env(t_env *env)
{
	int		size;
	t_env	*current;
	char	*ptr_env;
	int		i;

	size = 0;
	i = 0;
	current = env;
	while (current && current->next)
	{
		if (current->value)
			size += strlen(current->value);
		if (current->next->next)
			size++;
		current = current->next;
	}
	ptr_env = ft_calloc(sizeof(char), (size + 1));
	if (!ptr_env)
		return (NULL);
	current = env;
	while (current && current->next)
	{
		if (current->value)
		{
			strcpy(ptr_env + i, current->value);
			i += strlen(current->value);
		}
		if (current->next->next)
			ptr_env[i++] = '\n';
		current = current->next;
	}
	return (ptr_env);
}

int	env_add_value_to_list(char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	if (env && env->value == NULL)
	{
		env->value = ft_strdup(value);
		return (0);
	}
	new = malloc(sizeof(t_env));
	new->value = ft_strdup(value);
	while (env && env->next && env->next->next)
		env = env->next;
	tmp = env->next;
	env->next = new;
	new->next = tmp;
	return (SUCCESS);
}
