/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:42:38 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/26 16:42:41 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *nptr)
{
	long long unsigned	n;
	int					sign;
	long long unsigned	max;

	sign = 1;
	max = 9223372036854775807;
	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		if (n > max && sign == 1)
			return (-1);
		if (n > max + 1 && sign == -1)
			return (0);
		nptr++;
	}
	return (sign * n);
}
