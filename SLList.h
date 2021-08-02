#ifndef SLLIST_H
#define SLLIST_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define create_List(x,y,z) _create_List(x,sizeof(y),z)

struct node{
    void* data;
    struct node* next;
};
typedef struct
{
    struct node* _first;
    struct node* _secondLast ;
    int size;
    void (*_print_func)( void * );
}List;

void add_To_End         ( List* list , void* inte ); 
void add_To_Beggining   ( List* list , void* inte );
void delete_At_End      ( List* list );
void delete_At_Beggining( List* list );
void _create_List        ( List* list , int size , void (*_print_func)(void *list_data));
void display_Contents   (const List* list ,FILE* file);

#endif
