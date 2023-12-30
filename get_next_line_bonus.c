/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:18:53 by dgomez-m          #+#    #+#             */
/*   Updated: 2023/12/30 04:50:44 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}

char	*read_line(int fd, char *buf)
{
	char	*line;
	int		countread;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')))
	{
		countread = read(fd, buf, BUFFER_SIZE);
		if (countread == -1)
		{
			free(line);
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (NULL);
		}
		if (countread == 0)
			break ;
		buf[countread] = '\0';
		line = ft_strjoin(line, buf, countread);
	}
	return (line);
}

void	prepare_buffer(char *buf, char *line, char *newline)
{
	int	to_copy;

	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buf[fd]);
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	prepare_buffer(buf[fd], line, newline);
	return (line);
}
