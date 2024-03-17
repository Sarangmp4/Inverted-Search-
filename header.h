#include <stdio.h>

typedef struct file
{
  char data[20];
  struct file *link;
}fnode;
typedef struct main
{
  char word[20];
  int fcount;
  struct main *mlink;
  struct sub *slink;
}mnode;
typedef struct sub
{
  char fname[20];
  int wcount;
  struct sub *slink;
}snode;

#define SUCCESS 0
#define FAILURE -1


//function prototype
int validate(int argc, char *argv[]);
