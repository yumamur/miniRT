/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:10 by yumamur           #+#    #+#             */
/*   Updated: 2024/04/03 01:26:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

static _Bool	is_ext_valid(char *filename, char *ext)
{
	char	*file_ext;

	file_ext = ft_strrchr(filename, '.');
	if (file_ext && !ft_strcmp(file_ext, ext))
		return (1);
	return (0);
}

static _Bool	is_file_available(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

_Bool	is_file_valid(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	if (argv[1] && *argv[1] != '\0' && ft_strlen(argv[1]) > 4
		&& is_ext_valid(argv[1], ".rt")
		&& is_file_available(argv[1]))
		return (1);
	return (0);
}
