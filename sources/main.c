/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:20:37 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/23 17:44:52 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int	p[2];
	int	pid;

	if (argc != 5)
	{
		ft_error("argv error");
		return (EXIT_FAILURE);
	}
	if (pipe(p) == -1)
		ft_error("main");
	pid = fork();
	if (pid == -1)
		ft_error("main");
	if (pid == 0)
		child(argv[1], argv[2], envp, p);
	parent(argv[4], argv[3], envp, p);
	waitpid(pid, NULL, 0);
	exit(EXIT_SUCCESS);
}
