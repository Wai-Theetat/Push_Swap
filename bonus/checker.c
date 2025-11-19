/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/19 22:09:29 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	cleanup_resources(t_node *a, t_node *b, char **ref)
{
	clear_lst_node(a);
	clear_lst_node(b);
	if (ref)
		free_split_argv(ref);
}

static int	exec_silent(char *op, t_node **a, t_node **b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		return (swap(a));
	if (!ft_strncmp(op, "sb\n", 3))
		return (swap(b));
	if (!ft_strncmp(op, "ss\n", 3))
		return (swap(a) && swap(b));
	if (!ft_strncmp(op, "pa\n", 3))
		return (push(b, a));
	if (!ft_strncmp(op, "pb\n", 3))
		return (push(a, b));
	if (!ft_strncmp(op, "ra\n", 3))
		return (rotate(a, 0));
	if (!ft_strncmp(op, "rb\n", 3))
		return (rotate(b, 0));
	if (!ft_strncmp(op, "rr\n", 3))
		return (rotate(a, 0) && rotate(b, 0));
	if (!ft_strncmp(op, "rra\n", 4))
		return (rotate(a, 1));
	if (!ft_strncmp(op, "rrb\n", 4))
		return (rotate(b, 1));
	if (!ft_strncmp(op, "rrr\n", 4))
		return (rotate(a, 1) && rotate(b, 1));
	return (0);
}

static void	read_and_exec(t_node **a, t_node **b, char **ref)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_silent(line, a, b))
		{
			free(line);
			gnl_cleanup(0);
			cleanup_resources(*a, *b, ref);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
	gnl_cleanup(0);
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
		puterr();
	tokens = get_tokens(argc, argv, &split_ref);
	if (!tokens || !tokens[0])
	{
		free_split_argv(split_ref);
		puterr();
	}
	stack_a = build_stack_from_tokens(tokens, split_ref);
	read_and_exec(&stack_a, &stack_b, split_ref);
	if (is_sorted(stack_a, 0) && get_stack_len(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	cleanup_resources(stack_a, stack_b, split_ref);
	return (0);
}
