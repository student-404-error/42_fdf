/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:25 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/21 20:37:57 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define ABS(Value) (Value < 0 ? -Value : Value)
# define MAX(first, second) (first > second ? first : second)
# define MAX_FLAG(first, second) (first > second ? 1 : 0)
# define MIN(first, second) (first < second ? first : second)
# define MIN_FLAG(first, second) (first < second ? 1 : 0)

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		max;
	int		min;
}	t_stack;
void	find_index(t_list *a);
int		find_lis(t_list *a_list, int size);
//void	push_swap(t_list **a_stack, t_list **b_stack);
int		check_sort(t_list *a);
void	passing_to_b(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk);
void	move_swap(t_list **lst, t_stack **stk, char *title);
void	move_ss(t_list **a_stack, t_list **b_stack);
void	move_push(t_list **to_lst, t_list **fr_lst, t_stack **to, t_stack **fr);
void	move_rotate(t_list **lst, t_stack **stack, char *title);
void	move_rr(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk);
void	move_reverse_rotate(t_list **lst, t_stack **stack, char *title);
void	move_rrr(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk);
void	status_list_and_stack(t_list *lst, t_stack *stk, char *title);
void	three_argu(t_list **a_list, t_stack **a_stk);
void	last_sort(t_list **a, t_stack **a_stk);
t_stack	*ft_new_stack(t_list *lst);

#endif
