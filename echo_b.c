/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:41:02 by mndlovu           #+#    #+#             */
/*   Updated: 2017/09/07 12:50:52 by mndlovu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo_path(char *var)
{
	char *path;

	path = find_envv(var + 1);
	ft_putstr(path);
}

static void		echo_string(char *str)
{
	int len;
	int start;
	int end;

	len = (int)ft_strlen(str);
	start = 0;
	end = len - 1;
	if (str[0] == '$')
		echo_path(str);
	else
	{
		while (str[start] == '\'' || str[start] == '"')
			start++;
		while (str[end] == '\'' || str[end] == '"')
			end--;
		while (start <= end)
			write(1, &str[start++], 1);
	}
}

int				my_echo(char **args)
{
	int i;

	i = 0;
	if (!args[0])
	{
		ft_putchar('\n');
		return (1);
	}
	while (args[i])
	{
		echo_string(args[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
