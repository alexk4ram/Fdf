/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:59:52 by alkaram           #+#    #+#             */
/*   Updated: 2024/01/03 21:16:15 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len;
	size_t	start_pos;
	size_t	end_pos;

	if (!s1)
		return (NULL);
	i = 0;
	len = 0;
	end_pos = 0;
	start_pos = 0;
	while (ft_strchr(set, s1[start_pos]))
		start_pos++;
	len = ft_strlen(s1);
	if (len == 0 || start_pos == len)
		return (ft_strdup(""));
	i = len - 1;
	while (ft_strchr(set, s1[i--]))
		end_pos++;
	return (ft_substr(s1, start_pos, len - start_pos - end_pos));
}

// int	main(void)
// {
// 	char *s1 = "";
// 	char *set = "";
// 	printf("the function displays %s\n", ft_strtrim(s1, set));
// 	return (0);
// }