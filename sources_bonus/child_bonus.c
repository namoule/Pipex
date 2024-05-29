/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:03:35 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/29 13:59:54 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_bonus(char *cmd, char **envp, int *p)
{
	pid_t	pid;

	if (pipe(p) == -1)
		ft_error("child_process");
	pid = fork();
	if (pid == -1)
		ft_error("child_process");
	if (pid == 0)
	{
		close(p[READ_END]);
		dup2(p[WRITE_END], STDOUT_FILENO);
		execute(cmd, envp);
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[READ_END], STDIN_FILENO);
	}
}

void	last_child(char **argv, int argc, char **envp, int *p)
{
	int	fileout;
	if(ft_strcmp(argv[1], "here_doc") == 0)
		fileout = open_fct(argv[argc - 1], 2);
	else
		fileout = open_fct(argv[argc -1], 1);
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	close(fileout);
	execute(argv[argc -2], envp);
}
