/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:47:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/18 23:51:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**get_env_paths(char *ep[])
{
	char	*path;
	char	**rev;

	path = ft_getenv(ep, "PATH");
	rev = ft_split(path, ':');
	if (!rev)
	{
		rev = (char **)ft_calloc(sizeof(char *), 2);
		rev[0] = ft_strdup(".");
		rev[1] = NULL;
	}
	return (rev);
}