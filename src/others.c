/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:13:01 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/09 18:46:26 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' \
			|| c == '\f' || c == '\n' || c == '\r');
}

void	ft_matrix_replace_in(char ***envp, char **s, int ij)
{
	char 			**dst;
	unsigned int	dst_len;
	int				i;
	int				j;

	dst_len = ft_matrixlen(*envp);
	dst = (char **)malloc((dst_len + 2) * sizeof(char *));
	if (!s)
	{
		i = -1;
		j = 0;
		while (*envp && *envp[++i])
		{
			if (i != ij)
				dst[j++] = ft_strdup(*envp[i]);
			else if (s != NULL)
				dst[j++] = *s;
		}
		dst[j] = (char *)NULL;
		ft_free_matrix(*envp);
		*envp = dst;
		return ;
	}
	dst[ij] = *s;
}

int	ft_isinset(int c, char *set)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	nb_inoutput(char *str)
{
	int	i;
	int n;
	int	q[2];

	i = 0;
	n = 0;
	q[0] = 1;
	q[1] = 1;
	while (str[i])
	{
		if (str[i] == '"' && (i == 0 || str[i - 1] != '\\') && q[1] == 1)
			q[0] *= -1;
		else if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\') && q[0] == 1)
			q[1] *= -1;
		else if (ft_isinset(str[i], "<|>") && q[0] == 1 && q[1] == 1)
			n++;
		i++;
	}
	return (n);
}

