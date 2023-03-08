/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:00 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 16:31:14 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(int *fd, int pid1)
{
	int	fd1;

	fd1 = open("axel.txt", O_RDONLY);
	if (fd1 == -1)
	{
		close (fd[0]);
		close (fd[1]);
		perror("open ");
		exit(0);
	}
	if (pid1 == 0)
	{
		dup2(fd1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd1);
		execlp("cat", "cat", NULL);
	}
	else
		return ;
}

void	ft_child_two(int *fd, int pid2)
{
	int	fd2;

	fd2 = open("result.txt", O_CREAT | O_RDWR, 00700);
	if (fd2 == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("open ");
		exit(0);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		close(fd[1]);
		close(fd2);
		execlp("wc", "wc", NULL);
	}
	else
		return ;
}
