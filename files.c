#include "pipex.h"

void	ft_open_files(t_pipex *pipex, char **param)
{
	pipex->fd_infile = open(param[1], O_RDONLY);
	if (pipex->fd_infile == -1)
	{	
		ft_close_unused_fd(pipex->fd[0], pipex->fd[1]);
		perror("First file\n");
		ft_clear_path(pipex->path);
		free(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->fd_outfile = open(param[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (pipex->fd_outfile == -1)
	{
		ft_close_unused_fd(pipex->fd[0], pipex->fd[1]);
		perror("Second file\n");
		ft_clear_path(pipex->path);
		close(pipex->fd_infile);
		free(pipex);
		exit(EXIT_FAILURE);
	}
}