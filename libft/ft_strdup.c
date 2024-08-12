/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:43:58 by alkaram           #+#    #+#             */
/*   Updated: 2024/01/03 15:04:53 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	char	*p;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "";
// 	printf("the original function displays %p\n", strdup(str));
// 	printf("the built in function displays %p\n", ft_strdup(str));
// 	return (0);
// }
