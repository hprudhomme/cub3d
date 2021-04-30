/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:59:41 by hprudhom          #+#    #+#             */
/*   Updated: 2021/01/13 14:03:25 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
		ft_memdel((void**)as);
}

// split

static char				**ft_second_malloc(char **tab, char const *s, char c)
{
	int i;
	int x;
	int count;

	x = 0;
	i = 0;
	count = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		count = 0;
		while (s[x] != c && s[x])
		{
			x++;
			count++;
		}
		if (count != 0)
		{
			if (!(tab[i] = malloc(sizeof(char) * (count + 1))))
				return (NULL);
			i++;
		}
	}
	return (tab);
}

static char				**ft_first_malloc(char **tab, char const *s, char c)
{
	int x;
	int count;

	x = 0;
	count = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		while (s[x] != c && s[x])
		{
			if (s[x - 1] == c || x == 0)
				count++;
			x++;
		}
	}
	if (!(tab = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	return (tab);
}

static char				**ft_spliting(char **tab, char const *s, char c)
{
	int		x;
	int		ligne;
	int		col;

	ligne = 0;
	col = 0;
	x = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		col = 0;
		while (s[x] != c && s[x])
		{
			tab[ligne][col++] = s[x++];
			if (s[x] == c || !(s[x]))
			{
				tab[ligne][col] = '\0';
				ligne++;
			}
		}
	}
	tab[ligne] = NULL;
	return (tab);
}

char					**ft_splitt(char const *s, char c)
{
	char	**tab;

	tab = NULL;
	if ((tab = ft_first_malloc(tab, s, c)) == NULL)
		return (NULL);
	if ((tab = ft_second_malloc(tab, s, c)) == NULL)
		return (NULL);
	tab = ft_spliting(tab, s, c);
	// printf("hello\n");
	// printf("******* %s\n", tab[0]);
	// printf("******* %s\n", tab[1]);
	// printf("******* %s\n", tab[2]);
	return (tab);
}


/// cub3d

int 	ft_skip_space(char *s, int start)
{
	int i = start;

	while (s[i] && s[i] == ' ')
		i++;
	return i;
}

int		ft_is_in_flags_list(char *s)
{
	return ((s == "R") || (s == "NO") || (s == "SO") || (s == "WE") || (s == "EA") || (s == "S"));
	// if (s[0] = 'R')
	// 	return 1;
	// return 0;
}

char 	*first_letters(char *s)
{
	char *tmp;

	if (s[0] == 'R')
		return (tmp = "R");
	if (s[0] == 'N' && s[1] == 'O')
		return (tmp = "NO");
	if (s[0] == 'S' && s[1] == 'O')
		return (tmp = "SO");
	if (s[0] == 'W' && s[1] == 'E')
		return (tmp = "WE");
	if (s[0] == 'E' && s[1] == 'A')
		return (tmp = "EA");
	if (s[0] == 'S')
		return (tmp = "S");
	return NULL;
}

t_params	ft_treat_r(char *s, t_params params, char *fl)
{
	params.R = ft_splitt(s, ' ');

	return params;
}

t_params	ft_treat(char *s, char *fl, t_params params)
{
	if (fl == "R")
		params = ft_treat_r(s, params, fl);
	if (fl == "NO")
		params = ft_treat_r(s, params, fl);
	if (fl == "SO")
		params = ft_treat_r(s, params, fl);
	if (fl == "WE")
		params = ft_treat_r(s, params, fl);
	if (fl == "EA")
		params = ft_treat_r(s, params, fl);
	if (fl == "S")
		params = ft_treat_r(s, params, fl);
	return params;
}

t_params 	ft_treat_params(char **s, t_params params)
{	
	// int i = 0;

	// while (s[i])
	// {
	// 	char params_list = ["R", "NO", "SO", "WE", "EA", "S"];
	// 	char *first_letters = first_letters(s);

	// 	if (!(first_letters))
	// 		return NULL;
	// 	if (ft_is_in_flags_list(first_letters))
	// 		params = ft_treat(s[i], first_letters, params);
	// 	i++;
	// }

		// char params_list = ["R", "NO", "SO", "WE", "EA", "S"];
		char *fl;

		// printf("%s\n", s[0]);
		int i = 0;


		// fl = first_letters(s[1]);
		// while (fl[i])
		// {
		// 	printf("++++++ %c\n", fl[i]);
		// 	i++;
		// }
		// printf("***** %d\n", fl == "NO");
		// if (ft_is_in_flags_list(fl))
		// 	params = ft_treat(s[i], fl, params);
		while (s[i])
		{	
			// printf("s[i] = %s\n", s[i]);
			fl = first_letters(s[i]);
			// printf("fl = %s\n", fl);
			if (ft_is_in_flags_list(fl))
				params = ft_treat(s[i], fl, params);
			i++;
		}
	// printf("end\n");
	return params;
}