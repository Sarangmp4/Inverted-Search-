#include "header.h"

int create_database( f_name **files, M_node **hash_table )
{
    f_name *ftemp = *files;
    if(ftemp == NULL)
        return DATA_NOT_FOUND;

    while(ftemp != NULL) //loop for accessing files from the slist
    {
        FILE *fptr = fopen(ftemp -> filename , "r"); //file open
        char word[20];
        while(fscanf(fptr, "%s", word) != EOF)  //scaning word from array one by one
        {
            int index = 0;
            if(isalpha(word[0]))         //condition to check wheather the given word starts with alphabet
                index = tolower(word[0]) - 97;  //finding index
            else
                index = 26;              //default index if it is not alphabet


            if(hash_table[index] == NULL)
            {
                //creating sub node
                S_node *snew = malloc(sizeof(S_node));
                if(snew == NULL)
                    return FAILURE;

                strcpy(snew -> filename, ftemp -> filename); //copying file name
                snew -> wordcount = 1;  //initialsing wordcount
                snew -> slink = NULL;   //updating link

                //creating main node
                M_node *mnew = malloc(sizeof(M_node));
                if(mnew == NULL)
                    return FAILURE;

                //updating main node values
                strcpy(mnew -> word, word);
                mnew -> filecount = 1;
                mnew -> mlink = NULL;

                mnew -> slink = snew; //update main node sublink with sub node

                hash_table[index] = mnew; //update hash_table with main node
            }
            else  //main node exist
            {
                M_node *mprev = NULL;
                M_node *mtemp = hash_table[index];

                while( mtemp != NULL ) //traversing through sub node
                {
                    if(!strcmp(mtemp -> word, word)) //if word is matching
                    {
                        //creating subnode
                        S_node *sprev = NULL;
                        S_node *stemp = mtemp -> slink;

                        while( stemp != NULL ) //traversing through main node
                        {
                            if(!strcmp(stemp -> filename, ftemp -> filename)) //if filename same
                            {
                                ++stemp -> wordcount; //increasing wordcount
                                break;
                            }
                            sprev = stemp;
                            stemp = stemp -> slink;
                        }
                        if(stemp == NULL) //word is not matching
                        {
                            S_node *snew = malloc(sizeof(S_node)); //creating new subnode
                            if(snew == NULL)
                                return FAILURE;

                            //updating values
                            strcpy(snew -> filename, ftemp -> filename);
                            snew -> wordcount = 1;
                            snew -> slink = NULL;
                            sprev -> slink = snew;
                            ++mtemp -> filecount;
                        }
                        break;
                    }
                    mprev = mtemp;
                    mtemp = mtemp -> mlink;
                }
                if(mtemp == NULL) // word not existing
                {
                    //creating sub node
                    S_node *snew = malloc(sizeof(S_node));
                    if(snew == NULL)
                        return FAILURE;

                    strcpy(snew -> filename, ftemp -> filename);
                    snew -> wordcount = 1;
                    snew -> slink = NULL;

                    //creating main node
                    M_node *mnew = malloc(sizeof(M_node));
                    if(mnew == NULL)
                        return FAILURE;

                    strcpy(mnew -> word, word); //main node word
                    mnew -> filecount = 1;
                    mnew -> mlink = NULL;

                    mnew -> slink = snew; //update main node siblink with sub node

                    mprev -> mlink = mnew; // updating main link
                }
            }
        }
        ftemp = ftemp -> link;
    }
}