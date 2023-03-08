#include "pipex.h"

void	ft_execute_cmd(char *command, t_path *path)
{
	char	**command_w_options;
	char	*cmd;
	int		i;

	command_w_options = ft_get_command(command);
	i = 0;
	while (path->clean[i])
	{
		cmd = ft_strjoin(path->clean[i], command_w_options[0]);
		if (ft_check_command(cmd) == COMMAND_OK)
			execve(cmd, command_w_options, &path->clean[i]);
		free(cmd);
		i = i + 1;
	}
}
