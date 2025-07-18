/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:47:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 03:20:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		create_pipe(t_ctx *ctx, t_cp *cp);
void		create_child_process(t_cp *cp);
void		child_process(t_cp *cp, int i, t_ctx ctx, char *ep[]);
int			wait_child_process(t_ctx ctx, t_cp cp);

int	pipex(t_ctx *ctx, char *ep[])
{
	t_cp	cp;
	int		i;

	i = 0;
	while (i < ctx->cmd_num)
	{
		create_pipe(ctx, &cp);
		create_child_process(&cp);
		if (cp.pid == 0)
		{
			safe_close(ctx->prev_pipe_to_read);
			child_process(&cp, i, *ctx, ep);
		}
		safe_close(cp.in);
		safe_close(cp.out);
		i++;
	}
	return (wait_child_process(*ctx, cp));
}
