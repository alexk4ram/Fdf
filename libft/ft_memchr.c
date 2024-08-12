/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:00:05 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/05 20:03:54 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*news;
	size_t	i;

	news = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)news[i] == (unsigned char)c)
		{
			return ((void *)(news + i));
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[20] = "hello";
// 	char	a;
// 	int		n;

// 	a = 'o';
// 	n = 5;
// 	printf("the built in function displays %s\n", (ft_memchr(str, a, n)));
// 	printf("the original function displays %s\n", (memchr(str, a, 5)));
// 	return (0);
// }
