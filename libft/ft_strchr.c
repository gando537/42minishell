/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:53:02 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/06 13:56:14 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int search_char)
{
	char	find;
	int		i;

	find = (unsigned char)search_char;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == find)
		return ((char *)str + i);
	return (0);
}

int		ft_strchr_i(const char *str, int search_char)
{
	char	find;
	int		i;

	find = (unsigned char)search_char;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return (i);
		i++;
	}
	if (str[i] == find)
		return (i);
	return (-1);
}