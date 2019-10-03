//
// Created by danny on 03.10.2019.
//

//#include "list.h"

typedef struct     s_list
{
    int            data;
    struct s_list  *next;
}                  t_list;

int        cycle_detector(const t_list *list)//funcion que funciona con solo 15 lineas
{
    const t_list	*slow;
    const t_list	*fast;

    slow = list;//necesitamos tener dos para saber cuando se intersecan, si lo hacen, es un ciclo
    fast = list;
    if (!list)// simple revision de que si existe o no
        return (0);//si no esxiste entonces regresamos cero
    while (fast && fast->next)//debe existir la lista y el puntero a la siguiente lista
    {
        slow = slow->next;//si slow era la primera lista, ahora es igual a la segunda lista
        fast = fast->next->next;//fast ahora es igual a la tercera lista
        if (fast == slow)//tenemos dos diferentes listas, y cuando sean iguales, tenemos un ciclo
            return (1);// y regresamos 1
    }
    return (0);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node4;

    node1 = malloc(sizeof(t_list));
    node2 = malloc(sizeof(t_list));
    node3 = malloc(sizeof(t_list));
    node4 = malloc(sizeof(t_list));

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    printf("%d\n", cycle_detector(node1));
}