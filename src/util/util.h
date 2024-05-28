/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:03:45 by yumamur           #+#    #+#             */
/*   Updated: 2024/05/28 08:27:37 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdint.h>

unsigned int	arr_len(void *arr);
void			arr_free(void *data);

void			free_and_null(void *data);
void			free_non_null(void *data);
void			set_seed(uint64_t sd);
double			mock_rand(void);
double			mock_rand_range(double min, double max);

#endif
