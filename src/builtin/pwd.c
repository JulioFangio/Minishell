/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:19 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/12 17:31:16 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	make_pwd(t_env *env)
{
	char	pwd[MAX_PATH];

	(void)env;
	if (getcwd(pwd, MAX_PATH))
		return (ft_putendl_fd(pwd, STDOUT), SUCCESS);
	return (FAILURE);
}
