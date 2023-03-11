/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:18:03 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/11 11:23:47 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path(t_path *path)
{
	path->envp = "/mnt/nfs/homes/akusniak/bin/:/mnt/nfs/homes/akusniak/bin/:/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/";
	path->clean = ft_split(path->envp, ':');
}

//s'occper du cas ou chemin relatif /bin/command par exemple..
