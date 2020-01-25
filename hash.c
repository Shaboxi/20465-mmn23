#include "header.h"

void push(node_int * head)
{
    node_int * current = head;
    

    while (current->next != NULL)
    {
        current = current->next;
    }
        
    /* now we can add a new variable */
    current->next = (node_int *) malloc(sizeof(node_int));
    current->next->val = 1;
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

/* declare the array */
node_int* hash_table[NUMSIZE];

/* init each list (first node) in the array */
void init_hash()
{   
    int i=0;
    while (i<NUMSIZE)
    {
        hash_table[i] = (node_int *) malloc(sizeof(node_int));
        i++;
    }
    
}

/* push to hash */
void push_to_hash(int index, int argumentNumber)
{
    int i = 0;
    node_int * nodeToUpdate = hash_table[index];
    /*node_int * current = nodeToUpdate;*/

        
    while (nodeToUpdate->next != NULL && i != argumentNumber)
    {
        nodeToUpdate = nodeToUpdate->next;
        i++;
    }   

    push(nodeToUpdate);

}

int main(int argc, char **argv)
{
    int i = 1; /* argv[0] is the program itself, so we need to iterate arguments from 1 */    
    FILE *fp; 
    char buff[BUFSIZE]; /* a buffer to hold the data from the input */
    

    init_hash(hash_table);
    


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
            push_to_hash(atoi(buff),i);
        }
            
        fclose(fp);  /* close the file */ 

        i++;
    }
    
    printf("\nPRINT LIST \n");
    /*push(hash_table[2],4);*/
    print_list(hash_table[7]);        
 
    printf("\n");
    return 0;
}








