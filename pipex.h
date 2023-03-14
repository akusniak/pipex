/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 12:21:56 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

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

typedef struct s_pipex
{
	t_path	*path;
	int		fd[2];
	int		pid1;
	int		pid2;
	int		fd_infile;
	int		fd_outfile;
}				t_pipex;


void	ft_child_one(t_pipex *pipex, char **param);
void	ft_child_two(t_pipex *pipex, char **param);
void	ft_command(char *command, t_path *path);
t_path	*ft_path();
void	ft_close_pipe(t_pipex *pipex);
void	ft_clear_path(t_pipex *pipex);
void	ft_close_unused_fd(int fd, int fd_bis);
void	ft_relative_path(char *command);
t_pipex	*ft_init_pipex();
void	ft_open_files(t_pipex *pipex, char **param);
void	ft_free_pipex(t_pipex *pipex);
int		ft_is_empty(char *command);

#endif
