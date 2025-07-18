/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:58:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/18 21:16:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	create_child_process(t_cp *cp)
{
	cp->pid = fork();
	if (cp->pid == -1)
		error("fork");
	return ;
}
