#include "header.h"

int save_database( M_node **hash_table , char *file )
{
    FILE *fptr = fopen(file, "w"); //opening the file pointer
    for(int i = 0; i < 27 ; i++)
    {
        if(hash_table[i] != NULL) //if hash index is not null
        {
            M_node *mtemp = hash_table[i];
            while( mtemp != NULL ) //traversing through main node
            {
                //storing details to backup file
                fprintf(fptr, "#%d;%s;%d;", i, mtemp -> word, mtemp -> filecount);
                S_node *stemp = mtemp -> slink;
                while( stemp != NULL ) //traversing through sub node
                {
                    fprintf(fptr, "%s;%d;" , stemp -> filename, stemp -> wordcount);
                    stemp = stemp -> slink;
                }
                fprintf(fptr,"%s","#\n");
                mtemp = mtemp -> mlink;
            }
        }
    }
    return SUCCESS;
}