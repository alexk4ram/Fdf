/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:01:06 by alkaram           #+#    #+#             */
/*   Updated: 2023/11/30 11:45:48 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*newdst;
	char	*newsrc;

	newdst = (char *)dst;
	newsrc = (char *)src;
	if (!newdst && !newsrc)
		return (newdst);
	if (len == 0)
		return (dst);
	if (newsrc < newdst && newsrc + len > newdst)
	{
		newsrc += len - 1;
		newdst += len - 1;
		while (len--)
			*newdst-- = *newsrc--;
	}
	else
	{
		while (len--)
			*newdst++ = *newsrc++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[20] = "hello";
// 	char dst[20] = "world";

// 	char	a[20] = "hello";
// 	char	b[20] = "world";
// 	memmove(a, b, 3);
// 	printf("%s", a);
// 	return (0);
// 	memmove(dst, src, 1);
// 	printf("%s", dst);
// 	return (0);
// }
