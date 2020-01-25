#include "header.h"

void push(node_int * node, char* filename)
{
    node_int * current = node;
    
    /* now we can add a new variable */

    current->next->filename = filename;
    current->next->val = current->next->val + 1;
    current->next->next = NULL;

}

void print_list(node_int * head)
{
    node_int * current = head;

    while (current != NULL)
    {
        printf("%d ,  %s\n", current->val, current->filename);
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
void push_to_hash(int index, char* filename)
{
    int newNode = 1;
    node_int * nodeToUpdate = hash_table[index];
    
    /* check if this value has a list */
    if(nodeToUpdate->next != NULL)
    {
        while (nodeToUpdate->next != NULL )
        {
            
            printf("\nstrcmp: %d %d\n", strcmp(nodeToUpdate->next->filename,filename), nodeToUpdate->next->val);
            
            if(strcmp(nodeToUpdate->next->filename,filename) == 0)
            {
                printf("update index %d file %s - %s %d\n", index, filename, nodeToUpdate->next->filename, nodeToUpdate->next->val);
                push(nodeToUpdate,filename);   
                printf("update index %d file %s - %s %d\n", index, filename, nodeToUpdate->next->filename, nodeToUpdate->next->val);
                newNode = 0;           
            }
                
            nodeToUpdate = nodeToUpdate->next;
            
        }                 
    }
     
    if (newNode == 1) {
        nodeToUpdate->next = (node_int *) malloc(sizeof(node_int));            
        push(nodeToUpdate,filename);
    }

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
        printf("\nHandle file name: %s\n", argv[i]);
        fp = fopen(argv[i], "r"); /* "r" = open for reading */

        /* loop throw each number in the current input */
        while (fscanf(fp,"%s ",buff)==1)
        {
            printf("%d\n", atoi(buff));
            
            /*push(hash_table[atoi(buff)],1);*/
            push_to_hash(atoi(buff),argv[i]);
        }
            
        fclose(fp);  /* close the file */ 

        i++;
    }
    
    printf("\nPRINT LIST \n");
    /*push(hash_table[2],4);*/
    print_list(hash_table[7]);
    printf("\n");
    print_list(hash_table[24]);
    printf("\n");
    print_list(hash_table[23]);  

    printf("\n");
    print_list(hash_table[9]);        
 
    printf("\n");
    return 0;
}








