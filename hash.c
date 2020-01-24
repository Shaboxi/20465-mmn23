#include "header.h"
#define BUFSIZE 100


int main(int argc, char **argv)
{
    int i = 1;    
    FILE *fp;
    char buff[BUFSIZE]; /* a buffer to hold what you read in */

    /* handle input */
    while(i < argc)
    {
        printf("\nHandle file number: %d\n", i);

        fp = fopen(argv[i], "r"); /* "r" = open for reading */

        /* loop throw each number in the current input */
        while (fscanf(fp,"%s ",buff)==1)
        {
            printf("%d\n", atoi(buff));
            
        }
            




        

        fclose(fp);  /* close the file */ 

        i++;
    }
        
 
    printf("\n");
    return 0;
}





