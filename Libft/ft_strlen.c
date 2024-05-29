/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:33:39 by jeannelefev       #+#    #+#             */
/*   Updated: 2024/05/19 11:24:24 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
	}
	return (i - 1);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int ac, char **av) {
// 	printf("%d", ft_strlen(strdup("")));
// }
