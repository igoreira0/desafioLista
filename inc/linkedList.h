/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   struct.h
 * Author: igor
 *
 * Created on 4 de Setembro de 2020, 18:39
 */

#ifndef STRUCT_H
#define STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

struct node
{
    int data;
    struct node *next;
};
int put(struct node* *head, int input);

void list(struct node* *head);

int getNumber(char *str);

void list(struct node* *head);

void getPos(struct node** head,int pos);

void getLast(struct node **head);

void getFirst(struct node **head);

void removePos(struct node** head, int pos);

void orderListDesc(struct node ** head);

void orderListAsc(struct node ** head);





#ifdef __cplusplus
}
#endif

#endif /* STRUCT_H */

