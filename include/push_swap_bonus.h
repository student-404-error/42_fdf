/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:09:36 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/22 19:54:14 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft.h"

void	checker(t_list **a, t_list **b);
void	push(t_list **to_lst, t_list **fr_lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	swap(t_list **lst);
void	ss(t_list **a, t_list **b);
void	movement_swap(t_list **a, t_list **b, char *option);
void	movement_rotate(t_list **a, t_list **b, char *option);
void	movement_reverse_rotate(t_list **a, t_list **b, char *option);
void	movement_push(t_list **a, t_list **b, char *option);

#endif // !PUSH_SWAP_BONUS_H
