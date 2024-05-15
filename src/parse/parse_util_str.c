/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:23:44 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 23:23:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*str_to_wordtab(void *line)
{
	char	**tab;
	char	*tmp;
	int		i;

	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i])
	{
		tmp = ft_strtrim(tab[i], "\t\n\v\f\r");
		free(tab[i]);
		tab[i] = tmp;
		i++;
	}
	return (tab);
}
