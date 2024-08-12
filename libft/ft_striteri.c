/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:00:19 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/19 19:09:18 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper3(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (*s)
			f(i++, s++);
	}
}

// int	main(void)
// {
// 	printf("the function displays %s\n", "hello");
// }