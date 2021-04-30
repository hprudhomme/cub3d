#include <stdio.h>

int     left_right(char **map)
{   
    int i = 0;
    int j = 0;
    int f = 0;
    int l = 0;
    int len = 0;;
    while (map[i])
    {
        i++;
        len++;
    }
    printf("len = %d\n", len);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && map[i][j] == ' ')
            j++;
        if (map[i][j] == '1')
            f++;
        while (map[i][j] && map[i][j] != ' ')
            j++;
        if (map[i][j - 1] == '1')
            l++;
        i++;
    }
    printf("l = %d et f = %d\n", l, f);
    if (l == len && f == len)
        return 1;
    else
        return 0;
}

int     top_bot(char **map)
{
    int i = 0;
    int j = 0;
    int f = 0;
    int l = 0;
    int len = 0;
    int max_len = 0;

    while (map[i])
    {
        j = 0;
        len = 0;
        while (map[i][j])
        {
           j++;
           len++;
        }
        if (len > max_len)
            max_len = len;
        i++;
    }

    j = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
           j++;
        }
        while (j != max_len)
        {
            map[i][j] = ' ';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    // int i = 0;
    // while (map[i])
    // {
    //     printf("--%s\n", map[i]);
    //     i++;
    // }

    j = 0;
    i = 0;

    while (map[i][j])
    {   
        printf("*******\n");
        i = 0;
        while (map[i][j] && map[i][j] == ' ')
            i++;
        if (map[i][j] == '1')
            f++;
        while (map[i][j] && (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N') || map[i][j] == '2')
        {
            i++;
            if (i == 14)
                break ;
        }
        if (map[i - 1][j] == '1')
        {
            printf("i = %d et j = %d\n", i, j);
            l++;
        }
        i = 0;
        j++;
    }
    printf("l = %d et f = %d\n", l, f);
    if (l == max_len && f == max_len)
        return 1;
    else
        return 0;
}