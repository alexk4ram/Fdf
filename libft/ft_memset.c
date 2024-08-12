/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:50:07 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/06 13:23:48 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < len)
	{
		*(str + i) = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[50] = "hello this is me";

// 	printf("the built in function displays %s\n", ft_memset(((void *)0), 'a',
// 			12));
// 	printf("the original function displays %s\n", memset(((void *)0), 'a', 12));
// }
