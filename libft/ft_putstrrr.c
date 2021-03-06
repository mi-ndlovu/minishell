
#include "libft.h"

void	ft_open(void)
{
	ft_p("\033[34m0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0\033[0m");
	ft_putstr("\033[34m|\033[0m");
	ft_putstr("\033[32m                   Welcome to Minishell                    \033[0m");
	ft_p("\033[34m|\033[0m");
	ft_p("\033[34m|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\033[0m");
	ft_p("\033[32m|          ::::::   :::  :+:  ::::::   :::     :::  ™       |\033[0m");
	ft_p("\033[32m|         :+:       :+:  :+:  :+:      :+:     :+:          |\033[0m");
	ft_p("\033[32m|          ::::::   :+::::+:  :+::::   :+:     :+:          |\033[0m");
	ft_p("\033[32m|              :+:  :+:  :+:  :+:      :+:     :+:          |\033[0m");
	ft_p("\033[32m|          ::::+:   :+:  :+:  ::::::   ::::::  :::::::      |\033[0m");
	ft_p("\033[34m0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0\033[0m");
	ft_putstr("\033[34m|\033[0m");
	ft_putstr("\033[32m                   Designed by mndlovu®             ©2017  \033[0m");
	ft_p("\033[34m|\033[0m");
	ft_p("\033[34m0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0\033[0m");
}

void	ft_close(void)
{
	ft_p("\033[34m0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0\033[0m");
	ft_putstr("\033[34m|\033[0m");
	ft_putstr("\033[32m            Minishell has been closed successfully         \033[0m");
	ft_p("\033[34m|\033[34m");
	ft_p("\033[34m0~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~0\033[0m");
}

void	ft_p(char const *s)
{
	unsigned int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}