/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:01:25 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/08 18:06:09 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_characters(int c)
{
	return ((c == '\t') || (c == '\v') || (c == '\n') || (c == '\r')
		|| (c == '\f') || (c == ' '));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_characters(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (result * sign);
}

// int	main(void)
// {
// 	char	str[20] = "+-123";

// 	printf("the original function displays %d\n", atoi(str));
// 	printf("the built in function displays %d\n", ft_atoi(str));
// 	return (0);
// }
