#include "lem_in.h"

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
                //ft_printf("First: %d\nSecond: %d\n\n", temp->length, temp2->length);
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