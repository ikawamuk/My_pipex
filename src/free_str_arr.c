/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:19:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:52:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*free_str_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}
