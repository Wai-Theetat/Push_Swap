/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:27:51 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/19 20:28:15 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
int		min(int a, int b);
int		max(int a, int b);

//-------Building Stack----------//
void	free_split_argv(char **strs);
char	**get_tokens(int argc, char **argv, char ***split_out);
t_node	*build_stack_from_tokens(char **tokens, char **split_ref);

//-------Push Swap---------//
void	push_swap(t_node **stack_a, t_node **stack_b, size_t len);
//-------Push Swap Operation---------//
int		swap(t_node **stack);
int		push(t_node **stack_from, t_node **stack_to);
int		rotate(t_node **stack, int is_reverse);
int		operation_ctl(t_node **stack_fst, t_node **stack_snd, char *operation);
int		loop_operation(t_node **stack_a, t_node **stack_b, char *op, size_t t);

//-------Sort---------//
int		is_sorted(t_node *stack, int is_decending);
void	rotate_min_to_top(t_node **stack_a, size_t len);
void	sort_three_elem(t_node **stack);
void	sort_four_or_five(t_node **stack_a, t_node **stack_b, size_t len);
void	sort_general(t_node **stack_a, t_node **stack_b);

//-------Calculations---------//
int		lcm(int targ_ind[2], int len_a, int len_b, int return_move);
int		calc(t_node *stack_a, t_node *stack_b, int len, int rt_pos_b);
int		execute_calc(t_node *stack_a, t_node *stack_b, int len, int rt_pos_b);
int		find_min_index(t_node *stack_a, t_node *stack_b, int len);

//-------General Sort Utils---------//
int		node_index(t_node *stack, int target);
int		min_max_pos(t_node *stack, int max, int return_index);
int		find_target(t_node *stack_from, t_node *stack_to);
void	target_push(t_node **stack, int index);
void	reverse_pos(t_node **stack_a, t_node **stack_b, int targ_ind[2]);
void	exec_smt(t_node **stack_a, t_node **stack_b, int targ_ind[2], int mode);
void	exec_ps(t_node **stack_a, t_node **stack_b, int targ_ind[2], int mode);

//-------Other Utilities---------//
int		is_valid(t_node *stack, char *str);
void	ft_showerror_clr_and_exit(t_node *stack);
void	puterr(void);

//Debugger
void	print_two_stack(t_node *a, t_node *b);

#endif