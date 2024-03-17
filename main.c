#include "header.h"

int main(int argc, char *argv[])
{
  if (validate(argc, argv) == SUCCESS)
  {
    printf("Validation Success\n");
  }
}

int validate(int argc, char *argv[])
{

  for (int i = 0; i <= argc; i++)
  {
    if ((!strcmp(strstr(argv[i], ".txt"), ".txt")))
    {
      FILE *fptr_file = fopen(argv[i], "r");
      if (fptr_file != NULL)
      {
        fseek(fptr_file, SEEK_END);
        if (ftell(fptr_file) != 0)
        {
          for (int j = i; j <= argc; j++)
          {
            if (!strcmp(argv[i], argv[j]))
            {
              return SUCCESS;
            }
            else
            {
              printf("File exist two times");
              return FAILURE;
            }
          }
        }
        else
          return FAILURE;
      }
      else
        return FAILURE;
    }
  }
}