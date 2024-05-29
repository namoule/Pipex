/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:20:40 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/23 17:37:55 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	child(char *infile, char *cmd, char **envp, int *p)
{
	int	filein;

	filein = open(infile, O_RDONLY, 0777);
	dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(p[READ_END]);
	execute(cmd, envp);
}

void	parent(char *outfile, char *cmd, char **envp, int *p)
{
	int	fileout;

	fileout = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	close(fileout);
	execute(cmd, envp);
}

void	execute(char *cmd, char **envp)
{
	char	**commande;
	char	*pathoche;

	commande = ft_split(cmd, ' ');
	if (!commande)
		ft_error("execute");
	pathoche = path(commande[0], envp);
	if (!pathoche)
	{
		freetab(commande);
		ft_error("execute");
	}
	if (execve(pathoche, commande, envp) == -1)
	{
		free(pathoche);
		freetab(commande);
		ft_error("cmd error");
	}
}

char	*path(char *cmd, char **envp)
{
	char	**total_path;
	char	*join_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	total_path = ft_split(envp[i] + 5, ':');
	if (!total_path)
		ft_error("path");
	i = -1;
	while (total_path[++i])
	{
		join_path = ft_strjoin(total_path[i], "/");
		if (!join_path)
			(freetab(total_path), ft_error("path"));
		path = ft_strjoin(join_path, cmd);
		if (free(join_path), !path)
			(freetab(total_path), ft_error("path"));
		if (access(path, F_OK) == 0)
			return (freetab(total_path), path);
		free(path);
	}
	return (freetab(total_path), NULL);
}
