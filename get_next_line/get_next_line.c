/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:16:36 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/22 17:45:55 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buf)
{
	char	*buffer;
	int		byte_read;

	if (!buf)
	{
		buf = ft_calloc(1, 1);
		if (!buf)
			return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buf), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(buf), NULL);
		buffer[byte_read] = 0;
		buf = ft_free(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1)
		return (free(buffer), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	// int		fd;
	char	*line;
	int		nb;

	nb = 0;
	(void)argc;
	if (argc != 2)
		return (1);
	(void) argv;
	// fd = open(argv[1], O_RDONLY);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		printf("[%d] : %s", nb, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
		nb++;
	}
	printf("[%d] : %s", nb, line);
	// close(fd);
} */
