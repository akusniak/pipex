/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:05:16 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 13:06:43 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_command(char *command, t_path *path)
{
	int		i;
	char	*cmd;
	char	**command_w_options;

	i = 0;
	cmd = NULL;
	if (ft_strlen(command) == 0 || ft_is_empty(command) == 1)
		return ;
	command_w_options = ft_split(command, 32);
	if (command_w_options == NULL)
	{
		printf("\n\nPLOUFFFFF\n\n\n");
		return ;
	}
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

int	ft_is_empty(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if ((command[i] >= 8 && command[i] <= 13) || command[i] == 32)
			i = i + 1;
		else
			return (0);
	}
	return(1);
}
