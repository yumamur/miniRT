/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:41 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/28 21:03:41 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*_errno_location(void)
{
	static int	errno;

	return (&errno);
}

_Bool	errno_isset(void)
{
	return (0);
}
