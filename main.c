#include "get_next_line.h"

// t_params     ft_init_params()
// {
//      t_params params;

//     params.R;
//     params.NO;
//     params.SO;
//     params.WE;
//     params.EA;
//     params.S;
    
//     return (params);
// }

int   main(int ac, char **av)
{
	(void)ac;
	char  *line;
	int   fd1;
    char *buzz[6];
    char **map;

	int x = 0;
    int c  = 0;
    int i = 0;
    int p = 0;
    t_params params;

    // params = ft_init_params();

	fd1 = open(av[1], O_RDONLY);

	while (( c = get_next_line(fd1, &line)) >= 0)
	{
        // printf("------------------------ ligne %d\n", x + 1);
		// printf(" l = %s\n", line);

		x++;
        if (ft_strlen(line) > 4)
        {
            buzz[i] = ft_substr(line, ft_skip_space(line, 0), ft_strlen(line));
            if (ft_is_in_flags_list(first_letters(buzz[i])))
                p++;
            i++;
        }
        if (p == 6)
            break ;
        if (c == 0)
            break ;
	}
    params = ft_treat_params(buzz, params);
    i = 0;
    if (!(map = (char **)malloc(sizeof(char*) * (15))))
		return (0);
    while (( c = get_next_line(fd1, &line)) >= 0)
	{
        if (ft_strlen(line) > 4)
        {   
            if (!(map[i] = malloc(sizeof(char) * (40))))
				return (0);
            map[i] = line;
            i++;
        }
        if (c == 0)
            break ;
    }
    map[i] = NULL;
    
    // if (left_right(map))
    //     printf("buzz\n");
    if (top_bot(map))
        printf("buzz2\n");
    // i = 0;
    // while (map[i])
    // {
    //     printf("--%s\n", map[i]);
    //     i++;
    // }

    // printf("******* %s\n", params.R[1]);
}