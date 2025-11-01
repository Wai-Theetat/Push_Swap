/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/10/31 14:14:51 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (is_valid(stack_a, argv[i]) == 0)
				ft_showerror_clr_and_exit(stack_a);
			stack_a = add_node(stack_a, ft_atoi(argv[i]));
		}
		// push_swap(stack_a, stack_b, get_stack_len(stack_a));
		clear_lst_node(stack_a);
		clear_lst_node(stack_b);
	}
    return (0);
}

