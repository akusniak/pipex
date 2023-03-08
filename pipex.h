/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 16:29:08 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <unistd.h>//fork
# include <sys/wait.h>//wait
# include <fcntl.h>//open
# include <stdio.h>//debug
# include <stdlib.h>

# define COMMAND_KO -1
# define COMMAND_OK 1

typedef struct s_path
{
    char    *envp;
    char    **clean; 
}               t_path;


void	ft_child_one(int *fd, int pid1, char **param, t_path *path);
void	ft_child_two(int *fd, int pid2, char **param, t_path *path);
void    ft_execute_cmd(char *command, t_path *path);
char    **ft_get_command(char *command);
int     ft_check_command(char *path);
void    ft_path(t_path *path);


#endif
