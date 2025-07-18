/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:27:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:19:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <string.h>

static void	print_error(int err, char *error_text);

void	error(char *error_text)
{
	int	err;

	err = errno;
	print_error(err, error_text);
	exit(EXIT_FAILURE);
}

static void	print_error(int err, char *error_text)
{
	ft_putstr_fd("pipex: ", 2);
	if (error_text)
	{
		ft_putstr_fd(error_text, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(strerror(err), 2);
}
