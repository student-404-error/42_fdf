/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:18:27 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/07 21:26:34 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"
#include <stdio.h>

void	enqueue(t_queue *queue, int data)
{
	t_node	*node;

	node = ft_new_node(data);
	if (isempty_que(queue))
	{
		queue->front = node;
		queue->rear = node;
		queue->size += 1;
		printf("empty\n");
		return ;
	}
	queue->size += 1;
	printf("not empty\n");
	queue->rear->next = node;
	printf("not empty 1\n");
	node->prev = queue->rear;
	printf("not empty 2\n");
	queue->rear = queue->rear->next;
	printf("not empty 3\n");
}
