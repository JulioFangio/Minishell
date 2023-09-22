

#include "../../includes/minishell.h"

char	**token_to_tab(t_token *token, char **tab)
{
	int	i;

	i = 1;
	while (token && token->type < PIPE)
	{
		tab[i++] = token->str;
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**token_cmd_to_tab(t_token *token)
{
	t_token	*token_ptr;
	char	**tab;
	int		i;

	if (!token)
		return (NULL);
	token_ptr = token->next;
	i = 2;
	// while (token_ptr && token_ptr->type != PIPE)
	while (token_ptr && token_ptr->type < PIPE)
	{
		token_ptr = token_ptr->next;
		i++;
	}
	tab = malloc(sizeof(char *) * (i));
	if (tab == NULL)
		return (ft_exit(ERR_MALLOC), NULL); // do i have to return?
	token_ptr = token->next;
	tab[0] = token->str;
	tab = token_to_tab(token_ptr, tab);
	return (tab);
}
