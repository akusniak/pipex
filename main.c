/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 16:14:14 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **param)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	fd1;
	int	fd2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			return (1);
		ft_child_one(fd, pid1);
		pid2 = fork();
		if (pid2 < 0)
			return (1);
		ft_child_two(fd, pid2);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return (0);
	}
	else
	{
		ft_printf("Usage : .pipex file1 command1 command2 file2\n");
		return (1);
	}
}
// .pipex   file1    command1 command2 file2
// param[0] param[1] param[2] param[3] param[4]
