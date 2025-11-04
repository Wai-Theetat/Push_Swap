/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:29:27 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 12:44:06 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b, size_t len)
{
	*stack_a = get_first_or_last_node(*stack_a, 0);
	if (is_sorted(*stack_a, 0))
		return ;
	if (len == 2)
		operation_ctl(stack_a, stack_b, "sa");
	else if (len == 3)
		sort_three_elem(stack_a);
	else if (len > 3 && len < 6)
		sort_four_or_five(stack_a, stack_b, len);
	else
		sort_general(stack_a, stack_b, len);
}
