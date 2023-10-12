/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/12 21:47:37 by juduval          ###   ########.fr       */
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
// int	handle_echo_options(char **arg, int *cur_pos, int flags)
// {
// 	int	i;

// 	while (arg[*cur_pos] && ft_strcmp("-n", arg[*cur_pos]))
// 	{
// 		i = 1;
// 		while (arg[*cur_pos][i])
// 		{
// 			if (arg[*cur_pos][i] && arg[*cur_pos][i] != 'n')
// 			{
// 				i = -1;
// 				if (*cur_pos == 1)
// 					flags = 0;
// 				break ;
// 			}
// 			flags = 1;
// 			i++;
// 		}
// 		if (i == -1)
// 			break ;
// 		(*cur_pos)++;
// 	}
// 	return (flags);
// }

int	handle_echo_options(char **arg)
{
	if (!ft_strcmp("-n", arg[1]))
		return (1);
	return (0);
}

int	make_echo(char **arg)
{
	int	i;
	int	flags;

	i = 1;
	flags = handle_echo_options(arg);
	printf("flag = %d\n", flags);
	if (tab_size(arg) > 1)
	{
		while (arg[i])
		{
			if (i == 1 && !ft_strcmp("-n", arg[1]))
				i++;
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
