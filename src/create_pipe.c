/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:23:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:11:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	new_pipe(int *read, int *write);

void	create_pipe(t_ctx *ctx, t_cp *cp)
{
	cp->in = ctx->prev_pipe_to_read;
	if (new_pipe(&ctx->prev_pipe_to_read, &cp->out) == -1)
		error("pipe");
	return ;
}

static int	new_pipe(int *read, int *write)
{
	int	rev;
	int	pipefd[2];

	rev = pipe(pipefd);
	if (rev == -1)
		return (-1);
	*read = pipefd[0];
	*write = pipefd[1];
	return (0);
}
