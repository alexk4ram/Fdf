/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkaram <alkaram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:57:11 by alkaram           #+#    #+#             */
/*   Updated: 2024/04/23 17:29:18 by alkaram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	int_part(float n)
{
	return ((int)n);
}

float	fp(float n)
{
	if (n > 0.f)
		return (n - int_part(n));
	return (n - (int_part(n) + 1.f));
}

float	rfp(float n)
{
	return (1.f - fp(n));
}
