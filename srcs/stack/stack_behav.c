/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_behav.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:47:07 by tdharmar          #+#    #+#             */
/*   Updated: 2025/10/31 13:46:33 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*add_node(t_node *node, int content)
{
	t_node	*new_node;

	if (!node)
		return (NULL);
	new_node = create_node(content);
	if (!new_node)
		return (NULL);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

void	clear_lst_node(t_node *node)
{
	t_node	*traverse;

	if (!node)
		return ;
	node = get_last_or_first_node(node, 0);
	while (node)
	{
		traverse = node->next;
		free(node);
		node = traverse;
	}
}
