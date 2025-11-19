/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:35:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/19 11:29:53 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elem(t_node **stack)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		if ((*stack)->content < (*stack)->next->next->content)
			operation_ctl(stack, NULL, "sa");
		else if ((*stack)->next->content > (*stack)->next->next->content)
		{
			operation_ctl(stack, NULL, "sa");
			operation_ctl(stack, NULL, "rra");
		}
		else
			operation_ctl(stack, NULL, "ra");
	}
	else
	{
		if ((*stack)->content > (*stack)->next->next->content)
			operation_ctl(stack, NULL, "rra");
		else
		{
			operation_ctl(stack, NULL, "sa");
			operation_ctl(stack, NULL, "ra");
		}
	}
}

void	sort_four_or_five(t_node **stack_a, t_node **stack_b, size_t len)
{
	size_t	temp;

	temp = len;
	while (temp-- > 3)
	{
		rotate_min_to_top(stack_a, temp + 1);
		operation_ctl(stack_a, stack_b, "pb");
	}
	if (!is_sorted(*stack_a, 0))
		sort_three_elem(stack_a);
	loop_operation(stack_a, stack_b, "pa", len - 3);
}

static void	push_all_except_three_to_b(t_node **stack_a, t_node **stack_b)
{
	int		targ_ind[2];
	int		mode;
	t_node	*node_to_push;
	int		len_a;
	int		i;

	while (get_stack_len(*stack_a) > 3)
	{
		node_to_push = get_first_or_last_node(*stack_a, 0);
		len_a = get_stack_len(node_to_push);
		targ_ind[0] = find_min_index(node_to_push,
				get_first_or_last_node(*stack_b, 0), len_a);
		i = -1;
		while (++i < targ_ind[0])
			node_to_push = node_to_push->next;
		targ_ind[1] = execute_calc(node_to_push,
				get_first_or_last_node(*stack_b, 0), len_a, 1);
		mode = lcm(targ_ind, len_a, get_stack_len(*stack_b), 1);
		if (mode == 1)
			reverse_pos(stack_a, stack_b, targ_ind);
		exec_ps(stack_a, stack_b, targ_ind, mode);
		operation_ctl(stack_a, stack_b, "pb");
	}
}

static void	push_all_to_a_in_order(t_node **stack_a, t_node **stack_b)
{
	while (get_stack_len(*stack_b) > 0)
	{
		target_push(stack_a, find_target(*stack_b, *stack_a));
		operation_ctl(stack_a, stack_b, "pa");
	}
}

void	sort_general(t_node **stack_a, t_node **stack_b)
{
	loop_operation(stack_a, stack_b, "pb", 2);
	push_all_except_three_to_b(stack_a, stack_b);
	sort_three_elem(stack_a);
	push_all_to_a_in_order(stack_a, stack_b);
	rotate_min_to_top(stack_a, get_stack_len(*stack_a));
}
