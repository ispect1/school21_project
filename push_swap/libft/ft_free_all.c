/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 01:07:59 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/13 01:08:00 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_all(char **nr, int j)
{
	while (j >= 0)
	{
		free(nr[j]);
		j--;
	}
	free(nr);
	return (1);
}