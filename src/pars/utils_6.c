/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:45:38 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:31:27 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_msg(char c)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
}

int	ft_isseparator(char c, char sep)
{
	if (c == sep || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

int	ft_countwords(const char *str, char sep, int i, int count)
{
	char	b;

	while (str[i])
	{
		if (ft_isseparator(str[i], sep))
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != sep)
			{
				if (str[i] == '"' || str[i] == '\'')
				{
					b = str[i];
					i++;
					while (str[i] != b)
						i++;
					i++;
				}
				else
					i++;
			}
		}
	}
	return (count);
}

int	skip_quotes(char *line, size_t i)
{
	char	b;

	if (line[i] == 34 || line[i] == 39)
	{
		b = line[i];
		i++;
		while (line[i] && line[i] != b)
			i++;
		return (i);
	}
	return (i);
}

int	how_long(char *line, char c, int count, size_t i)
{
	char	b;
	size_t	len;

	len = ft_strlen(line);
	while (line[i] && i < len)
	{
		if (line[i + 1] && (line[i] == '"' || line[i] == '\''))
		{
			b = line[i];
			i++;
			while (line[i] && i < len && line[i] != b)
				i++;
		}
		else if (line[i] == c && i < len
			&& ((i > 0 && line[i - 1] != 32 && line[i - 1] != c)
				|| (line[i + 1] && line[i + 1] != 32 && line[i + 1] != c)))
			count++;
		i++;
	}
	return (count);
}
