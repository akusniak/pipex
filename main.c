/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 11:42:21 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **param)
{
	t_path	*path;
	int		fd[2];
	int		pid1;
	int		pid2;

	if (ac == 5)
	{
		path = malloc(sizeof(t_path));
		if (path == NULL)
			return (0);
		pid1 = fork();
		if (pid1 < 0)
			exit(0);
		pid2 = fork();
		if (pid2 < 0)
			exit(0);
		ft_path(path);
		if (pipe(fd) == -1)
			return (1);
		ft_child_one(fd, pid1, param, path);
		ft_child_two(fd, pid2, param, path);
		ft_close_pipe(fd);
		ft_clear_path(path);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return (0);
	}
	ft_printf("Usage : .pipex file1 command1 command2 file2\n");
	return (1);
}
