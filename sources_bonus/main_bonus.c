/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:20:49 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/29 13:29:15 by jeannelefev      ###   ########.fr       */
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
	int	i;
	int	p[2];
	int	filein;

	i = 2;
	if (argc < 5)
	{
		ft_error("Argv error");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc(argv[2]);
	else
	{
		filein = open_fct(argv[1], 0); //
 		dup2(filein, STDIN_FILENO);
		close(filein);
	}
	while (i++ <= argc - 3)
		child_bonus(argv[i], envp, p);
	last_child(argv, argc, envp, p);
	wait(0);
	exit(EXIT_SUCCESS);
}
