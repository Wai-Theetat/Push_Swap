/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:35:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/03 13:55:54 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_three(t_node **stack)
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
