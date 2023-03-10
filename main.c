/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/10 18:27:40 by akusniak         ###   ########.fr       */
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
		ft_path(path);
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			return (1);
		ft_child_one(fd, pid1, param, path);
		pid2 = fork();
		if (pid2 < 0)
			return (1);
		ft_child_two(fd, pid2, param, path);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		ft_free_tab_char(path->clean);
		free(path);
		return (0);
	}
	else
	{
		ft_printf("Usage : .pipex file1 command1 command2 file2\n");
		return (1);
	}
}
//besoin de rajouter les tests des flags
