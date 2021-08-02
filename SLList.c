#include "SLList.h"

void display_Contents(const List* list,FILE* write_file){
    if(list->_print_func == NULL)
    {
        printf("list doesn't have a print function");
        return;
    }
    struct node* tmp = list->_first;
    while(tmp != NULL)
    {
        list->_print_func(tmp->data);
        tmp = tmp->next;
    }
}
void _create_List(List* list , int size , void (*_print_func)(void *list_data))
{
    list->_first               = NULL;
    list->_secondLast          = NULL;
    list->size                = size;
    list->_print_func         = _print_func;
}
void add_To_End(List* list , void* src )
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(list->_first == NULL)
    {
        add_To_Beggining(list,src);// this will make _secondLast and _first same element in this case
        return ;
    }
    else
    if(list->_secondLast->next == NULL)// If last is null set last to new_node
    {
        new_node->data = malloc(list->size);
        memcpy(new_node->data ,src,list->size);

        if(list->_secondLast != list->_first)
        {
            list->_secondLast->next        = new_node;
            list->_secondLast->next->next  = NULL;
        }
        else
        {
            list->_secondLast              = new_node;
            list->_secondLast->next        = NULL;
            list->_first->next             = list->_secondLast;
        }
    }
    else                              // Else set the next of last to new_node
    {
        new_node->data = malloc(list->size);
        memcpy(new_node->data,src,list->size);
        list->_secondLast                   = list->_secondLast->next; // update _secondLast
        list->_secondLast->next             = new_node; // put what just allocated
        list->_secondLast->next->next       = NULL; // this should always be null
    }
}
void add_To_Beggining(List* list , void* src)
{                                
    printf("Adding at the Beggining\n");
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("%p",new_node);
    fflush(stdout);
    new_node->data = malloc(list->size);
    memcpy(new_node->data,src,list->size);
    //new_node->next = NULL;
    printf("Enter any Integer : ");
    if(list->_secondLast == NULL)
    {
        list->_secondLast             = new_node;
        list->_secondLast->next       = NULL;
    }
    struct node* tmp = list->_first;
    list->_first = new_node;
    list->_first->next = tmp;
}
void delete_At_Beggining(List* list)//Half tested 
{
    if(list->_first == NULL)
    {
        fprintf(stdout,"Out of Index");
        return;
    }
    printf("Deleting at the Beggining\n");
    struct node* tmp = (list->_first);
    if(tmp == list->_secondLast) // both _first and _secondLast are same and size of list is 1 or 2
    {
        list->_secondLast       = list->_secondLast->next;
    }
    list->_first = (list->_first)->next;
    free(tmp);
}
void delete_At_End(List* list)
{
    if(list->_first == NULL)
    {
        fprintf(stdout,"Out of Index");
        return;
    }
    printf("Deleting at the End\n");
    if(list->_secondLast->next != NULL)
    {
        free(list->_secondLast->next);   // not updating _secondLast so _secondLast is last now

        list->_secondLast->next = NULL;
        return;
    }
    struct node* to_delete =  list->_first;
    /* Temp contains : 
       The address of the element to be deleted 
       always free only to_delete */
    struct node* third_last = to_delete; 
    /* TempThirdLast contains :
     * _first element when sizeoflist is 1 , 2 , 3
     * and Third last element when sizeoflist of list is larger */
    int count = 1;
    while((to_delete)->next != NULL)
    {
        to_delete = (to_delete)->next;
        count++;
    }
    for( ; count > 2 ; count-- )
    {
        third_last = (third_last)->next;
    }
    if(list->_secondLast ==  list->_first)
    /* if size is one list is deleted here and func returns */
    {
        list->_first      = NULL;
        list->_secondLast = NULL;
        free(to_delete);  // This frees the only remaining element of the list
        return;
    }

    list->_secondLast = (third_last); // What happens when size is 3 then _secondLast will become equal to _first this shouldn't happen instead it should be _first->next

    if(list->_secondLast->next == to_delete)
    {
        list->_secondLast->next = NULL;
        if(list->_first->next == to_delete)
        {
            list->_first->next = NULL;
        }
    }
    else
        {
            list->_secondLast->next->next = NULL;
            list->_secondLast = list->_secondLast->next;
        }
    free(to_delete);
}
