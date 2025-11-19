/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/19 21:36:30 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	char	**split_ref;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	split_ref = NULL;
	if (argc <= 1)
		puterr();
	tokens = get_tokens(argc, argv, &split_ref);
	if (!tokens || !tokens[0])
	{
		free_split_argv(split_ref);
		puterr();
	}
	stack_a = build_stack_from_tokens(tokens, split_ref);
	push_swap(&stack_a, &stack_b, get_stack_len(stack_a));
	clear_lst_node(stack_a);
	clear_lst_node(stack_b);
	if (split_ref)
		free_split_argv(split_ref);
	return (0);
}
