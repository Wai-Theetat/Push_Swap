/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:35:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 14:13:19 by tdharmar         ###   ########.fr       */
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
		rotate_min_to_top(stack_a, len);
		operation_ctl(stack_a, stack_b, "pb");
	}
	sort_three_elem(stack_a);
	loop_operation(stack_a, stack_b, "pa", len - 3);
}

void	sort_general(t_node **stack_a, t_node **stack_b)
{
	int	min_ind;

	min_ind = 0;
	loop_operation(stack_a, stack_b, "pb", 2);
	while (get_stack_len(*stack_a) > 3)
	{
		min_ind = find_min_ind(*stack_a, *stack_b, get_stack_len(*stack_a));
	}
}
