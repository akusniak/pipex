/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 13:15:44 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex()
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	pipex->path = malloc(sizeof(t_path));
	if (pipex->path == NULL)
		return (NULL);
	ft_path(pipex->path);
	if (pipe(pipex->fd) == -1)
			return (NULL);
	return (pipex);
}

int	main(int ac, char **param)
{
	t_pipex	*pipex;

	if (ac < 5)
		return (ft_printf("Usage : .pipex file1 command1 command2 file2\n"), 1);
	else
	{
		int i = 3;
		pipex = ft_init_pipex();
		if (pipex == NULL)
			return (0);
		ft_open_files(pipex , param, ac);
		dup2(pipex->fd_infile, STDIN_FILENO);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		redir(param[2], pipex->path, pipex->fd_infile);
		while (i < ac - 2)
		{
			redir(param[i], pipex->path, 1);
			i++;
		}
		ft_command(param[i], pipex->path);
		//pipex->pid1 = fork();
		// if (pipex->pid1 < 0)
		// 	exit(0);
		// ft_child_one(pipex, param);
		// pipex->pid2 = fork();
		// if (pipex->pid2 < 0)
		// 	exit(0);
		// ft_child_two(pipex, param);
		// ft_free(pipex);
		// waitpid(pipex->pid1, NULL, 0);
		// waitpid(pipex->pid2, NULL, 0);
		return(0);
	}
}

void	redir (char *cmd, t_path *path, int fdin)
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
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			ft_command(cmd, path);
	}
}