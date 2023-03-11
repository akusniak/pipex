/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 14:02:50 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft.h"

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define COMMAND_KO -1
# define COMMAND_OK 1

typedef struct s_path
{
	char	*envp;
	char	**clean;
}				t_path;

typedef struct s_fds
{
	int	**fd;
	int	fork_quantity;
	int	pipe_quantity;
}				t_fds;


void	ft_child_input(int *fd, int pid1, char **param, t_path *path);
void	ft_child_output(int *fd, int pid2, char **param, t_path *path);
void	ft_command(char *command, t_path *path);
void	ft_path(t_path *path);
void	ft_close_pipe(int *fd);
void	ft_clear_path(t_path *path);
void	ft_close_unused_fd(int fd, int fd_bis);
void	ft_relative_path(char *command);

#endif
