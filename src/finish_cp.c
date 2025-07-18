/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_cp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:43:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 03:20:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <string.h>

void	finish_cp(t_cp *cp, char *err_text)
{
	int	err;

	err = errno;
	ft_putstr_fd("pipex: ", 2);
	if (err_text)
	{
		ft_putstr_fd(err_text, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err == SYNTAX_ERROR1)
		ft_putstr_fd("syntax error unclosed qupte\n", 2);
	else if (err == SYNTAX_ERROR2)
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	else
		ft_putendl_fd(strerror(err), 2);
	safe_close(cp->in);
	safe_close(cp->out);
	cp->env_paths = free_str_arr(cp->env_paths);
	cp->argv = free_str_arr(cp->argv);
	free(cp->cmd_path);
	exit(EXIT_FAILURE);
}
