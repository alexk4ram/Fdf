/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:45:28 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/04 21:59:07 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' || *s == (char)c)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*s = "Hello World";
// 	int			c;

// 	c = 'H';
// 	ft_strchr(s, c);
// }
