#include "header.h"

int validata_file(int argc, char *argv[], f_name **files)
{
    for(int i = 1; i < argc; i++)
    {
        if(strstr(argv[i],".txt") != NULL) //checking .txt
        {
            FILE *temp;
            if((temp = fopen(argv[i], "r")) != NULL)  //file exist
            {
                fseek(temp, 0, SEEK_END);
                if(ftell(temp) != 0)            //file is not empty
                {
                    if(insert_to_list(argv[i], files) == FAILURE) //calling insert to list
                    {
                        return FAILURE;
                    }
                }
                else
                    printf("file is empty.\n");
                fclose(temp);
            }
            else
                printf("file not exist.\n");
        }
    }
    return SUCCESS;
}
int insert_to_list( char *argv, f_name **files)
{
    f_name *new = malloc(sizeof(f_name));   //new list
    if(new == NULL)
        return FAILURE;

    strcpy(new -> filename, argv); //copying file name
    new -> link = NULL;  //updating links

    if(*files == NULL) //list is empty
    {
        *files = new;
    }
    else    //list not empty
    {
        f_name *f_temp = *files;
        while(f_temp -> link)
        {
            if(!strcmp(f_temp -> filename, argv))   //filename same
                break;

            f_temp = f_temp -> link;
        }
        if(strcmp(f_temp -> filename, argv))
        {
            f_temp -> link = new;
        }
        else
        {
            //printf("ERROR: %s file is already exist.\n", argv);
            free(new);
        }
    }
    return SUCCESS;
}