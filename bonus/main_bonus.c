/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/14 13:59:39 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipex	*ft_init_pipex()
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	pipex->path = ft_path();
	if (pipex->path == NULL)
	{
		free(pipex);
		return (NULL);
	}
	if (pipe(pipex->fd) == -1)
	{
		ft_clear_path(pipex);
		free(pipex);
		return (NULL);
	}
	return (pipex);
}

int	main(int ac, char **param)
{
	t_pipex	*pipex;

	if (ac < 5)
		return (ft_printf("Usage : .pipex file1 command1 command2 file2\n"), 1);
	else
	{
		pipex = ft_init_pipex();

		if (pipex == NULL)
			return (0);

		ft_open_files(pipex , param, ac);

		/*set entree et sortie */

		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);

		/***********************/

		int	i = 3;
		ft_pipe(param[2], pipex, pipex->infile);
		while (i < ac - 2)
		{
			ft_pipe(param[i], pipex, 1);
			i = i + 1;
		}
		ft_command(param[i], pipex->path);
		ft_free_pipex(pipex);
	}
}


