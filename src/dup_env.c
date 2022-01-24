/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:10:27 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/07 22:57:37 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_matrixlen(char **s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i][0])
		i++;
	return (i);
}

void	ft_putmatrix_fd(char **env, int fd)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd(env[i], fd);
		ft_putchar_fd('\n', fd);
	}
}

char	**ft_extend_matrix(char **src, char *s)
{
	char 			**dst;
	unsigned int	dst_len;
	int				i;

	dst_len = ft_matrixlen(src);
	dst = (char **)malloc((dst_len + 2) * sizeof(char *));
	i = -1;
	while (src && src[++i])
		dst[i] = ft_strdup(src[i]);
	if (i == -1)
		i++;
	dst[i++] = ft_strdup(s);
	dst[i] = (char *)NULL;
	ft_free_matrix(src);
	return (dst);
}

void	ft_free_matrix(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_dup_env(char **envp)
{
	char			**n_env;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	nb_strs = ft_matrixlen(envp);
	n_env = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!n_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		next_str_len = ft_strlen(envp[i]);
		n_env[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!(n_env[i]))
		{
			ft_free_matrix(n_env);
			return (NULL);
		}
		ft_strlcpy(n_env[i], envp[i], next_str_len + 1);
		i++;
	}
	n_env[i] = NULL;
	return (n_env);
}
