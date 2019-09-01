/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 06:39:02 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/19 06:39:13 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only_3(t_stack *stack)
{
	int	elem[3];

	elem[0] = stack->a[2];
	elem[1] = stack->a[1];
	elem[2] = stack->a[0];
	if (elem[0] < elem[1] && elem[1] < elem[2])
		return ;
	else if (elem[0] > elem[1] && elem[1] > elem[2])
	{
		ps_s(stack->a, stack->alen, 'a', stack);
		ps_rr(stack->a, stack->alen, 'a', stack);
	}
	else if (elem[0] < elem[1] && elem[0] > elem[2])
		ps_rr(stack->a, stack->alen, 'a', stack);
	else if (elem[0] < elem[1] && elem[0] < elem[2])
	{
		ps_rr(stack->a, stack->alen, 'a', stack);
		ps_s(stack->a, stack->alen, 'a', stack);
	}
	else if (elem[0] > elem[1] && elem[0] > elem[2])
		ps_r(stack->a, stack->alen, 'a', stack);
	else if (elem[0] > elem[1] && elem[0] < elem[2])
		ps_s(stack->a, stack->alen, 'a', stack);
}

void	sort_stackb2(t_stack *stack, int i, int tmp, int n)
{
	int aa;
	int count;
	int countb;

	count = 0;
	countb = 0;
	aa = 0;
	while (--tmp >= 0)
		if (stack->b[i--] > stack->pivot)
		{
			while (aa > 0)
			{
				aa--;
				ps_r(stack->b, stack->blen, 'b', stack) && i++;
				countb++;
			}
			ps_p(stack, 'a', 1);
			count++;
		}
		else
			aa++;
	while (--countb >= 0)
		ps_rr(stack->b, stack->blen, 'b', stack);
	sort_stacka(stack, count);
	sort_stackb(stack, n - count);
}

void	sort_stackb(t_stack *stack, int n)
{
	int tmp;
	int i;

	if (n <= 1)
		return ;
	if (check_sort(stack->b, n, stack->blen, 'b'))
	{
		while (--n >= 0)
			ps_p(stack, 'a', 1);
		return ;
	}
	tmp = n;
	i = stack->blen - 1;
	if (n > 2)
	{
		stack->pivot = determ_pivot(stack->b, n, stack->blen);
		sort_stackb2(stack, i, tmp, n);
	}
	else
	{
		stack->b[stack->blen - 1] < stack->b[stack->blen - 2]
		? ps_s(stack->b, stack->blen, 'b', stack) : 0;
		while (--n >= 0)
			ps_p(stack, 'a', 1);
	}
}

void	sort_stacka2(t_stack *stack, int i, int tmp, int n)
{
	int aa;
	int countb;
	int count;

	count = 0;
	countb = 0;
	aa = 0;
	while (--tmp >= 0)
		if (stack->a[i--] < stack->pivot)
		{
			while (aa > 0)
			{
				countb++;
				ps_r(stack->a, stack->alen, 'a', stack) && i++;
				aa--;
			}
			ps_p(stack, 'b', 1);
			count++;
		}
		else
			aa++;
	while (--countb >= 0)
		ps_rr(stack->a, stack->alen, 'a', stack);
	sort_stacka(stack, n - count);
	sort_stackb(stack, count);
}

void	sort_stacka(t_stack *stack, int n)
{
	int tmp;
	int i;

	if (n <= 1 || check_sort(stack->a, n, stack->alen, 'a'))
		return ;
	tmp = n;
	i = stack->alen - 1;
	if (n > 3)
	{
		stack->pivot = determ_pivot(stack->a, n, stack->alen);
		sort_stacka2(stack, i, tmp, n);
	}
	else
		sort_3_or_2_param1(stack, stack->alen, n);
}
