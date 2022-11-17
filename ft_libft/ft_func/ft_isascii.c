/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:38:18 by segarcia          #+#    #+#             */
/*   Updated: 2022/08/29 14:15:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index_ft_func.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}