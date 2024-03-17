#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure for file list
typedef struct file
{
  char data[20];
  struct file *link;
}fnode;

//structure for main node
typedef struct main
{
  char word[20];
  int fcount;
  struct main *mlink;
  struct sub *slink;
}mnode;

//structure for subnode
typedef struct sub
{
  char fname[20];
  int wcount;
  struct sub *slink;
}snode;

#define SUCCESS 0
#define FAILURE -1


//function prototypes
int validate(int argc, char *argv[],fnode **flist);


//create(fname,arr);
//display(arr);
//search(arr);
//save(arr);
//update(arr);
