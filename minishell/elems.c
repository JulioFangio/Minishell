/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:18:25 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 15:18:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_cmd(t_list *cmd, char *tab)
{
    if (access(tab, F_OK | X_OK) == 0)
    {
        cmd->type = "cmd";
        cmd->elem = tab;
        return (1);
    }
    return (0);
}

int is_option(t_list *cmd, char *tab)
{
    if (tab[0] ==  '-')
    {     
        cmd->type = "option";
        cmd->elem = tab;
        return (1);
    }
    return (0);
}

int is_arg(t_list *cmd, char *tab)
{
    
}

int is_redir(t_list *cmd, char *tab)
{
    if (tab[0] ==  '>' || tab[0] == '<')
    {     
        cmd->type = "redir";
        cmd->elem = tab;
        return (1);
    }
    return (0);
}

int is_pipe(t_list *cmd, char *tab)
{
    if (tab[0] ==  '|')
    {     
        cmd->type = "pipe";
        cmd->elem = tab;
        return (1);
    }
    return (0);
}

int is_char(t_list *cmd, char *tab)
{
    if (tab[0] ==  '"')
    {     
        if (tab[ft_strlen(tab) -1] == '"')
        cmd->type = "string";
        cmd->elem = tab;
        return (1);
    }
    else if (tab[0] ==  "'")
    {     
        if (tab[ft_strlen(tab) -1] == "'")
        cmd->type = "string";
        cmd->elem = tab;
        return (1);
    }
    return (0);
}