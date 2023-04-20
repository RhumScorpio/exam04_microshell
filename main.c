/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:01:26 by clesaffr          #+#    #+#             */
/*   Updated: 2023/04/20 20:03:50 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char **envp)
{
	int		i = 0;
	int		exec_start = 1;
	int		exec_end = 1;
	int		fd;

	if (ac <= 1)
		return (0);
	while (i++ < (ac - 1))
	{
		printf("%d/ %s\n", i, av[i]);
		if (*av[i] == '|' || *av[i] == ';')
		{
			printf("Start == %d\n", exec_start);
			if (av[i + 1])
				exec_start = i + 1;
			exec_end = i - 1;
			printf("END == %d\n", exec_end);
		}
	}
	exec_end = i - 1;
	printf("Start == %d\n", exec_start);
	printf("END == %d\n", exec_end);
	return (0);
}
