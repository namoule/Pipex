/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:55:40 by jeannelefev       #+#    #+#             */
/*   Updated: 2024/02/27 16:55:41 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	p[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(p) == -1)
			erreurs();
		pid = fork();
		if (pid == -1)
			erreurs();
		if (pid == 0)
			child_process(argv, envp, p);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, p);
	}
	else
		erreurs();
	return (0);
}
