/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:16:15 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/06 15:12:28 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_memset.c"
#include "libft.h"

// including c files forbidden by norminette, replace later by libft.h

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int	main(void)
// {
// 	const char	s[] = "hola";
// 	int			i;

// 	i = 0;
// 	ft_bzero((void *)s, 4);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%i", s[i]);
// 		i++;
// 	}
// 	return (0);
// }
