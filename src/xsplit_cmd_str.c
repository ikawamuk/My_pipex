/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsplit_cmd_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:41:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:55:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "split_cmd_str.h"

char	**xsplit_cmd_str(char	*cmd_str, t_cp *cp)
{
	char	**argv;

	argv = split_cmd_str(cmd_str);
	if (!argv)
	{
		if (errno == SYNTAX_ERROR1)
			finish_cp(cp, NULL);
		else
			finish_cp(cp, "malloc");
	}
	if (!*argv)
	{
		errno = SYNTAX_ERROR2;
		free_str_arr(argv);
		finish_cp(cp, NULL);
	}
	return (argv);
}
