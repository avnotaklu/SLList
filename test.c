#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SLList.h"
struct test_struct
{
    int id;
    char* key;
};

FILE* write_file = NULL;

void print_struct_member(void* current_node_void)
{
    struct test_struct* current_node = (struct test_struct*)current_node_void;
    fprintf(write_file,"%d\n",(current_node->id));
    fprintf(write_file,"%s\n",(current_node->key));
}

void handle_Input();

int main(int argc,char** argv)
{
    if(argc == 2)
    {
        fclose(stdout);
        write_file = fopen(argv[1],"w");
    }
    else
    {
        write_file = stdout;
    }
    List numbers;
    create_List(&numbers, struct test_struct ,&print_struct_member);
    char keepGoing = 'p';
    while(keepGoing != 'c'){
        handle_Input(&numbers);
        printf("enter 'c' to quit : \n");
        getchar();
        scanf("%c",&keepGoing);
        getchar();
    }
    display_Contents(&numbers,write_file);
}
void handle_Input(List* list)
{
    struct test_struct test_data;
    test_data.key = malloc(sizeof(char)*10);
    printf("\n%s\n%s\n%s\n%s\n%s",
            "'AB' for add at beggining",
            "'AE' for add at end",
            "'DE' for delete at end",
            "'DB' for delete at beggining",
            "Command : "
          );
    char input[2];
    fgets(input,3,stdin);
    //input[2] = '\0';
    if(strcmp("AB",input)==0){
        scanf("%d %s",&test_data.id, test_data.key);
        add_To_Beggining(list,&test_data);
    }
    if(strcmp("AE",input)==0){
        scanf("%d %s",&test_data.id, test_data.key);
        add_To_End(list,&test_data);
    }
    if(strcmp("DB",input)==0){
        delete_At_Beggining(list);
    }
    if(strcmp("DE",input)==0){
        delete_At_End(list);
    }
}
