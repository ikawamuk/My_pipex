/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:17:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 03:20:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <errno.h>
# include "libft.h"
# include "config.h"

// utils
void	error(char *error_text);
void	safe_close(int fd);
void	finish_cp(t_cp *cp, char *err_text);
void	*free_str_arr(char **arr);

// ft_utils
int		ft_strcmp(char *s1, char *s2);
char	*ft_getenv(char **ep, const char *name);

#endif