/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 11:23:53 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex()
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	pipex->path = ft_path();
	if (pipex->path == NULL)
	{
		free(pipex);
		return (NULL);
	}
	if (pipe(pipex->fd) == -1)
	{
		ft_clear_path(pipex);
		free(pipex);
		return (NULL);
	}
	return (pipex);
}

int	main(int ac, char **param)
{
	t_pipex	*pipex;

	if (ac < 5 || ac > 5)
		return (ft_printf("Usage : .pipex file1 command1 command2 file2\n"), 1);
	else
	{
		pipex = ft_init_pipex();
		if (pipex == NULL)
			return (0);
		ft_open_files(pipex , param);
		pipex->pid1 = fork();
		if (pipex->pid1 < 0)
			exit(0);
		if (pipex->pid1 == 0)
			ft_child_one(pipex, param);
		pipex->pid2 = fork();
		if (pipex->pid2 < 0)
			exit(0);
		if (pipex->pid2 == 0)
			ft_child_two(pipex, param);
		waitpid(-1, NULL, 0);
		ft_free_pipex(pipex);
	}
}
