#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedList.h"

struct node ** findBigger(struct node ** head)
{
    struct node ** ptrMaior = head;
    
    if(!head || !(*head)) return NULL;
    
    while (*head)
    {
        if((*head)->data > (*ptrMaior)->data)
        {
            ptrMaior = head;
        }
        head = &((*head)->next);
    }
    
    return ptrMaior;
}

struct node ** findSmallest(struct node ** head)
{
    struct node ** ptrMenor = head;
    
    if(!head || !(*head)) return NULL;
    
    while (*head)
    {
        if((*head)->data < (*ptrMenor)->data)
        {
            ptrMenor = head;
        }
        head = &((*head)->next);
    }
    
    return ptrMenor;
}

void orderListAsc(struct node ** head)
{
    struct node *ordered = NULL, **last = &ordered, **smallest;

    while((smallest = findSmallest(head)) != NULL)
    {
        if((smallest) && (*smallest))
        {
            *last = *smallest;
            *smallest = (*smallest)->next;
            last = &((*last)->next);
        }
    };
    *head = ordered;
}

void orderListDesc(struct node ** head)
{
    struct node *ordered = NULL, **last = &ordered, **biggest;

    while((biggest = findBigger(head)) != NULL)
    {
        if((biggest) && (*biggest))
        {
            *last = *biggest;
            *biggest = (*biggest)->next;
            last = &((*last)->next);
        }
    };
    *head = ordered;
}


int put(struct node* *head, int input)
{
    struct node *var;
    var = NULL;
    if (*head == NULL)
    {
        var = (struct node *) malloc(sizeof (struct node));
        if (var == NULL) return (EXIT_FAILURE);
        var->data = input;
        var->next = NULL;
        *head = var;

    }
    else
    {
        var = *head;
        while ((var->next != NULL))
        {
            var = var->next;

        }
        var->next = (struct node *) malloc(sizeof (struct node));
        if (var->next == NULL) return (EXIT_FAILURE);
        var->next->data = input;
        var->next->next = NULL;
    }
    return (EXIT_SUCCESS);
}

void list(struct node* *head)
{
    int cont = 0;
    struct node * item = NULL;

    if(head) item = *head;
    
    printf("-------------------- PRINT LIST --------------------\n\n");
    while (item)
    {
        printf("+-----------------------------------+\n");
        printf("|#%-4d @ %-27p|\n", ++cont, item);
        printf("+-Data-----------+-Next-------------+\n");
        printf("|%16d|%18p|\n", item->data, item->next);
        printf("+----------------+------------------+\n\n");
        item = item->next;
    }
    if(!cont) printf("Lista vazia.\n\n");
    printf("--------------------- END LIST ---------------------\n\n");
    fflush(stdout);
}

void removePos(struct node** head, int pos)
{
    struct node * aux = *head, *toDel;
    int i;
    for(i=1; i<pos; i++)
        aux = aux->next;
    if(pos == 1)
        free(aux);
    else
    {
        toDel = aux->next;
        aux->next = toDel->next;
        free(toDel);
    }
   
}


int clean(struct node* *head){
    struct node *temp;
    struct node *next;
    next = NULL;
    temp = *head;
    if((*head) == NULL) return EXIT_FAILURE;
    while(temp->next)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
    return EXIT_SUCCESS;
}

int getNumber(char *str){
    
    char* aux;
    aux = strchr(str, ' ');
    return atoi(++aux);
}


void getPos(struct node** head,int pos)
{
    struct node* aux = *head;
    int i;
    for(i=0; i < pos; i++)
    {
        if(!aux->next) return;
        aux = aux->next;
    }
    if(pos)
    {
        printf("+-----------------------------------+\n");
        printf("|#%-4d @ %-27p|\n", pos, aux);
        printf("+-Data-----------+-Next-------------+\n");
        printf("|%16d|%18p|\n", aux->data, aux->next);
        printf("+----------------+------------------+\n\n");
    }
    
}

void getLast(struct node **head)
{
    struct node * aux = *head;
    while(aux->next)
        aux = aux->next;
    if(aux)
    {
        printf("+-----------------------------------+\n");
        printf("|#%-s @ %-27p|\n", "last", aux);
        printf("+-Data-----------+-Next-------------+\n");
        printf("|%16d|%18p|\n", aux->data, aux->next);
        printf("+----------------+------------------+\n\n");
    }
}

void getFirst(struct node **head)
{
    struct node* aux = *head;
    if(aux)
    {
        printf("+-----------------------------------+\n");
        printf("|#%-s @ %-27p|\n", "last", aux);
        printf("+-Data-----------+-Next-------------+\n");
        printf("|%16d|%18p|\n", aux->data, aux->next);
        printf("+----------------+------------------+\n\n");
    }
}
