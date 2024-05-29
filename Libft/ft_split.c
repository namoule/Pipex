/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:37:39 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/22 17:44:36 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_countword(const char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] == c)
			w++;
		i++;
	}
	w++;
	return (w);
}

char	*ft_strncpy(const char *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strncpy(s + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     if(argc == 3)
//         printf("%c \n",ft_split(argv[1], argv[2]));
//     return(0);}
