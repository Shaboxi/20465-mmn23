#include "header.h"



void push(node_int * head, int val)
{
    node_int * current = head;
    

    while (current->next != NULL)
    {
        current = current->next;
    }
        
    /* now we can add a new variable */
    current->next = (node_int *) malloc(sizeof(node_int));
    current->next->val = val;
    current->next->next = NULL;

    
    
}

void print_list(node_int * head)
{
    node_int * current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main(int argc, char **argv)
{
    int i = 1; /* argv[0] is the program itself, so we need to iterate arguments from 1 */    
    FILE *fp; 
    char buff[BUFSIZE]; /* a buffer to hold the data from the input */
    node_int * head = (node_int *) malloc(sizeof(node_int));
    node_int hash_table[29];


    /* handle input */
    while(i < argc)
    {
        printf("\nHandle file number: %d\n", i);

        fp = fopen(argv[i], "r"); /* "r" = open for reading */

        /* loop throw each number in the current input */
        while (fscanf(fp,"%s ",buff)==1)
        {
            printf("%d\n", atoi(buff));
            
            /*push(hash_table[atoi(buff)],1);*/
        }
            
        fclose(fp);  /* close the file */ 

        i++;
    }
    
    printf("\n PRINT LIST \n");
    push(hash_table[1],1);
    print_list(hash_table[1]);        
 
    printf("\n");
    return 0;
}





