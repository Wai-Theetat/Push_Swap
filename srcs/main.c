	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:46:41 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/03 15:01:14 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_argv(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	**get_tokens(int argc, char **argv, char ***split_out)
{
	if (argc == 2)
	{
		*split_out = ft_split(argv[1], ' ');
		return (*split_out);
	}
	*split_out = NULL;
	return (&argv[1]);
}

static t_node	*build_stack_from_tokens(char **tokens, char **split_ref)
{
	int		i;
	t_node	*stack_a;

	i = 0;
	stack_a = NULL;
	while (tokens[i])
	{
		if (is_valid(stack_a, tokens[i]) == 0)
		{
			if (split_ref)
				free_split_argv(split_ref);
			ft_showerror_clr_and_exit(stack_a);
		}
		stack_a = add_node(stack_a, ft_atoi(tokens[i]));
		i++;
	}
	return (stack_a);
}

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
		return (0);
	tokens = get_tokens(argc, argv, &split_ref);
	stack_a = build_stack_from_tokens(tokens, split_ref);
	push_swap(&stack_a, &stack_b, get_stack_len(stack_a));
	print_two_stack(stack_a, stack_b);
	clear_lst_node(stack_a);
	clear_lst_node(stack_b);
	if (split_ref)
		free_split_argv(split_ref);
	return (0);
}
