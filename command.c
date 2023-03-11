/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:24:09 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 11:24:11 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
