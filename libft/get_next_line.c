/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:28:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/07/14 17:49:48 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEL : trouve len(line), malloc first line, buffer = line OK
RETURN : jusqu'a end(line) et malloc jusqu'a end(line) OK
READ : malloc if no result for free later, else malloc buffer.
Tant que on a pas fini de read le fd et que on ne trouve pas de '\n'
on lit. On join ce qu'on a lu puis free s1. OK
*/

#include "libft.h"

static	char	*del_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = malloc((ft_strlen_gnl(buffer) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

static	char	*return_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[0] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * (i + 1 + ft_strchr_gnl(buffer)));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static	char	*read_fd(int fd, char *reading)
{
	char	*buffer;
	char	*tmp;
	int		byte;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!ft_strchr_gnl(reading) && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buffer), NULL);
		buffer[byte] = 0;
		tmp = reading;
		if (!tmp)
		{
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		reading = ft_strjoin_gnl(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (reading);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = return_line(buffer);
	buffer = del_line(buffer);
	return (line);
}

/*
int    main(int ac, char **av)
{
    const int    fd = open(av[1], O_RDONLY);
    int            i;
    char        *str;

    (void)ac;
//    pour que printf print instantanement
//    setbuf(stdout, NULL);
    i = atoi(av[2]);
    while (i)
    {
        str = get_next_line(fd);
        if (str == NULL)
        {
            puts("(null)");
            close (fd);
            return (0);
        }
        printf("%s", str);
        free(str);
        i--;
    }
    close(fd);
    return (0);
}
*/
