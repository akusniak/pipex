/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:00 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 13:20:10 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(int *fd, int pid1, char **param, t_path *path)
{
	int	fd1;


	fd1 = open(param[1], O_RDONLY);
	if (fd1 == -1)
	{
		ft_close_unused_fd(fd[0], fd[1]);
		perror("First file\n");
		ft_clear_path(path);
		exit(0);
	}
	if (pid1 == 0)
	{
		dup2(fd1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_close_unused_fd(fd[0], fd1);
		if (ft_strncmp(param[2], "/", 1) == 0)
			ft_relative_path(param[2]);
		else
			ft_command(param[2], path);
		perror("First command\n");
		ft_clear_path(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_child_two(int *fd, int pid2, char **param, t_path *path)
{
	int	fd2;

	fd2 = open(param[4], O_CREAT | O_RDWR, 00700);
	if (fd2 == -1)
	{
		ft_close_unused_fd(fd[0], fd[1]);
		perror("Second file\n");
		ft_clear_path(path);
		exit(0);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		ft_close_unused_fd(fd[1], fd2);
		if (ft_strncmp(param[3], "/", 1) == 0)
			ft_relative_path(param[3]);
		else
			ft_command(param[3], path);
		perror("Second command\n");
		ft_clear_path(path);
		exit(EXIT_FAILURE);
	}
}
