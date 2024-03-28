/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:38 by yumamur           #+#    #+#             */
/*   Updated: 2024/03/28 21:03:38 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*g0(void)
{
	static void	*g;

	return (&g);
}

void	*g1(void)
{
	static void	*g;

	return (&g);
}

void	*g2(void)
{
	static void	*g;

	return (&g);
}

void	*g3(void)
{
	static void	*g;

	return (&g);
}
