/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:38:43 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/07 17:56:11 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_strlen.c"
// #include "ft_strncmp.c"
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (haystack == NULL && needle == NULL)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (!ft_strlen(haystack) && !ft_strlen(needle))
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// printf("the built in function displays %s\n", ft_strnstr("fake",
// 	// 		((void *)0), 3));
// 	// printf("the original function displays %s\n", strnstr("fake",
// 	// ((void *)0),
// 	// 		3));
// 	printf("the built in function displays %s\n", ft_strnstr("", "", 3));
// 	printf("the original function displays %s\n", strnstr("", "", 3));
// 	printf("the built in function displays %s\n", ft_strnstr("", "something",
// 			3));
// 	printf("the original function displays %s\n", strnstr("", "something", 3));
// 	printf("the built in function displays %s\n", ft_strnstr("something", "",
// 			3));
// 	printf("the original function displays %s\n", strnstr("something", "", 3));
// 	return (0);
// }
