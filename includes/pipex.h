/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:46:55 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/29 13:26:00 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

void	child(char *infile, char *cmd, char **envp, int *p);
void	parent(char *outfile, char *cmd, char **envp, int *p);
void	ft_error(char *str);

char	*path(char *cmp, char **envp);
void	execute(char *cmd, char **envp);

void	here_doc(char *limiter);
void	first_child(char *infile, char *cmd, char **envp, int *p);
void	child_bonus(char *cmd, char **envp, int *p);
void	last_child(char **argv, int status, char **envp, int *p);
int     open_fct(char *file, int i);
int		ft_strcmp(char *s1, char *s2);
#endif
