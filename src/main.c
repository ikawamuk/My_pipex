/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:32:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 04:51:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	validate(int ac, char *av[]);
t_ctx	set_ctx(int ac, char *av[]);

int	main(int ac, char *av[], char *ep[])
{
	t_ctx	ctx;

	validate(ac, av);
	ctx = set_ctx(ac, av);
	return (pipex(&ctx, ep));
}
