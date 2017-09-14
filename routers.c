#include "lem_in.h"

int     allways = 0;

int         find_end(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (!temp->end)
        temp = temp->next;
    return (temp->id);
}

int         list_length(s_lem_in *list)
{
    s_lem_in    *temp;
    int         i;

    i = 0;
    if (!list)
        return (0);
    temp = list;
    while (temp)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

int         last_room_id(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (temp->next)
        temp = temp->next;
    return temp->id;
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

void        add_new_route(s_lem_in *routes, s_lem_in *route)
{
//    s_lem_in    *temp;
//
//    temp = route;
//    while (temp)
//    {
//        ft_printf("%d ", temp->id);
//        temp = temp->next;
//    }
//    ft_printf("\n");
    allways++;
//    ft_printf("%d\n", allways);
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

void    print_route(s_lem_in *route)
{
    s_lem_in    *temp;

    ft_printf("Current Route: ");
    temp = route;
    while (temp)
    {
        ft_printf("%d ", temp->id);
        temp = temp->next;
    }
    ft_printf("\n");
}

void    routes_exists(s_lem_in *list, s_lem_in *routes, int end, s_lem_in *route)
{
    //sleep(1);
    //ft_printf("\n");
    //ft_printf("Enter: %d\n", list->id);
    route = push_to_last(route, ft_copy(list));
    //print_route(route);
    if (list->id == end)
    {
        //ft_printf("Find!\n");
        add_new_route(routes, route);
        return;
    }
    while (list)
    {
        //ft_printf("In loop: %d\n", list->id);
        if (!passed_vertex(route, list))
        {
            //ft_printf("Pass: %d\n", list->id);
            routes_exists(list->next, routes, end, route);
            free_last_list(route);
        }
        //ft_printf("Last route id: %d\n", last_room_id(route));
        //ft_printf("Before iter: %d\n", list->id);
        list = list->route;
        if (!list)
            continue;
        //ft_printf("After iter: %d\n", list->id);
    }
}

void        create_routes(s_lem_in *list, int ants)
{
    s_lem_in    *routes;
    s_lem_in    *route;

    routes = NULL;
    route = NULL;
    //ft_printf("%d\n", find_end(list));
    routes_exists(list, routes, find_end(list), route);
    ft_printf("%d\n", allways);
}