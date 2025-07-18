/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:13:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/15 23:03:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char **ep, const char *name)
{
	int	name_len;
	int	i;

	if (!ep || !name)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	while (ep[i])
	{
		if (ft_strncmp(ep[i], name, name_len) == 0 && ep[i][name_len] == '=')
			return (ep[i] + name_len + 1);
		i++;
	}
	return (NULL);
}
