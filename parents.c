/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:55:44 by jeannelefev       #+#    #+#             */
/*   Updated: 2024/02/27 16:55:45 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *p)
{
	int	filein;

	filein = gestion(argv[1], 2);
	dup2(p[WRITE_END], STDOUT_FILENO); 
	close(p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(p[READ_END]);
	close(filein);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *p)
{
	int	fileout;

	fileout = gestion(argv[4], 1);
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	close(fileout);
	execute(argv[3], envp);
}