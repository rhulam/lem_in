#include "lem_in.h"

int valid_route(char *line)
{
    int     i;

    i = 0;
    while (isdigit(line[i]))
        i++;
    if (line[i] != '-')
        return (0);
    i++;
    while (isdigit(line[i]))
        i++;
    if (line[i] != '\0')
        return (0);
    return (1);
}

int valid_numeric_line(char *line)
{
    int     i;

    i = 0;
    if (line[i] == '#' || line[i] == 'L' || line[i] == ' ' || line[i] == '\t' || line[i] == '\r')
        return (0);
    while (line[i] != ' ' && line[i] != '\0')
        i++;
    i++;
    while (isdigit(line[i]))
        i++;
    if (line[i] != ' ')
        return (0);
    i++;
    while (isdigit(line[i]))
        i++;
    if (line[i] != '\0')
        return (0);
    return (1);
}

int start_end_count_check(char **file_array)
{
    int     i;
    int     start_count;
    int     end_count;

    i = 0;
    start_count = 0;
    end_count = 0;
    while (file_array[i])
    {
        if (!ft_strcmp(file_array[i], "##start") && file_array[i + 1])
        {
            if (!valid_numeric_line(file_array[i + 1]))
                return (0);
            start_count++;
        }
        else if (!ft_strcmp(file_array[i], "##end") && file_array[i + 1])
        {
            if (!valid_numeric_line(file_array[i + 1]))
                return (0);
            end_count++;
        }
        i++;
    }
    if (start_count == 1 && end_count == 1)
        return (1);
    return (0);
}

int ant_checker(char *first_line)
{
    int     i;

    i = 0;
    while(isdigit(first_line[i]))
        i++;
    if (first_line[i] == '\0')
        return (1);
    return (0);
}

int     line_validator(char *line)
{
    if (line[0] == '#' && line[1] != '#')
        return (1);
    else if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
        return (1);
    else
        if (!valid_numeric_line(line) && !valid_route(line))
            return (0);
    return (1);
}

//
//int start_exists(char **file_array)
//{
//    int     i;
//    int     counter;
//
//    i = 0;
//    counter = 0;
//    while (file_array[i])
//    {
//        if (!ft_strcmp(file_array[i], "##start"))
//            if (valid_numeric_line(file_array[i + 1]))
//                counter++;
//    }
//    if (counter == 1)
//        return (1);
//    return (0);
//}
//
//int end_exists(char **file_array)
//{
//    int     i;
//    int     counter;
//
//    i = 0;
//    counter = 0;
//    while (file_array[i])
//    {
//        if (!ft_strcmp(file_array[i], "##end"))
//            if (valid_numeric_line(file_array[i + 1]))
//                counter++;
//    }
//    if (counter == 1)
//        return (1);
//    return (0);
//}