/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:13:08 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/27 10:13:20 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*str_join(char *s1, char s2)
{
	int		i;
	int		k;
	char	*s12;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s12 = malloc(ft_strlen(s1) + 2);
	if (!s12)
		return (NULL);
	while (s1[i])
	{
		s12[i] = s1[i];
		i++;
	}
	s12[i++] = s2;
	s12[i] = 0;
	return (s12);
}