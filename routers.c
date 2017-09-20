#include "lem_in.h"

int         find_end(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (!temp->end)
        temp = temp->next;
    return (temp->id);
}

int         passed_vertex(s_lem_in *route, s_lem_in *list)
{
    s_lem_in    *temp;

    temp = route;
    while (temp)
    {
        if (temp->id == list->id)
            return (1);
        temp = temp->next;
    }
    return (0);
}

s_lem_in        *push_to_last(s_lem_in *route, s_lem_in *copy)
{
    s_lem_in    *temp;

    if (!route)
    {
        route = copy;
        route->next = NULL;
        return route;
    }
    temp = route;
    while (temp->next)
        temp = temp->next;
    temp->next = copy;
    temp->next->next = NULL;
    return route;
}

s_lem_in        *add_new_route(s_lem_in *routes, s_lem_in *route)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;
    s_lem_in    *current;
    int         i;

    temp = route;
    temp2 = routes;
    if (temp2)
    {
        while (temp2->next)
            temp2 = temp2->next;
        temp2->next = ft_copy(temp);
        temp2 = temp2->next;
    }
    else
    {
        temp2 = ft_copy(temp);
        routes = temp2;
    }
    temp2->next = NULL;
    current = temp2;
    temp = temp->next;
    i = 1;
    while (temp)
    {
        temp2->route = ft_copy(temp);
        temp2 = temp2->route;
        temp2->next = NULL;
        temp = temp->next;
        i++;
    }
    current->length = i;
    return routes;
}

void    free_last_list(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void    routes_exists(s_lem_in *list, s_lem_in **routes, int end, s_lem_in *route)
{
    route = push_to_last(route, ft_copy(list));
    if (list->id == end)
    {
        *routes = add_new_route(*routes, route);
        return;
    }
    while (list)
    {
        if (!passed_vertex(route, list))
        {
            routes_exists(list->next, routes, end, route);
            free_last_list(route);
        }
        list = list->route;
        if (!list)
            continue;
    }
}

s_lem_in    *end_room(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    temp = list->route;
    while (temp->route)
        temp = temp->route;
    return temp;
}

int         *create_ants_arr(s_lem_in *routes, int ants)
{
    int     *arr;
    int     i;

    i = 0;
    arr = malloc(sizeof(int) * (ants + 1));
    while (i < ants)
    {
        arr[i] = 1;
        i++;
    }
    arr[i] = 0;
    return arr;
}

void        create_routes(s_lem_in *list, int ants)
{
    s_lem_in    *routes;
    s_lem_in    *route;
    s_lem_in    *temp;
    int         *ants_arr;
    int         i;

    routes = NULL;
    route = NULL;
    i = 0;
    routes_exists(list, &routes, find_end(list), route);
    if (!routes)
        error();
    routes = sort_routes(routes);
    routes = filter_crossing_routes(routes);
    while (file_array[i])
    {
        ft_printf("%s\n", file_array[i]);
        i++;
    }
    ft_printf("\n");
    ants_arr = create_ants_arr(routes, ants);
    start_ants(routes, ants_arr, ants);
}