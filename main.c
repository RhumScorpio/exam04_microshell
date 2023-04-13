/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:01:26 by clesaffr          #+#    #+#             */
/*   Updated: 2023/04/13 21:16:37 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	parsing_rd_line(char *rd_line, t_cmd *cmd)
{
	int	i;
	t_cmd	*tmp;
	(void)cmd;

	printf("RD/ %s\n", rd_line);
	while (rd_line[i])
	{
		if (rd_line[i] == '|')
		{
			tmp =  (t_cmd *)malloc(sizeof(t_cmd));
			cmd->next = tmp;
			cmd = cmd->next;
			i++;
		}
		if (rd_line[i] == ' ')
		{
			
		}
		i++;
	}
}

void	free_dt(char **av)
{
	while (*av)
	{
		free(*av);
		av++;
	}
	free(av);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd->next != NULL)
	{
		tmp = cmd;
		free_dt(tmp->av);
		free(tmp);
		cmd = cmd->next;
	}
	free_dt(cmd->av);
	free(cmd);
}

int	main(int ac, char *av, char **envp)
{
	int		fd;
	char	*rd_line;
	t_cmd	*cmd;

	while (1)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		rd_line = readline("microshell> ");
		if (rd_line && *rd_line)
			add_history(rd_line);
		if (rd_line == NULL)
			free_cmd(cmd);
		else
			parsing_rd_line(rd_line, cmd);
	}
	return (0);
}
