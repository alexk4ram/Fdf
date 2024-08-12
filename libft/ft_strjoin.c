/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:58:07 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/12 03:04:10 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	newstring = malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (s1[i])
		newstring[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstring[j++] = s2[i++];
	newstring[j] = '\0';
	return (newstring);
}

// int	main(void)
// {
// 	printf("the function displays %s\n", ft_strjoin("", ""));
// }