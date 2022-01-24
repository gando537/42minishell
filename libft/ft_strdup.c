/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:04:59 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/06 15:40:46 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	size_t		size;
	char		*strdp;
	char		*p_strdp;

	if (!src)
		return ((char *)NULL);
	size = ft_strlen(src);
	if (!(strdp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	p_strdp = strdp;
	while (*src)
		*p_strdp++ = *src++;
	*p_strdp = '\0';
	return (strdp);
}
