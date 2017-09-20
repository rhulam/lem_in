#include "lem_in.h"

int    find_route_2(int ant, s_lem_in *temp)
{
    ft_printf("L%d-%s ", ant, temp->route->name);
    if (!temp->route->end)
    {
        temp->route->ant = ant;
        return (0);
    }
    else
        return (1);
}

int     find_route_3(int ant, s_lem_in *temp2)
{
    temp2->route->ant = ant;
    ft_printf("L%d-%s ", ant, temp2->route->name);
    return (0);
}