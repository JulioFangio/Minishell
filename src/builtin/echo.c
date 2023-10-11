/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/03 18:10:33 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_echo(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!ft_strncmp (line, "echo", i))
		return (FAILURE);
	return (SUCCESS);
}

/*parses the arguments passed to a command"echo" and handles the "-n"
If the "-n" option is present and followed only by linefeed characters ('\n'),
it sets a flag to indicate that the option is enabled
If the "-n" option is interrupted by another character, it resets the flags
The cur_pos parameter is used to track the position
of the argument being processed in the arg array*/
int	handle_echo_options(char **arg, int *cur_pos, int flags)
{
	int	i;

	while (arg[*cur_pos] && ft_strncmp("-n", arg[*cur_pos], 2) == 0)
	{
		i = 1;
		while (arg[*cur_pos][i])
		{
			if (arg[*cur_pos][i] && arg[*cur_pos][i] != 'n')
			{
				i = -1;
				if (*cur_pos == 1)
					flags = 0;
				break ;
			}
			flags = 1;
			i++;
		}
		if (i == -1)
			break ;
		(*cur_pos)++;
	}
	return (flags);
}

int	make_echo(char **arg)
{
	int	i;
	int	flags;

	i = 1;
	flags = 0;
	if (tab_size(arg) > 1)
	{
		flags = handle_echo_options(arg, &i, flags);
		while (arg[i])
		{
			ft_putstr_fd(arg[i], STDOUT);
			if (arg[i + 1] && arg[i][0] != '\0')
				ft_putchar_fd(' ', STDOUT);
			i++;
		}
	}
	if (flags == 0)
		ft_putchar_fd('\n', STDOUT);
	return (SUCCESS);
}
