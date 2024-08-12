/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:59:25 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/06 15:13:15 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *dst, const void *src, size_t n)
{
	unsigned char	*newsrc;
	size_t			i;
	unsigned char	*newdst;

	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if (newsrc[i] != newdst[i])
			return (newdst[i] - newsrc[i]);
		i++;
	}
	if (newsrc == NULL || newdst == NULL)
		return (-1);
	if (i == n)
		return (0);
	return (0);
}

// int	main(void)
// {
// 	char	s1[20] = "atoms\0\0\0\0";
// 	char	s2[20] = "atoms\0abc";

// 	printf("the built in function is %i\n", ft_memcmp(s1, s2, 8));
// 	printf("the original function is %d\n", memcmp(s1, s2, 8));
// 	return (0);
// }
