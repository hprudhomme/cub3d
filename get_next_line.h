/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:03:50 by hprudhom          #+#    #+#             */
/*   Updated: 2021/01/13 14:04:29 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 8

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef	struct		s_params
{
    char **R;
    char **NO;
    char **SO;
    char **WE;
    char **EA;
    char **S;
}					t_params;

void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
void	ft_memdel(void **ap);
char	*ft_substr(char const *s, unsigned int start, size_t len);


//

int 	ft_skip_space(char *s, int start);
int		ft_is_in_flags_list(char *s);
char 	*first_letters(char *s);

int     left_right(char **map);
int     top_bot(char **map);

t_params 	ft_treat_params(char **s, t_params params);


//

int		get_next_line(int fd, char **line);
#endif
