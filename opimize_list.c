#include "lem_in.h"

int             crossing(s_lem_in *l1, s_lem_in *l2)
{
    s_lem_in    *temp1;
    s_lem_in    *temp2;

    if (!l1 || !l2)
        return (0);
    temp1 = l1->route;
    while (temp1)
    {
        temp2 = l2->route;
        while (temp2)
        {
            if (temp2->id == temp1->id && temp2->route)
                return (1);
            temp2 = temp2->route;
        }
        temp1 = temp1->route;
    }
    return (0);
}

s_lem_in        *filter_crossing_routes(s_lem_in *routes)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;
    s_lem_in    *previous;

    temp = routes;
    while (temp)
    {
        temp2 = temp->next;
        previous = temp;
        while (temp2)
        {
            if (crossing(temp, temp2))
            {
                previous->next = temp2->next;
                temp2->next = NULL;
                free_list(temp2);
                temp2 = previous;
            }
            previous = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return routes;
}

int             the_same(s_lem_in *a, s_lem_in *b)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;

    temp = a;
    temp2 = b;
    while (temp)
    {
        if (temp->id != temp2->id)
            return (0);
        temp = temp->route;
        temp2 = temp2->route;
    }
    return (1);
}

s_lem_in        *sort_routes(s_lem_in *routes)
{
    s_lem_in    *temp;
    s_lem_in    *temp2;
    s_lem_in    *temp3;
    s_lem_in    *previous;
    s_lem_in    *previous2;

    temp = routes;
    previous = NULL;
    while (temp)
    {
        temp2 = temp->next;
        previous2 = temp;
        while (temp2)
        {
            if (temp->length > temp2->length)
            {
                if (previous)
                    previous->next = temp2;
                else
                    routes = temp2;

                temp3 = temp2->next;

                if (!the_same(temp2, temp->next))
                    temp2->next = temp->next;
                else
                    temp2->next = temp;

                previous2->next = temp;
                temp->next = temp3;

                temp3 = temp2;
                temp2 = temp;
                temp = temp3;

            }
            previous2 = temp2;
            temp2 = temp2->next;
        }
        previous = temp;
        temp = temp->next;
    }
    return routes;
}