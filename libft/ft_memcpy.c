/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:58:24 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/02 16:09:15 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s = (const char *)src;

	i = 0;
	d = (char *)dst;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst[20] = "hello";
// 	char	src[20] = "world";

// 	ft_memcpy(dst, src, 5);
// 	printf("%s", dst);
// char	c[20] = "hello";
// char	d[20] = "world";
// memcpy(c, d, 1);
// printf("%s", c);
// return (0);
// }
