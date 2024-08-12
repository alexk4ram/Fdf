/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:17:54 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/19 18:52:49 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper2(unsigned int i, char c)
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

char	*newstring2(size_t size)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*result;

	if (s == NULL)
		return (NULL);
	str = newstring2(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}

// int	main(void)
// {
// 	printf("the function displays %s\n", ft_strmapi("hello", ft_toupper2));
// }
