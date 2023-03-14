#include "pipex.h"

t_path	*ft_path()
{
	t_path	*path;

	path = malloc(sizeof(t_path));
	if (path == NULL)
		return (NULL);
	path->envp = "/mnt/nfs/homes/akusniak/bin/:/mnt/nfs/homes/akusniak/bin/:/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/";
	path->clean = ft_split(path->envp, ':');
	if (path->clean == NULL)
		return (NULL);
	return (path);
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
