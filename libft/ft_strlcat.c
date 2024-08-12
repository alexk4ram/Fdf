/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:04:56 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/21 12:44:35 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s = src;
	size_t		n;
	size_t		dstlen;

	n = size;
	d = dst;
	while (n-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	n = size - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}

// int	main(void)
// {
// 	int		size;
// 	char	dst[20] = "hello";
// 	char	src[20] = "world";

// 	size = strlcat(dst, src, 3);
// 	printf("the original function displays %d\n", size);
// 	size = ft_strlcat(dst, src, 3);
// 	printf("the built in function displays %d\n", size);
// 	return (0);
// }
