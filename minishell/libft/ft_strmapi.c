/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:57:44 by juduval           #+#    #+#             */
/*   Updated: 2022/11/11 16:27:34 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ns;

	i = 0;
	ns = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(ns))
		return (NULL);
	while (s[i])
	{
		ns[i] = (*f)(i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

/*
int	main(void)
{
	char	s[] = "Jules";
	char	(*f)(unsigned int, char) = &ft_putstr_fd;
	printf("%s\n", ft_strmapi(s, ft_putstr_fd(1, s));
	return (0);
}*/
