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

void	ft_child_one(t_pipex *pipex, char **param)
{
	if (pipex->pid1 == 0)
	{
		dup2(pipex->fd_infile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		ft_close_unused_fd(pipex->fd[0], pipex->fd_infile);
		if (ft_strncmp(param[2], "/", 1) == 0)
			ft_relative_path(param[2]);
		else
			ft_command(param[2], pipex->path);
		perror("First command\n");
		ft_clear_path(pipex->path);
		free(pipex);
		exit(EXIT_FAILURE);
	}
}

void	ft_child_two(t_pipex *pipex, char **param)
{
	if (pipex->pid2 == 0)
	{
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		ft_close_unused_fd(pipex->fd[1], pipex->fd_outfile);
		if (ft_strncmp(param[3], "/", 1) == 0)
			ft_relative_path(param[3]);
		else
			ft_command(param[3], pipex->path);
		perror("Second command\n");
		ft_clear_path(pipex->path);
		free(pipex);
		exit(EXIT_FAILURE);
	}
}