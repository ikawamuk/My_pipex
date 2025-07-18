/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:28:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:12:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "utils.h"

static void	set_nomal_mode(t_ctx *ctx, int ac, char *av[]);
static void	set_here_doc_mode(t_ctx *ctx, int ac, char *av[]);

t_ctx	set_ctx(int ac, char *av[])
{
	t_ctx	ctx;

	if (ft_strcmp(av[1], "here_doc") == 0)
		set_here_doc_mode(&ctx, ac, av);
	else
		set_nomal_mode(&ctx, ac, av);
	return (ctx);
}

static void	set_nomal_mode(t_ctx *ctx, int ac, char *av[])
{
	ctx->infile = av[1];
	ctx->outfile = av[ac - 1];
	ctx->cmd_num = ac - 3;
	ctx->cmds = av + 2;
	ctx->heredoc = 0;
	ctx->limiter = NULL;
	ctx->prev_pipe_to_read = -1;
	return ;
}

static void	set_here_doc_mode(t_ctx *ctx, int ac, char *av[])
{
	ctx->infile = NULL;
	ctx->outfile = av[ac - 1];
	ctx->cmd_num = ac - 4;
	ctx->cmds = av + 3;
	ctx->heredoc = 1;
	ctx->limiter = av[2];
	ctx->prev_pipe_to_read = -1;
	return ;
}
