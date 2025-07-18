/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:58:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:39:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		set_cp(t_cp *cp, int i, t_ctx ctx, char **ep);
static void	convert_stdio(t_cp *cp);

void	child_process(t_cp *cp, int i, t_ctx ctx, char *ep[])
{
	set_cp(cp, i, ctx, ep);
	convert_stdio(cp);
	execve(cp->cmd_path, cp->argv, cp->ep);
}

static void	convert_stdio(t_cp *cp)
{
	if (dup2(cp->in, STDIN_FILENO) == -1)
		error("dup");
	if (cp->in != STDIN_FILENO)
		close(cp->in);
	if (dup2(cp->out, STDOUT_FILENO) == -1)
		error("dup");
	if (cp->out != STDOUT_FILENO)
		close(cp->out);
	return ;
}
