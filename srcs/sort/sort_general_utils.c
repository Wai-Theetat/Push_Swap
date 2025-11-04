/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:31:52 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 15:19:13 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_lcm(int *arr, int len, int return_index)
{
	int	min;
	int	i;
	int	target_index;

	i = 0;
	target_index = 0;
	min = arr[0];
	while (++i < len)
	{
		if (arr[i] < min && arr[i] >= 0)
		{
			min = arr[i];
			target_index = i;
		}
	}
	if (return_index == 1)
		return (target_index);
	else
		return (min);
}

int	lcm(int targ_ind[2], int len_a, int len_b, int return_move)
{
	int	nlcm[4];
	int	temp_pos_b;

	temp_pos_b = -1;
	if (targ_ind[1] == 0)
	{
		temp_pos_b = targ_ind[1];
		targ_ind[1] = targ_ind[0];
	}
	nlcm[0] = max(targ_ind[0], targ_ind[1]);
	nlcm[1] = max(len_a - targ_ind[0], len_b - targ_ind[1]);
	nlcm[2] = targ_ind[0] + (len_b - targ_ind[1]);
	nlcm[3] = (len_a - targ_ind[0]) + targ_ind[1];
	if (temp_pos_b != -1)
		targ_ind[1] = temp_pos_b;
	if (return_move == 1)
		return (min_lcm(nlcm, 4, 1));
	else
		return (min_lcm(nlcm, 4, 0));
}

int	calc(t_node *stack_a, t_node *stack_b, int len, int rt_pos_b)
{
	t_node	*tmp;
	int		nmoves_to_top[2];
	int		target;

	nmoves_to_top[0] = node_index(stack_a, stack_a->content);
	tmp = get_first_or_last_node(stack_b, 0);
	if (stack_b)
	{
		target = tmp->content;
		while (tmp)
		{
			if ((tmp->content > target && tmp->content < stack_a->content)
				|| (tmp->content < stack_a->content
					&& target > stack_a->content))
				target = tmp->content;
			tmp = tmp->next;
		}
		nmoves_to_top[1] = node_index(stack_b, target);
		if (rt_pos_b == 1)
			return (nmoves_to_top[1]);
		else
			return (lcm(nmoves_to_top, len, get_stack_len(stack_b), 0) + 1);
	}
	return (nmoves_to_top[0] + 1);
}

int	execute_calc(t_node *stack_a, t_node *stack_b, int len, int rt_pos_b)
{
	int	nmoves;
	int	targ_ind[2];

	if ((stack_a->content < min_max_pos(stack_b, 0, 0))
		|| (stack_a->content > min_max_pos(stack_b, 1, 0)))
	{
		targ_ind[0] = node_index(stack_a, stack_a->content);
		targ_ind[1] = min_max_pos(stack_b, 1, 1);
		if (rt_pos_b == 1)
			nmoves = targ_ind[1];
		else
			nmoves = (lcm(targ_ind, get_stack_len(stack_a),
						get_stack_len(stack_b), 0) + 1);
	}
	else
		nmoves = calc(stack_a, stack_b, len, rt_pos_b);
	return (nmoves);
}

int	find_min_index(t_node *stack_a, t_node *stack_b, int len)
{
	int		min;
	int		index[2];
	t_node	*tmp;

	tmp = get_first_or_last_node(stack_a, 0);
	min = execute_calc(stack_a, stack_b, len, 0);
	index[0] = 0;
	index[1] = 0;
	while (tmp)
	{
		if (execute_calc(tmp, stack_b, len, 0) < min)
		{
			min = execute_calc(tmp, stack_b, len, 0);
			index[1] = index[0];
		}
		tmp = tmp->next;
		index[0]++;
	}
	return (index[1]);
}
