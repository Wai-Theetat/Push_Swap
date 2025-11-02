/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:41:38 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/02 13:30:04 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*temp;

	*stack = get_first_or_last_node(*stack, 0);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (1);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
	return (1);
}

int	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*temp;

	if (stack_from == NULL || *stack_from == NULL)
		return (1);
	*stack_from = get_first_or_last_node(*stack_from, 0);
	*stack_to = get_first_or_last_node(*stack_to, 0);
	temp = (*stack_from)->next;
	if (temp != NULL)
		temp->prev = NULL;
	(*stack_from)->next = *stack_to;
	if (*stack_to != NULL)
		(*stack_to)->prev = *stack_from;
	*stack_to = *stack_from;
	*stack_from = temp;
	print_two_stack(*stack_from, *stack_to);
	return (1);
}

int	rotate(t_node **stack, int is_reverse)
{
	t_node *temp;

	*stack = get_first_or_last_node(*stack, 0);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (1);
	temp = *stack;
	if (!is_reverse)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->prev = get_first_or_last_node(*stack, 1);
		temp->next = NULL;
		temp->prev->next = temp;
	}
	else
	{
		*stack = get_first_or_last_node(*stack, 1);
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = temp;
		temp->prev = *stack;
	}
	return (1);
}

int	operation_ctl(t_node **stack_a, t_node **stack_b, char *operation)
{
	ft_printf("%s\n", operation);
	if (ft_strncmp(operation, "sa", 3) == 0)
		return (swap(stack_a));
	if (ft_strncmp(operation, "sb", 3) == 0)
		return (swap(stack_b));
	if (ft_strncmp(operation, "ss", 3) == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strncmp(operation, "pa", 3) == 0)
		return (push(stack_b, stack_a));
	if (ft_strncmp(operation, "pb", 3) == 0)
		return (push(stack_a, stack_b));
	if (ft_strncmp(operation, "ra", 3) == 0)
		return (rotate(stack_a, 0));
	if (ft_strncmp(operation, "rb", 3) == 0)
		return (rotate(stack_b, 0));
	if (ft_strncmp(operation, "rr", 3) == 0)
		return (rotate(stack_a, 0) && rotate(stack_b, 0));
	if (ft_strncmp(operation, "rra", 3) == 0)
		return (rotate(stack_a, 1));
	if (ft_strncmp(operation, "rrb", 3) == 0)
		return (rotate(stack_b, 1));
	if (ft_strncmp(operation, "rrr", 3) == 0)
		return (rotate(stack_a, 1) && rotate(stack_b, 1));
	return (0);
}
