#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define BUFSIZE 100
#define NUMSIZE 29

/* define a list of ints */
typedef struct node {
    int val;
    struct node * next;
}node_int;

node_int* hash_table[NUMSIZE];

/* actions on the list */
void push(node_int * head);
void print_list(node_int * head);