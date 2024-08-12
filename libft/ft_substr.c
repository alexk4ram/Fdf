/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:45 by alkaram           #+#    #+#             */
/*   Updated: 2024/01/02 22:20:23 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		substring = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

// int	main(void)
// {
// 	char* str;
// 	str = ft_substr("hello", 1, 1);
// 	// printf("%s\n", ft_substr("hello", 1, 1));
// 	free(str);
// }
