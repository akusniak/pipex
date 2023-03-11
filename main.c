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

void	ft_path(t_path *path)
{
	path->envp = "/mnt/nfs/homes/akusniak/bin/:/mnt/nfs/homes/akusniak/bin/:/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/";
	path->clean = ft_split(path->envp, ':');
}

void	ft_command(char *command, t_path *path)
{
	int		i;
	char	*cmd;
	char	**command_w_options;

	i = 0;
	cmd = NULL;
	command_w_options = ft_split(command, 32);
	if (command_w_options == NULL)
		return ;
	while (path->clean[i])
	{
		cmd = ft_strjoin(path->clean[i], command_w_options[0]);
		if (access(cmd, F_OK) == 0)
			execve(cmd, command_w_options, &path->clean[i]);
		free(cmd);
		i = i + 1;
	}
	ft_free_tab_char(command_w_options);
}

void	ft_relative_path(char *command)
{
	char	**command_no_options;
	char	**cmd_isolation;
	int		i;

	i = 0;
	command_no_options = ft_split(command, 32);
	if (command_no_options == NULL)
		return ;
	cmd_isolation = ft_split(command_no_options[0], '/');
	if (cmd_isolation == NULL)
	{
		ft_free_tab_char(command_no_options);
		return ;
	}
	while (cmd_isolation[i])
		i++;
	if (access(command_no_options[0], F_OK) == 0)
		execve(cmd_isolation[i - 1], command_no_options, &command_no_options[0]);
	ft_free_tab_char(command_no_options);
	ft_free_tab_char(cmd_isolation);
}

int	main(int ac, char **param)
{
	t_path	*path;
	int		fd[2];
	int		pid1;
	int		pid2;

	if (ac == 5)
	{
		path = malloc(sizeof(t_path));
		if (path == NULL)
			return (0);
		ft_path(path);
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			exit(0);
		ft_child_one(fd, pid1, param, path);
		pid2 = fork();
		if (pid2 < 0)
			exit(0);
		ft_child_two(fd, pid2, param, path);
		ft_close_pipe(fd);
		ft_clear_path(path);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return (0);
	}
	ft_printf("Usage : .pipex file1 command1 command2 file2\n");
	return (1);
}
