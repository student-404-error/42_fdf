/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:18:38 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/07 21:46:57 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"
#include <stdlib.h>
#include <stdio.h>

int	dequeue(t_queue *queue)
{
	int		data;
	t_node	*pop;

	if (isempty_que(queue))
		return (-1);
	pop = queue->front;
	data = pop->data;
	if (queue->size == 1)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
	{
		queue->front->next->prev = NULL;
		queue->front = queue->front->next;
	}
	free(pop);
	queue->size -= 1;
	return (data);
}
