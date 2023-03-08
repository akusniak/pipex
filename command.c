
#include "pipex.h"

char    **ft_get_command(char *command)
{
    char **command_w_options;

    command_w_options = ft_split(command, 32);
    if (command_w_options == NULL)
        return (NULL);
    return (command_w_options);
}

int ft_check_command(char *path)
{
    if (access(path, F_OK | R_OK | X_OK) == 0)
        return (COMMAND_OK);
    else
        return (COMMAND_KO);
}
// int execve(const char *pathname, char *const argv[], char *const envp[]);