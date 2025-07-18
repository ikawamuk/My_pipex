/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xset_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:02:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 04:53:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

static char	*set_redirect(int i, t_ctx ctx, t_cp *cp);
static char	*redirect(int i, t_ctx ctx, t_cp *cp);
char		*here_doc(int i, t_ctx ctx, t_cp *cp);

void	xset_redirect(int i, t_ctx ctx, t_cp *cp)
{
	char	*rev;

	rev = set_redirect(i, ctx, cp);
	if (rev)
	{
		safe_close(cp->in);
		safe_close(cp->out);
		error(rev);
	}
	return ;
}

static char	*set_redirect(int i, t_ctx ctx, t_cp *cp)
{
	char	*rev;

	if (ctx.heredoc)
		rev = here_doc(i, ctx, cp);
	else
		rev = redirect(i, ctx, cp);
	return (rev);
}

static char	*redirect(int i, t_ctx ctx, t_cp *cp)
{
	if (i == 0)
	{
		safe_close(cp->in);
		cp->in = open(ctx.infile, O_RDONLY);
		if (cp->in == -1)
			return (ctx.infile);
	}
	else if (i == ctx.cmd_num - 1)
	{
		safe_close(cp->out);
		cp->out = open(ctx.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cp->out == -1)
			return (ctx.outfile);
	}
	return (NULL);
}
