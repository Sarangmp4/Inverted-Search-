#include "header.h"
int Display_database(M_node **hash_table)
{
    printf("index\t        word\t          filecount      \tfilename\t    wordcount\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < 27 ; i++)
    {
        if(hash_table[i] != NULL) //hash index not empty
        {

            M_node *mtemp = hash_table[i];
            while( mtemp != NULL ) //traversing thrrough main node
            {
                printf("%d\t\t%-13s\t\t%-5d", i, mtemp -> word, mtemp -> filecount);
                S_node *stemp = mtemp -> slink;
                while( stemp != NULL ) //traversing through sub node
                {
                    printf("\t\t%-10s\t\t%-5d", stemp -> filename, stemp -> wordcount);
                    stemp = stemp -> slink;
                }
                mtemp = mtemp -> mlink;
                printf("\n");
            }
        }
    }
    return SUCCESS;
}