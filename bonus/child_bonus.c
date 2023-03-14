/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:00 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 14:03:50 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	ft_child_input(t_pipex *pipex, char **param)
// {
// 	if (pipex->infile == 0)
// 	{
// 		dup2(pipex->infile, STDIN_FILENO);
// 		dup2(pipex->fd[1], STDOUT_FILENO);
// 		ft_close_unused_fd(pipex->fd[0], pipex->infile);
// 		if (ft_strncmp(param[2], "/", 1) == 0)
// 			ft_relative_path(param[2]);
// 		else
// 			ft_command(param[2], pipex->path);
// 		ft_free_pipex(pipex);
// 		exit(EXIT_FAILURE);	}
// 	else
// 		return ;
// }

// void	ft_mid_childs(t_pipex *pipex, char **param, int ac)
// {
// 	int	i;

// 	i = 4;
// 	while (i <= ac - 2)
// 	{
// 		redir(param[i], pipex);
// 		i = i + 1;
// 	}
// }

// void	ft_child_output(t_pipex *pipex, char **param)
// {
// 	if (pipex->outfile == 0)
// 	{
// 		dup2(pipex->fd[0], STDIN_FILENO);
// 		dup2(pipex->outfile, STDOUT_FILENO);
// 		ft_close_unused_fd(pipex->fd[1], pipex->outfile);
// 		if (ft_strncmp(param[3], "/", 1) == 0)
// 			ft_relative_path(param[3]);
// 		else
// 			ft_command(param[3], pipex->path);
// 		ft_free_pipex(pipex);
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 		return ;
// }

void	ft_pipe(char *cmd, t_pipex *pipex, int file)
{
	int	pid;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (file == STDIN_FILENO)
			exit(1);
		else
			ft_command(cmd, pipex->path);
	}
}

/****************************************************/
void	ft_child_input(t_pipex *pipex, char **param)
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
		ft_free_pipex(pipex);
		exit(EXIT_FAILURE);	}
	else
		return ;
}

void	ft_child_output(t_pipex *pipex, char **param)
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
		ft_free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}



/*

./pipex file1 cmd1 cmd2 cmd3 cmd4 file2

ac = 7
3 pipe necessaire
4 forks necessaires

*/


