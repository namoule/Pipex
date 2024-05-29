/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:31:51 by jealefev          #+#    #+#             */
/*   Updated: 2024/05/19 11:22:53 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	if ((int)(count * size) < 0)
		return (NULL);
	mem = malloc((sizeof(char)) * (count * size));
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

// int main(void)
// {
// 	printf("%p", ft_calloc(-5,0));
// 	printf("%p", calloc(-5,0));
// }