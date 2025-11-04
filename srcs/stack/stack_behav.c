/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_behav.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:47:07 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/04 15:19:57 by tdharmar         ###   ########.fr       */
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

	new_node = create_node(content);
	if (!new_node)
		return (NULL);
	if (!node)
		return (new_node);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

void	clear_lst_node(t_node *node)
{
	t_node	*traverse;

	if (!node)
		return ;
	while (node->prev)
		node = node->prev;
	while (node)
	{
		traverse = node->next;
		free(node);
		node = traverse;
	}
}

void	print_two_stack(t_node *a, t_node *b)
{
	t_node	*ta;
	t_node	*tb;

	ta = get_first_or_last_node(a, 0);
	tb = get_first_or_last_node(b, 0);
	while (ta || tb)
	{
		if (ta)
			ft_printf("%d\t", ta->content);
		else
			ft_printf(" \t");
		if (tb)
			ft_printf("%d\n", tb->content);
		else
			ft_printf("\n");
		if (ta)
			ta = ta->next;
		if (tb)
			tb = tb->next;
	}
	ft_printf("_\t_\n");
	ft_printf("A\tB\n");
}
