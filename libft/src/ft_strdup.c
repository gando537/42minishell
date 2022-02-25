/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:45:20 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/26 16:45:20 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	d = (char *)malloc(size + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s1, size + 1);
	return (d);
}
