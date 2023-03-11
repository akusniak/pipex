/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:00 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 11:41:39 by akusniak         ###   ########.fr       */
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
		perror("open ");
		exit(0);
	}
	if (pid1 == 0)
	{
		dup2(fd1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_close_unused_fd(fd[0], fd1);
		ft_command(param[2], path);
		perror("command 1\n");
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
		perror("open ");
		exit(0);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		ft_close_unused_fd(fd[1], fd2);
		ft_command(param[3], path);
		perror("command 2\n");
		ft_clear_path(path);
		exit(EXIT_FAILURE);
	}
}
