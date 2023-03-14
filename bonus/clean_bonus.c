/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:24:41 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:15 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	ft_clear_path(t_pipex *pipex)
{
	ft_free_tab_char(pipex->path->clean);
	free(pipex->path);
}

void	ft_close_unused_fd(int fd, int fd_bis)
{
	close(fd);
	close(fd_bis);
}

void	ft_free_pipex(t_pipex *pipex)
{
	ft_close_pipe(pipex);
	ft_clear_path(pipex);
	free(pipex);
	pipex = NULL;
}
