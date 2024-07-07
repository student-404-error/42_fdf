/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:34:26 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/07 21:39:45 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"
#include <stdlib.h>

void	ft_free_queue(t_queue *queue)
{
	t_node	*node;
	t_node	*tmp;

	node = queue->front;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(queue);
}
