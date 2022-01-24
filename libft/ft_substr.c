/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:27:27 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/06 17:04:22 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char	*p_s;
	char		*new_str;
	char		*p_new_str;

	if (s == NULL)
		return (NULL);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	p_s = &s[start];
	p_new_str = new_str;
	if (start < ft_strlen(s))
	{
		while (*p_s && len--)
		{
			*p_new_str = *p_s;
			p_new_str++;
			p_s++;
		}
		*p_new_str = '\0';
	}
	return (new_str);
}
