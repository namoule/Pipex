/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:20:53 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/29 13:55:13 by jeannelefev      ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (-2);
		i++;
	}
	return (0);
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

int open_fct(char *file, int i)
{
	int filein;
	filein = 0;
	if(i == 0)
		filein = open(file, O_RDONLY);
	else if(i == 1)
		filein = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if(i == 2)
		filein = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if(filein < 0)
		ft_error("open_fct");
	return(filein);
}