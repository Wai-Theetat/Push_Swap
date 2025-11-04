/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:23:00 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 14:32:07 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack, int is_decending)
{
	t_node	*trav;

	trav = get_first_or_last_node(stack, 0);
	if (get_stack_len(stack) == 0 || !stack)
		return (0);
	while (trav->next)
	{
		if (trav->content > trav->next->content && !is_decending)
			return (0);
		if (trav->content < trav->next->content && is_decending)
			return (0);
		trav = trav->next;
	}
	return (1);
}

static size_t	get_min_pos(t_node *stack)
{
	t_node	*tmp;
	int		min_val;
	size_t	min_pos;
	size_t	current_pos;

	tmp = get_first_or_last_node(stack, 0);
	if (!tmp)
		return (0);
	min_val = tmp->content;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->content < min_val)
		{
			min_val = tmp->content;
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}

void	rotate_min_to_top(t_node **stack_a, size_t len)
{
	size_t	min_pos;
	size_t	moves;

	min_pos = get_min_pos(*stack_a);
	if (min_pos <= len / 2)
	{
		moves = min_pos;
		while (moves--)
			operation_ctl(stack_a, NULL, "ra");
	}
	else
	{
		moves = len - min_pos;
		while (moves--)
			operation_ctl(stack_a, NULL, "rra");
	}
}
