#include "header.h"

int update_database( M_node **hash_table )
{
    char file[20];
    printf("Enter the backup file name: ");scanf("%s", file);



    if((backup_validate( file )) == FAILURE) // validate backup file calling function
    {
        return FAILURE;
    }

    else if(backup_validate(file) == DATA_NOT_FOUND) //filename not matching
    {
        return DATA_NOT_FOUND;
    }

    //opening file
    FILE *fptr = fopen( file ,"r" );
    char str[30];

    while(fscanf(fptr,"%s", str) != EOF)
    {
        int index = atoi( strtok(str,"#;")); //getting index value

        M_node *mnew = malloc(sizeof(M_node));
        if( mnew == NULL )
        {
            return FAILURE;
        }
        //updating main node values
        strcpy(mnew -> word, strtok(NULL, "#;"));
        mnew -> filecount = atoi(strtok(NULL, "#;"));
        mnew -> mlink = NULL;


        if( hash_table[index] == NULL ) //if hash index is null
        {
            hash_table[index] = mnew;
        }
        else //not null
        {
            M_node *mtemp = hash_table[index];
            while(mtemp -> mlink != NULL) //traversing through main node
            {
                mtemp = mtemp -> mlink;
            }

            mtemp -> mlink = mnew;
        }

        for(int i = 1 ; i <= mnew -> filecount ; i++)
        {
            //creating subnode
            S_node *snew = malloc(sizeof(S_node));

            strcpy( snew -> filename, strtok(NULL, "#;"));
            snew -> wordcount = atoi(strtok(NULL, "#;"));
            snew -> slink = NULL;
            if(i == 1) //sub node at first time
            {
                mnew -> slink = snew;
            }
            else
            {
                S_node *stemp = mnew -> slink;
                while( stemp -> slink != NULL ) //traversing through subnode
                {
                    stemp = stemp -> slink;
                }
                stemp -> slink = snew;
            }
        }
    }
    return SUCCESS;
}
int backup_validate( char *file )
{
    if(strstr(file, ".txt") == NULL) //checking .txt format
    {
        return FAILURE;
    }

    FILE *fptr = fopen( file ,"r" ); //opening file
    if(fptr == NULL) //checking file is present
    {
        return DATA_NOT_FOUND;
    }

    //checking file is empty or not
    fseek(fptr, 0, SEEK_END);

    if(ftell(fptr) != 0)
    {
        char ch;
        fseek(fptr, 0 , SEEK_SET);

        if((ch = fgetc(fptr)) == '#') //checking first character is #
        {
            fseek(fptr, -2 , SEEK_END);
            ch = fgetc(fptr);

            if(ch != '#') //checking last character is #
            {
                return DATA_NOT_FOUND;
            }
        }
        else
        {
            return DATA_NOT_FOUND;
        }
        fclose(fptr);
    }
    else  //empty file
    {
        printf("File is empty\n");
        return FAILURE;
    }
}