/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:35:35 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/06 20:48:57 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

typedef struct s_node {
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	t_node	*front;
	t_node	*rear;
	int		size;
}	t_queue;

t_node	*ft_lstnew(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);

t_node	*create_node(int data);
void	init_queue(t_queue *queue);
void	is_empty(t_queue *queue);

#endif
