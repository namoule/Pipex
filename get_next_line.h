/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:16:46 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/22 17:46:04 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../Libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *string, int searchedChar);

// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t elementCount, size_t elementSize);

// size_t	ft_strlen(const char *theString);

#endif
