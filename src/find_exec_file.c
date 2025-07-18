/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 01:45:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 04:54:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		**get_env_paths(char *ep[]);
static char	*get_cmd_path(t_cp *cp);
static char	*join_dir_and_file_name(char *dir, char *name);
static void	cmd_not_found(t_cp *cp);
static void	permission_denied(t_cp *cp, char *path);

char	*find_exec_file(t_cp *cp)
{
	char	*path;

	if (ft_strchr(cp->argv[0], '/'))
		path = cp->argv[0];
	else
	{
		cp->env_paths = get_env_paths(cp->ep);
		path = get_cmd_path(cp);
		cp->env_paths = free_str_arr(cp->env_paths);
	}
	if (!path)
		cmd_not_found(cp);
	if (access(path, X_OK) != 0)
		permission_denied(cp, path);
	return (path);
}

static void	cmd_not_found(t_cp *cp)
{
	ft_putstr_fd(cp->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	safe_close(cp->in);
	safe_close(cp->out);
	cp->env_paths = free_str_arr(cp->env_paths);
	cp->argv = free_str_arr(cp->argv);
	exit(CMD_NOT_FOUND);
}

static void	permission_denied(t_cp *cp, char *path)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	safe_close(cp->in);
	safe_close(cp->out);
	cp->env_paths = free_str_arr(cp->env_paths);
	cp->argv = free_str_arr(cp->argv);
	free(cp->cmd_path);
	free(path);
	exit(PERM_DENIED);
}

static char	*get_cmd_path(t_cp *cp)
{
	char	*cmd;
	char	**dirs;
	char	*path;
	size_t	i;

	cmd = cp->argv[0];
	dirs = cp->env_paths;
	i = 0;
	while (dirs[i])
	{
		path = join_dir_and_file_name(dirs[i], cmd);
		if (!path)
			finish_cp(cp, "malloc");
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

static char	*join_dir_and_file_name(char *dir, char *name)
{
	char	*path;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, name);
	free(tmp);
	return (path);
}
