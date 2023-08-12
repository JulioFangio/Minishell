/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:15:37 by juduval           #+#    #+#             */
/*   Updated: 2022/11/19 16:43:53 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		ns = ft_calloc(sizeof(char), 1);
		return (ns);
	}
	if (start + len > len_s)
		ns = ft_calloc(sizeof(char), (len_s - start) + 1);
	else
		ns = ft_calloc(sizeof(char), (len + 1));
	if (!(ns))
		return (NULL);
	while (i < len && s[start])
	{
		ns[i] = s[start];
		i++;
		start++;
	}
	return (ns);
}

// int main(void)
// {
//     const char  s[] = "tripouille";
//     unsigned int    start = 1;
//     size_t  len = 1;
// 	char	*zboub = ft_substr(s, start, len);
//     printf("%s\n", zboub);
// 	free(zboub);
//     return (0);
// }
