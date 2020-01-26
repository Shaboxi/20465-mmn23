#include "header.h"

/* update the value (and filename) of a given node */
void push(node_int * node, char* filename)
{
    node_int * current = node;
    
    /* update a node */
    current->next->filename = filename;
    current->next->val = current->next->val + 1;
    current->next->next = NULL;
}

/* print the data */
void print_list(node_int * head, int index)
{
    node_int * current = head;

    if(current->next != NULL)
    {
        current = current->next;
        printf("The value %d: ", index);

        while (current != NULL)
        {
            printf("appears %d time in file %s; ", current->val, current->filename);            
            current = current->next;
        }
        printf("\n");
    }
}





/* push to hash */
void push_to_hash(int index, char* filename)
{
    int newNode = 1; /* set flag, if 1 thin this value not found in this file, if 0 this value is found in this input */
    node_int * nodeToUpdate = hash_table[index];
    
    /* check if this value has a list */
    if(nodeToUpdate->next != NULL)
    {
        while (nodeToUpdate->next != NULL )
        {
            /* if this value already exists in this input file */            
            if(strcmp(nodeToUpdate->next->filename,filename) == 0)
            {                
                push(nodeToUpdate,filename);                   
                newNode = 0;           
            }
                
            nodeToUpdate = nodeToUpdate->next;
            
        }                 
    }

    /* 
    check if need to allocate more memory, 
    since this is the first time this value apperas for this input file 
    */
    if (newNode == 1) {
        nodeToUpdate->next = (node_int *) malloc(sizeof(node_int));            
        push(nodeToUpdate,filename);
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

int main(int argc, char **argv)
{
    int i = 1; /* argv[0] is the program itself, so we need to iterate arguments from 1 */    
    FILE *fp; 
    char buff[BUFSIZE]; /* a buffer to hold the data from the input */
    int k = 0;

    /* no input found */
    if(argc == 1)
    {
        printf("No input files, exit program.\n");
        return 0;
    }

    /* init all the cells in the array */
    init_hash();
    
    /* handle input */
    while(i < argc)
    {
        fp = fopen(argv[i], "r"); /* "r" = open for reading */

        /* loop throw each number in the current input */
        while (fscanf(fp,"%s ",buff)==1)
        {
            push_to_hash(atoi(buff),argv[i]); /* put the value in the right place in the hash */
        }
            
        fclose(fp);  /* close the file */ 

        i++;
    }
    
    printf("\nPRINT LIST \n");
    while (k < NUMSIZE)
    {
        print_list(hash_table[k],k); 
        k++;
    }
    
    printf("\n");
    return 0;
}








