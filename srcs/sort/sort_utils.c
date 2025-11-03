/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:23:00 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/03 13:32:40 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_node *stack, int is_decending)
{
	t_node	*trav;

	trav = get_first_or_last_node(stack, 0);
	if (get_stack_len(stack) == 0 || !stack)
		return (0);
	while (trav->next)
	{
		if(trav->content > trav->next->content && !is_decending)
			return (0);
		if(trav->content < trav->next->content && is_decending)
			return (0);
		trav = trav->next;
	}
	return (1);
}