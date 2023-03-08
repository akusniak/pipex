/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_simple_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:55:23 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/13 13:52:56 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_alloc_simple_tab(int largeur)
{
	int	*tab;

	tab = malloc(sizeof(int *[largeur]));
	if (tab == NULL)
		return (NULL);
	return (tab);
}
