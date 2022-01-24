/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:54:22 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/09 19:50:08 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	str_replace_bis(char *str, char *s, int i[5])
{
	if (i[0] != 0 && str[i[0] - 1] != ' ' && str[i[0] - 1] != str[i[0]])
	{
		i[2] = 1;
		s[i[1]++] = ' ';
		s[i[1]++] = str[i[0]];
	}
	if (str[i[0] + 1] && str[i[0] + 1] != str[i[0]] && str[i[0] + 1] != ' ')
	{
		if (!i[2])
			s[i[1]++] = str[i[0]];
		s[i[1]++] = ' ';
	}
	else if (!i[2])
	{
		s[i[1]++] = str[i[0]];
		i[2] = 0;
	}
}

static void	init_i(int i[5])
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 1;
	i[4] = 1;
}

char	*str_replace(char *str)
{
	int		i[5];
	int		len;
	char	*s;

	init_i(i);
	len = nb_inoutput(str) * 2;
	s = malloc(sizeof(char) * (ft_strlen(str) + len + 2));
	if (!s)
		return (NULL);
	while (str[i[0]])
	{
		if (str[i[0]] == '"' && (i[0] == 0 || \
			str[i[0] - 1] != '\\') && i[4] == 1)
			i[3] *= -1;
		else if (str[i[0]] == '\'' && (i[0] == 0 || \
			str[i[0] - 1] != '\\') && i[3] == 1)
			i[4] *= -1;
		if (ft_isinset(str[i[0]], "<|>") && i[3] == 1 && i[4] == 1)
			str_replace_bis(str, s, i);
		else
			s[i[1]++] = str[i[0]];
		i[0]++;
	}
	s[i[1]] = '\0';
	return (s);
}