/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:07 by rugrigor          #+#    #+#             */
/*   Updated: 2023/12/25 15:12:32 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	my_write2(t_ms *ms, char **cmd_args)
{
	ms->exit_num = 1;
	ms->kloun = 128123;
	doublefree(cmd_args);
	return (1);
}

int	my_write(char *str, int i)
{
	if (i == 0)
	{
		write(2, "minishell: ", 11);
		write(2, str, ft_strlen(str));
		write(2, ": command not found\n", 20);
	}
	else if (i == 1)
	{
		write(2, str, ft_strlen(str));
		write(2, "minishell: Bad file descriptor\n", 31);
	}
	return (-1);
}

void	cat_exit(t_ms *ms, char *str)
{
	if (ft_strcmp(str, "/bin/cat") == 0)
	{
		if (g_glob == SIGINT)
			printf("\n");
		if (g_glob == SIGQUIT)
		{
			ms->exit_num = 131;
			printf("Quit: 3\n");
		}
	}
}
