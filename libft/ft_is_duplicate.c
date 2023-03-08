/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:27:56 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/14 11:28:51 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_duplicate(int number, int current, int *stack_a)
{
	current = current - 1;
	while (current >= 0)
	{
		if (stack_a[current] == number)
			return (1);
		current = current - 1;
	}
	return (0);
}
