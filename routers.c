#include "lem_in.h"

int     find_start(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (temp)
    {
        if (temp->start)
            return (temp->id);
        temp = temp->next;
    }
    return NULL;
}

int     find_end(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (temp)
    {
        if (temp->end)
            return (temp->id);
        temp = temp->next;
    }
    return NULL;
}

fill_null(int *array, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        array[i] = NULL;
        i++;
    }
}

find_all_routes(int **routes_matrix, int current, int end, int *route, int i, routes_list *routes)
{
    int     j;

    j = 0;
    route[i] = current;
    if (route[i] == end)
        add_route(routes_matrix, routes);
    while (routes_matrix[current])
    {
        if (!in_array(routes_matrix[current], route))
            find_all_routes(routes_matrix, curent);
    }
}

int     create_routers(s_lem_in *first_list, int **routes_matrix, int ants, int length)
{
    routes_list *routes_list;
    int         *route;
    int         n;
    int         ways;
    int         start;
    int         end;

    routes_list = malloc(sizeof(routes_list));
    start = find_start(first_list);
    routes_list->id = start;
    end = find_end(first_list);
    routes_list->id = end;
    routes_list->ant = 0;
    routes_list->next_route = NULL;
    routes_list->route = NULL;
    route = malloc(sizeof(int) * 1000);
    fill_null(route, 1000);
    n = 2;
    ways = 0;
    find_all_routes(routes_matrix, start, end, route, 0, routes_list);
//    while (ways < ants)
//    {
//        while (!find_route(n, routes_matrix, start, end, route))
//        {
//            if (n > length)
//                return NULL;
//            n++;
//        }
//        add_route(route, routes_list);
//        ways++;
//    }
}