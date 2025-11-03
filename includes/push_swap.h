/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:51 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/03 13:56:22 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

//-------Doubly Linked-List---------//
typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//-------Stack additional behaviour extra utility---------//
t_node	*create_node(int content);
t_node	*add_node(t_node *node, int content);
void	clear_lst_node(t_node *node);

t_node	*get_first_or_last_node(t_node *node, int is_last);
size_t	get_stack_len(t_node *stack);
int		compare_min(int a, int b);
int		compare_max(int a, int b);

//-------Push Swap---------//
void	push_swap(t_node **stack_a, t_node **stack_b, size_t len);
//-------Push Swap Operation---------//
int		swap(t_node **stack);
int		push(t_node **stack_from, t_node **stack_to);
int		rotate(t_node **stack, int is_reverse);
int		operation_ctl(t_node **stack_fst, t_node **stack_snd, char *operation);

//-------Sort---------//
int		is_sorted(t_node *stack, int is_decending);
void	sort_by_three(t_node **stack);

//-------Other Utilities---------//
int		is_valid(t_node *stack, char *str);
void	ft_showerror_clr_and_exit(t_node *stack);

//Debugger
void	print_two_stack(t_node *a, t_node *b);

#endif

/*
When 3 random number - Do the in-place

#Case1
A B
1		
2
3

#Case2	sa		ra
A B		A B		A B
1		3		1
3		1		2
2		2		3

#Case3	sa
A B		A B
2		1
1		2
3		3

#Case 4 rra
A B		A B
2		1
3		2
1		3

#Case 5 ra
A B		A B
3		1
1		2
2		3

#Case 6 sa		rra
A B		A B		A B
3		2		1
2		3		2
1		1		3

*/