/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:35:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:04:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <sys/types.h>

# define SYNTAX_ERROR1	1001
# define SYNTAX_ERROR2	1002

# define CMD_NOT_FOUND	127
# define PERM_DENIED	126

typedef struct s_cp
{
	pid_t	pid;
	int		in;
	int		out;
	char	**ep;
	char	**env_paths;
	char	**argv;
	char	*cmd_path;
}	t_cp;

typedef struct s_ctx
{
	char	*infile;
	char	*outfile;
	int		cmd_num;
	char	**cmds;
	int		heredoc;
	char	*limiter;
	int		prev_pipe_to_read;
}	t_ctx;

#endif