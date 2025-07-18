/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:12:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:40:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	xset_redirect(int i, t_ctx ctx, t_cp *cp);
char	**get_env_paths(char *ep[]);
char	**xsplit_cmd_str(char	*cmd_str, t_cp *cp);
char	*find_exec_file(t_cp *cp);

void	set_cp(t_cp *cp, int i, t_ctx ctx, char *ep[])
{
	cp->ep = ep;
	cp->env_paths = NULL;
	cp->argv = NULL;
	cp->cmd_path = NULL;
	xset_redirect(i, ctx, cp);
	cp->argv = xsplit_cmd_str(ctx.cmds[i], cp);
	cp->cmd_path = find_exec_file(cp);
}
