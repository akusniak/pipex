/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:24:41 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 11:36:46 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	ft_clear_path(t_path *path)
{
	ft_free_tab_char(path->clean);
	free(path);
}

void	ft_close_unused_fd(int fd, int fd_bis)
{
	close(fd);
	close(fd_bis);
}
