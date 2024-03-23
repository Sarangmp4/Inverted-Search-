#include "header.h"

int search_word( M_node **hash_table, char *word)
{
    int index = 0;

    if(isalpha(word[0])) //checking the first chacter is alphabet
    {
        index = tolower(word[0]) - 97;
    }
    else //not alphabet
    {
        index = 26;
    }

    if(hash_table[index] == NULL) //hash index is empty
    {
        return DATA_NOT_FOUND;
    }
    else
    {
        M_node *mtemp = hash_table[index];
        while( mtemp != NULL ) //traversing through main node
        {
            if( !strcmp(word, mtemp -> word)) //word matching
            {
                printf("The given word %s is present in %d files\n", mtemp -> word, mtemp -> filecount);

                S_node *stemp = mtemp -> slink;
                printf("-----------------------------------------\n");


                while( stemp !=NULL  ) //traversing through sub node
                {
                    printf("%s -> %d\n", stemp -> filename, stemp -> wordcount);
                    stemp = stemp -> slink;
                }
                return SUCCESS;
            }
            mtemp = mtemp -> mlink;
        }
        return DATA_NOT_FOUND;
    }
}