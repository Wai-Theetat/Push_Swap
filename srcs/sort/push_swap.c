/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:29:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/03 12:25:33 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b, size_t len)
{
	(void)len;
	// (void)stack_a;
	// (void)stack_b;
	print_two_stack(*stack_a, *stack_b);

	operation_ctl(stack_a, stack_b, "sa");
	operation_ctl(stack_a, stack_b, "pa");
	operation_ctl(stack_a, stack_b, "pb");
	operation_ctl(stack_a, stack_b, "pb");

	// operation_ctl(&stack_a, &stack_b, "pb");
	// operation_ctl(&stack_a, &stack_b, "pb");
	// operation_ctl(&stack_a, &stack_b, "pb");
	// ft_printf("=============\n");
	// print_two_stack(stack_a, stack_b);
	// operation_ctl(&stack_a, &stack_b, "rrb");
	// // operation_ctl(&stack_a, &stack_b, "rrr");

	ft_printf("=============\n");
	print_two_stack(*stack_a, *stack_b);
}