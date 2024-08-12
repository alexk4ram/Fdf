/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:22:04 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/06 15:12:23 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_bzero.c"
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(ptr, total);
	}
	return (ptr);
}

// int	main(void)
// {
// 	size_t	a;
// 	size_t	b;
// 	char	*ptr1;
// 	char	*ptr2;

// 	a = 3;
// 	b = 4;
// 	ptr2 = ft_calloc(a, b);
// 	ptr1 = calloc(a, b);
// 	printf("the built in function displays %p\n", (void *)ft_calloc(a, b));
// 	printf("the original function displays %p\n", (void *)calloc(a, b));
// 	return (0);
// }
