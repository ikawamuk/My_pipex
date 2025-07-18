/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:34:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:35:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/wait.h>

static int	get_status(int status);

int	wait_child_process(t_ctx ctx, t_cp cp)
{
	int	status;
	int	i;
	int	rev;

	rev = 1;
	i = 0;
	while (i++ < ctx.cmd_num)
		if (waitpid(-1, &status, 0) == cp.pid)
			rev = get_status(status);
	return (rev);
}

static int	get_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
