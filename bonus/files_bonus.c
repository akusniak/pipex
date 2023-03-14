/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:05:06 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 13:50:08 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_open_files(t_pipex *pipex, char **param, int ac)
{
	pipex->infile = open(param[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		ft_close_unused_fd(pipex->fd[0], pipex->fd[1]);
		perror("First file\n");
		ft_clear_path(pipex);
		free(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->outfile = open(param[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		ft_close_unused_fd(pipex->fd[0], pipex->fd[1]);
		perror("Second file\n");
		ft_clear_path(pipex);
		close(pipex->infile);
		free(pipex);
		exit(EXIT_FAILURE);
	}
}
