/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:31:37 by alkaram           #+#    #+#             */
/*   Updated: 2023/12/06 15:12:15 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

// int	main(void)
// {
// 	int	c;

// 	c = 97;
// 	ft_isalnum(c);
// }
