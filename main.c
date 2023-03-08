/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 13:09:46 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>//fork
#include <sys/wait.h>//wait
#include <fcntl.h>//open

#include <stdio.h>//debug

// int main()
// {
// 	int	id;

// 	id = fork(); //--> return un int
// 	if (id == 0)// --> si fork retourne 0 alors on se trouve dans le child
// 	{
// 		printf("Hello from child [%d]", id);
// 	}
// 	else// --> sinon on se trouve dans le main process
// 	{
// 		printf("Hello from parent [%d]", id);
// 		fork();
// 	}
// 	return (0);
// }


// int main()// --> result impredictable without wait();
// {
// 	int id;
// 	int	n;

// 	id = fork();
// 	if (id == 0)
// 	{
// 		n = 1;
// 	}
// 	else
// 	{
// 		n = 6;
// 	}
// 	if (id != 0)
// 	{
// 		wait(NULL); //NULL --> wait renvoie une valeur
// 	}
// 	int i;
// 	for (i = n; i < n + 5; i++){
// 		printf("%d ", i);
// 		fflush(stdout);
// 	}
// 	return (0);
// }

// int	main()
// {
// 	int	id;

// 	id = fork();
// 	printf("[%d][%d]", getpid(), getppid());
// 	return (0);
// }

// int main()
// {
// 	int	fd[2];
// 	// fd[0] - read
// 	// fd[1] - write
// 	int	id;

// 	pipe(fd);
// 	id = fork();
// 	if (id == 0)
// 	{
// 		int	x;

// 		close(fd[0]);
// 		printf("Input a number : ");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int	y;

// 		close(fd[1]);
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("Got from child : %d", y);//je suis dans le parent process
// 	}
// 	return (0);
// }

int main()
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)// on va effectuer nos actions dans ce child process
	{
		dup2(fd[1], STDOUT_FILENO);// remains open even if we dup it
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "3", "google.com", NULL);// execution de notre premiere commande
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);//close avant les waitpid
	waitpid(pid1, NULL, 0);// pour laisserle teps au child de s'executer
	waitpid(pid2, NULL, 0);// pour laisserle teps au child de s'executer
	return (0);
}

