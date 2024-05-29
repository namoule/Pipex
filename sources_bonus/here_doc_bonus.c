/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:20:43 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/29 13:25:52 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	put_line(char *limiter, int *p)
{
	char	*line;
	int		val;

	limiter = ft_strjoin(limiter, "\n");
	if (!(limiter))
		return (0);
	while (1)
	{
		line = get_next_line(0);
		val = ft_strcmp(line, limiter);
		if (val == 0)
		{
			free(line);
			get_next_line(-1);
			free(limiter);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, p[1]);
		free(line);
	}
	return (EXIT_SUCCESS);
}

void here_doc(char *limiter)
{
	int		p[2];
	pid_t	pid;

	if (pipe(p) == -1)
		ft_error("here_doc");
	pid = fork();
	if (pid == -1)
		ft_error("here_doc");
	if (!pid)
	{
		if (!put_line(limiter, p))
		{
			close(p[1]);
			dup2(p[0], 0);
			wait(NULL);
		}
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		wait(NULL);
	}
}
