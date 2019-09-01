/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 04:01:07 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/13 04:01:08 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker3(char *s, t_stack *stack)
{
	if (!ft_strcmp(s, "rr"))
	{
		ps_r(stack->a, stack->alen, 'a', stack);
		ps_r(stack->b, stack->blen, 'b', stack);
	}
	else if (!ft_strcmp(s, "rra"))
		ps_rr(stack->a, stack->alen, 'a', stack);
	else if (!ft_strcmp(s, "rrb"))
		ps_rr(stack->b, stack->blen, 'b', stack);
	else if (!ft_strcmp(s, "rrr"))
	{
		ps_rr(stack->a, stack->alen, 'a', stack);
		ps_rr(stack->b, stack->blen, 'b', stack);
	}
	else
	{
		if (!(*s))
			(stack->blen == 0 && check_sort(stack->a, stack->alen,
					stack->alen, 'a')) ? ft_putstr("OK\n") : ft_putstr("KO\n");
		else
			ft_putstr("Error\n");
		free(s);
		return (1);
	}
	return (0);
}

void	checker2(t_stack *stack, char *s)
{
	while (get_next_line(0, &s) > 0)
	{
		if (!ft_strcmp(s, "pa"))
			ps_p(stack, 'a', 1);
		else if (!ft_strcmp(s, "pb"))
			ps_p(stack, 'b', 1);
		else if (!ft_strcmp(s, "sa"))
			ps_s(stack->a, stack->alen, 'a', stack);
		else if (!ft_strcmp(s, "sb"))
			ps_s(stack->b, stack->blen, 'b', stack);
		else if (!ft_strcmp(s, "ss"))
		{
			ps_s(stack->a, stack->alen, 'a', stack);
			ps_s(stack->b, stack->blen, 'b', stack);
		}
		else if (!ft_strcmp(s, "ra"))
			ps_r(stack->a, stack->alen, 'a', stack);
		else if (!ft_strcmp(s, "rb"))
			ps_r(stack->b, stack->blen, 'b', stack);
		else if (checker3(s, stack) == 1)
			return ;
		free(s);
	}
	((stack->blen == 0 && check_sort(stack->a, stack->alen, stack->alen, 'a')))
		? ft_putstr("OK\n") : ft_putstr("KO\n");
}

void	checker(t_stack *stack, int ac, char **str)
{
	char	*s;

	s = NULL;
	stack->print = (!ft_strcmp(str[0], "-v")) ? 2 : 0;
	if (stack->print == 2)
	{
		stack->time = ft_atoll(str[1]);
		str += 2;
		ac -= 2;
	}
	stack->alen = ac + 1;
	if (check(ac, str) == -1)
	{
		ft_putstr("Error\n");
		return ;
	}
	stack->blen = 0;
	stack->b = (int*)ft_memalloc(sizeof(int) * ac);
	stack->a = reader(ac, str);
	if (check_copie(stack->a, stack->alen) == 0)
		ft_putstr("Error\n");
	else
		checker2(stack, s);
	free(stack->a);
	free(stack->b);
}

char	**parce_str(int *ac, int *i, char **av)
{
	char **str;

	if (--(*ac) == 0)
		return (0);
	else if (*ac == 1)
	{
		*ac = ft_w(av[0], 32);
		if (*ac == 1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		*i = 0;
		str = ft_strsplit(av[0], 32, *ac);
	}
	else
		str = av;
	return (str);
}

int		main(int ac, char **av)
{
	t_stack stack;
	char	**str;
	int		i;

	i = 1;
	av++;
	str = parce_str(&ac, &i, av);
	if (str == NULL)
		exit(EXIT_SUCCESS);
	ac--;
	checker(&stack, ac, str);
	if (i == 0)
	{
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
	exit(EXIT_SUCCESS);
}
