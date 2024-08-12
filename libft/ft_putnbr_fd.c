/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:54:30 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/20 18:07:33 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_number(int p, int fd)
{
	p += 48;
	write(fd, &p, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		write_number(n % 10, fd);
	}
	else
		write_number(n, fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// }