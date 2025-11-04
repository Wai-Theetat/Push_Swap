/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_calc_fst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:31:47 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 15:20:35 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_index(t_node *stack, int target)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = get_first_or_last_node(stack, 0);
	if (get_stack_len(stack) == 0 || !stack)
		return (-1);
	while (tmp)
	{
		if (tmp->content == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	min_max_pos(t_node *stack, int max, int return_index)
{
	int		target;
	size_t	attr[2];
	t_node	*tmp;

	tmp = get_first_or_last_node(stack, 0);
	attr[0] = -1;
	attr[1] = 0;
	if (!tmp)
		return (0);
	target = tmp->content;
	while (++attr[0] < get_stack_len(stack))
	{
		if ((tmp->content > target && max == 1) || (tmp->content < target
				&& max == 0))
		{
			target = tmp->content;
			attr[1] = attr[0];
		}
		tmp = tmp->next;
	}
	if (return_index == 1)
		return (attr[1]);
	else
		return (target);
}

int	find_target(t_node *stack_from, t_node *stack_to)
{
	t_node	*tmp;
	int		target;

	tmp = get_first_or_last_node(stack_to, 0);
	target = tmp->content;
	if (stack_from->content > min_max_pos(stack_to, 1, 0))
		return (min_max_pos(stack_to, 0, 1));
	while (tmp)
	{
		if ((tmp->content < target && tmp->content > stack_from->content)
			|| (tmp->content > stack_from->content
				&& target < stack_from->content))
			target = tmp->content;
		tmp = tmp->next;
	}
	return (node_index(stack_to, target));
}

void	target_push(t_node **stack, int index)
{
	int	len;

	len = get_stack_len(*stack);
	if (index <= len / 2)
	{
		while (index--)
			operation_ctl(stack, NULL, "ra");
	}
	else
	{
		index = len - index;
		while (index--)
			operation_ctl(stack, NULL, "rra");
	}
}

void	exec_smt(t_node **stack_a, t_node **stack_b, int targ_ind[2], int mode)
{
	if (mode == 0)
	{
		loop_operation(stack_a, stack_b, "rr",
			min(targ_ind[0], targ_ind[1]));
		if (max(targ_ind[0], targ_ind[1]) == targ_ind[0]
			&& targ_ind[0] != targ_ind[1])
			loop_operation(stack_a, stack_a, "ra",
				targ_ind[0] - targ_ind[1]);
		else if (max(targ_ind[0], targ_ind[1]) == targ_ind[1]
			&& targ_ind[0] != targ_ind[1])
			loop_operation(stack_a, stack_b, "rb",
				targ_ind[1] - targ_ind[0]);
	}
	else if (mode == 1)
	{
		loop_operation(stack_a, stack_b, "rrr", min(targ_ind[0], targ_ind[1]));
		if (max(targ_ind[0], targ_ind[1]) == targ_ind[0]
			&& targ_ind[0] != targ_ind[1])
			loop_operation(stack_a, stack_a, "rra", targ_ind[0] - targ_ind[1]);
		else if (max(targ_ind[0], targ_ind[1]) == targ_ind[1]
			&& targ_ind[0] != targ_ind[1] && targ_ind[1] != 0)
			loop_operation(stack_a, stack_b, "rrb", targ_ind[1] - targ_ind[0]);
	}
}
