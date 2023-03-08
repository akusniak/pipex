/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 15:23:01 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>//fork
#include <sys/wait.h>//wait
#include <fcntl.h>//open

#include <stdio.h>//debug

//        ./pipex file1 cmd1 cmd2 file2

int main()//int ac, char **param)
{
	int	fd[2]; //0 - read **** 1 - write
	pid_t	pid1;
	pid_t	pid2;
	int		fd1;
	int		fd2;

	/*check les prametres*/
	// if (ac == 5)
	// {
		//(void)param;
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			return (1);
		fd1 = open("axel.txt", O_RDONLY);
		if (pid1 == 0)//on se trouve dans le child process
		{
			dup2(fd1, STDIN_FILENO); // on fait pointer la tete de lecture [0] vers le fichier qu'on souhaite lire
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close (fd1);
			//close(fd[1]);
			execlp("cat", "cat", NULL);// execution de notre premiere commande
		}
		fd2 = open("result.txt", O_CREAT | O_RDWR, 00700);
		pid2 = fork();
		if (pid2 == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(fd2, STDOUT_FILENO);
			close(fd[1]);
			close(fd2);
			execlp("ls", "ls", NULL);
		}
		//close(fd1);
		//close(fd2);
		close(fd[0]);
		close(fd[1]);//close avant les waitpid
		waitpid(pid1, NULL, 0);// pour laisserle teps au child de s'executer
		waitpid(pid2, NULL, 0);// pour laisserle teps au child de s'executer
		return (0);
	//}
	//else
	//{
		//ft_printf("Usage : .pipex file1 command1 command2 file2\n");
		//return (1);
	//}
}

// .pipex   file1    command1 command2 file2
// param[0] param[1] param[2] param[3] param[4]
