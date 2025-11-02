/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:41:38 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/01 21:12:07 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*temp;

	*stack = get_last_or_first_node(*stack, 0);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (1);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->prev
	
}

int		push(t_node **stack_from, t_node **stack_to);
int		rotate(t_node **stack, int is_reverse);