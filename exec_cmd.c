/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:00:49 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/07 13:39:46 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		execute(char *path, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
		ft_putendl("\033[31mfork failed\033[0m");
	wait(&pid);
	return (1);
}

static void		print_error(char *str)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(str);
}

static int		exec_path_bin(char **args, char **paths)
{
	int			i;
	char		*temp;
	char		*temp1;

	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		temp1 = ft_strjoin(temp, args[0]);
		free(temp);
		if (access(temp1, X_OK) == 0)
		{
			execute(temp1, args);
			free(temp1);
			return (1);
		}
		free(temp1);
	}
	return (0);
}

int				exec_bin(char **args)
{
	int			ret;
	char		**paths;

	ret = 0;
	if (access(args[0], X_OK) == 0)
	{
		execute(args[0], args);
		return (1);
	}
	paths = ft_strsplit(find_envv("PATH"), ':');
	if (!paths || paths[0] == NULL)
		print_error(args[0]);
	else
	{
		ret = exec_path_bin(args, paths);
		if (ret == 0)
			print_error(args[0]);
	}
	ft_free_array(paths);
	return (1);
}
