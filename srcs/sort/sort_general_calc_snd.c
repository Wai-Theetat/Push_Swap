/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_calc_snd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:18:07 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 15:19:11 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ps(t_node **stack_a, t_node **stack_b, int targ_ind[2], int mode)
{
	if (mode == 0 || mode == 1)
		exec_smt(stack_a, stack_b, targ_ind, mode);
	else if (mode == 2)
	{
		loop_operation(stack_a, stack_b, "ra", targ_ind[0]);
		loop_operation(stack_a, stack_b, "rrb",
			get_stack_len(*stack_b) - targ_ind[1]);
	}
	else if (mode == 3)
	{
		loop_operation(stack_a, stack_b, "rra",
			get_stack_len(*stack_a) - targ_ind[0]);
		loop_operation(stack_a, stack_b, "rb", targ_ind[1]);
	}
}
