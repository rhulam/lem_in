#include "lem_in.h"

int         empty(int *arr, int ants)
{
    int     i;

    i = 0;
    while (i < ants)
    {
        if (arr[i])
            return (0);
        i++;
    }
    return (1);
}

s_lem_in    *find_empty(s_lem_in *list)
{
    s_lem_in    *temp;

    temp = list;
    while (temp)
    {
        if (!temp->route->ant)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int         find_route(s_lem_in *routes, int ant, int ants)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;

    temp = routes;
    while (temp)
    {
        if (!temp->route->ant)
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
        else
        {
            temp2 = find_empty(temp);
            if (temp2)
            {
                if (temp2->length - temp->length < ants)
                {
                    temp2->route->ant = ant;
                    ft_printf("L%d-%s ", ant, temp2->route->name);
                    return (0);
                }
            }
            else
                return (0);
        }
        temp = temp->next;
    }
    return (0);
}

int         move_it(s_lem_in *routes, int ant, int ants)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;

    temp = routes;
    while (temp)
    {
        temp2 = temp->route;
        while (temp2)
        {
            if (temp2->ant == ant)
                if (!temp2->route->ant)
                {
                    temp2->ant = 0;
                    ft_printf("L%d-%s ", ant, temp2->route->name);
                    if (!temp2->route->end)
                    {
                        temp2->route->ant = ant;
                        return (0);
                    }
                    else
                        return (1);
                }
            temp2 = temp2->route;
        }
        temp = temp->next;
    }
    return find_route(routes, ant, ants);
}

void        start_ants(s_lem_in *routes, int *ants_arr, int ants)
{
    int     i;
    int     j;

    while (!empty(ants_arr, ants))
    {
        i = 0;
//        j = 0;
//        while (j < ants)
//        {
//            ft_printf("%d ", ants_arr[j]);
//            j++;
//        }
//        ft_printf("\n");
        while (i < ants)
        {
            if (ants_arr[i])
                if (move_it(routes, i + 1, ants))
                    ants_arr[i] = 0;
            i++;
        }
        ft_printf("\n");
    }
}