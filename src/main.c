/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:12:52 by mdiallo           #+#    #+#             */
/*   Updated: 2022/01/24 18:40:22 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*clear_sc(void)
{
	const char	*clear;

	clear = "\e[1;1H\e[2J";
	write(1, clear, 11);
	return ((char *) NULL);
}

static pid_t	mini_getpid(t_prompt *prompt)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		mini_perror(prompt, FORKERR, NULL, 1);
		return (-1);
	}
	if (!pid)
		exit(1);
	waitpid(pid, NULL, 0);
	return (pid - 1);
}

static t_prompt	init_vars(t_prompt prompt, char *str, char **argv, char **envp)
{
	char	*num;

	str = getcwd(NULL, 0);
	prompt.envp = mini_setenv("PWD", str, prompt.envp, 3);
	free(str);
	str = mini_getenv("SHLVL", envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = mini_setenv("SHLVL", num, prompt.envp, 5);
	free(num);
	str = mini_getenv("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = mini_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
	free(str);
	str = mini_getenv("_", prompt.envp, 1);
	if (!str)
		prompt.envp = mini_setenv("_", argv[0], prompt.envp, 1);
	free(str);
	return (prompt);
}

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.envp = ft_dup_env(envp);
	prompt.e_status = 0;
	prompt.pid = mini_getpid(&prompt);
	prompt = init_vars(prompt, str, argv, envp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	char				*str;
	char				*out;
	t_prompt			prompt;

	clear_sc();
	prompt = init_prompt(argv, envp);
	while (argv && argc)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		str = mini_getprompt(prompt);
		if (str)
			out = mini_readline(&prompt, str);
		else
			out = mini_readline(&prompt, "guest@minishell $ ");
		free(str);
		if (!check_args(out, &prompt))
			break ;
	}
	ft_free_matrix(prompt.envp);
	exit(prompt.e_status);
}
