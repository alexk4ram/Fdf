/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:02:43 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/22 17:44:12 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(int nb)
{
	int				result;
	unsigned int	unsigned_nb;

	result = 1;
	if (nb < 0)
		unsigned_nb = -nb;
	else
		unsigned_nb = nb;
	while (unsigned_nb >= 10)
	{
		result++;
		unsigned_nb = unsigned_nb / 10;
	}
	return (result);
}

char	*handle_sign(int n)
{
	char	*sign;

	if (n < 0)
		sign = "-";
	else
		sign = "";
	return (sign);
}

char	*newstring(size_t size)
{
	char	*result;

	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, sizeof(char) * (size + 1));
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	char	*sign;

	if (n == FT_INT_MIN)
		return (result = ft_strdup("-2147483648"));
	sign = handle_sign(n);
	len = digits(n);
	result = newstring(len + ft_strlen(sign));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, sign, len + ft_strlen(sign) + 1);
	if (n < 0)
		n = -n;
	else if (n == 0)
		result[ft_strlen(sign)] = '0';
	while (n)
	{
		result[ft_strlen(sign) + len - 1] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	return (result);
}

// int	main(void)
// {
// 	char	*s;

// 	s = ft_itoa(2147483647);
// 	printf("the funtion displays %s\n", s);
// 	free(s);
// 	return (0);
// }
