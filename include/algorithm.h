/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:26:13 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:25:02 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H
# include "data_structure.h"
// ==================================MACRO================================
# define ABS(Value) (Value < 0 ? -Value : Value)
# define MAX(first, second) (first > second ? first : second)
# define MAX_FLAG(first, second) (first < second ? 1 : -1)
# define MIN(first, second) (first < second ? first : second)
# define MIN_FLAG(first, second) (first < second ? 1 : 0)

// ================================FUNCTION===============================
void	bfs_array(int **matrix, t_queue queue);
// void	bfs_graph(t_graph graph, t_queue queue);
// void	bfs_tree(t_tree tree, t_queue queue);

// void	dfs_array(int **matrix, t_queue queue);
// void	dfs_graph(t_graph graph, t_queue queue);
// void	dfs_tree(t_tree tree, t_queue queue);
// lis algo
#endif
