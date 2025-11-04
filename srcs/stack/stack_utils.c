/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:18:13 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 15:14:38 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_first_or_last_node(t_node *node, int is_last)
{
	if (!node)
		return (NULL);
	if (!is_last)
	{
		while (node->prev)
			node = node->prev;
		return (node);
	}
	else
	{
		while (node->next)
			node = node->next;
		return (node);
	}
}

size_t	get_stack_len(t_node *stack)
{
	size_t	len;
	t_node	*temp;

	len = 0;
	temp = get_first_or_last_node(stack, 0);
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reverse_pos(t_node **stack_a, t_node **stack_b, int targ_ind[2])
{
	targ_ind[0] = get_stack_len(*stack_a) - targ_ind[0];
	if (targ_ind[1] != 0)
		targ_ind[1] = get_stack_len(*stack_b) - targ_ind[1];
}
