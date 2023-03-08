/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:52:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/08 16:15:43 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>//fork
# include <sys/wait.h>//wait
# include <fcntl.h>//open
# include <stdio.h>//debug

void	ft_child_one(int *fd, int pid1);
void	ft_child_two(int *fd, int pid2);

#endif
