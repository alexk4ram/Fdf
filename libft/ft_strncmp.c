/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:26:02 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/05 19:21:22 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i <= n)
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

	// int	main(void)
	// {
	// 	const char	*s1 = "";
	// 	const char	*s2 = "";
	// 	int			n;

	// 	n = 10;
	// 	printf("the original function is %d\n", strncmp("abcdef", "abc\375xx",

	// 	printf("the built-in function is %d\n", ft_strncmp("abcdef",

	// 			5));
	// }
