/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:00:30 by tdharmar          #+#    #+#             */
/*   Updated: 2025/11/02 11:09:28 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_showerror_clr_and_exit(t_node *stack)
{
	clear_lst_node(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static int	is_space(char c)
{
	char	*str;

	str = " \f\n\r\t\v";
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (0);
}

int	ft_atoi_w_err_chk(char *str, t_node *stack)
{
	long long int	temp;
	int				multi;

	temp = 0;
	multi = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		multi *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		ft_showerror_clr_and_exit(stack);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_showerror_clr_and_exit(stack);
		temp = (temp * 10) + (*str - '0');
		str++;
	}
	if ((multi * temp) > 2147483647 || (multi * temp) < -2147483648)
		ft_showerror_clr_and_exit(stack);
	return (multi * temp);
}

int	is_valid(t_node *stack, char *str)
{
	t_node	*tmp_node;
	int		nbr;

	tmp_node = get_first_or_last_node(stack, 0);
	nbr = ft_atoi_w_err_chk(str, stack);
	while (tmp_node)
	{
		if (tmp_node->content == nbr)
			return (0);
		tmp_node = tmp_node->next;
	}
	return (1);
}
