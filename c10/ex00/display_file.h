/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:34:13 by yeongo            #+#    #+#             */
/*   Updated: 2022/04/23 09:56:13 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <fcntl.h>
# include <unistd.h>

# define NO_ARGS "File name missing.\n"
# define MANY_ARGS "Too many arguments.\n"
# define FAIL_TO_READ "Cannot read file.\n"

# define MAX_BUFF 1024

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	error_message(char *str);
void	init_buffer(char *buffer);
int		ft_display_file(char *path, char *buff);

#endif
