/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:34:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/19 02:16:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

// static int	here_doc_fd(char *limiter);
// static char	*get_here_doc_input(char *limiter);

char	*here_doc(int i, t_ctx ctx, t_cp *cp)
{
	(void)i;
	(void)ctx;
	(void)cp;
	// if (i == 0)
	// {
	// 	if (ctx->cp.in != -1)
	// 		close(ctx->cp.in);
	// 	ctx->cp.in = here_doc_fd(ctx->limiter);
	// 	if (ctx->cp.in == -1)
	// 		finish_child_process(&ctx->cp, "here_doc");
	// }
	// else if (i == ctx->cmd_num - 1)
	// {
	// 	if (ctx->cp.out != -1)
	// 		close(ctx->cp.out);
	// 	ctx->cp.out = open(ctx->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	// 	if (ctx->cp.out < 0)
	// 		finish_child_process(&ctx->cp, ctx->outfile);
	// }
	return (NULL);
}

// static int	here_doc_fd(char *limiter)
// {
// 	int		tmp_fd;
// 	char	*input;

// 	tmp_fd = open("tmp_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (tmp_fd < 0)
// 		return (-1);
// 	input = get_here_doc_input(limiter);
// 	if (!input)
// 		return (close(tmp_fd), -1);
// 	ft_putstr_fd(input, tmp_fd);
// 	free(input);
// 	close(tmp_fd);
// 	tmp_fd = open("tmp_file", O_RDONLY);
// 	if (tmp_fd < 0)
// 		return (-1);
// 	unlink("tmp_file");
// 	return (tmp_fd);
// }

// static char	*get_here_doc_input(char *limiter)
// {
// 	char	*result;
// 	char	*line;
// 	char	*tmp;
// 	size_t	len;

// 	len = ft_strlen(limiter);
// 	result = ft_strdup("");
// 	while (1)
// 	{
// 		write(1, "heredoc> ", 9);
// 		line = get_next_line(STDIN_FILENO);
// 		if (!line)
// 			break ;
// 		if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
// 		{
// 			free(line);
// 			break ;
// 		}
// 		tmp = result;
// 		result = ft_strjoin(tmp, line);
// 		free(tmp);
// 		free(line);
// 	}
// 	return (result);
// }
