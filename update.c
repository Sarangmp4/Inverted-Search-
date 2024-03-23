#include "header.h"

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
    int option = 0, flag = 0, res = 0;

    char word[20];

    f_name *files = NULL; //file names list


    if(validata_file( argc, argv, &files ) == FAILURE) //calling validation function
    {
        printf("Validation is failure\n");
        return 0;
    }
    else
        printf("Validation of files successfull\n---------------------------------\n");

        //printing valid files
        f_name *temp1= files;

        printf("Valid Files are : ");
        while( temp1  != NULL)
        {
            printf("%s ",temp1->filename);
            temp1=temp1->link;
        }
        printf("\n---------------------------------------");

    M_node *hash_table[27] = {NULL};  //creating hash table

    printf("\n1-->Create\n2-->Display\n3-->Search\n4-->Save\n5-->Update\n6-->Exit\n");
    while(1)
    {
        printf("Enter your choice : ");scanf("%d", &option);
        switch(option)
        {
            case 1:if( flag == 0)
                   {
                       if((res = create_database( &files, hash_table )) == SUCCESS)
                       {
                           flag = 1;
                           printf("Database Creation successfull\n");
                       }
                       else if(res == DATA_NOT_FOUND )
                       {
                           printf("Pass file names through Command line\n");
                       }
                       else
                       {
                           printf("Database creation failure\n");
                       }
                   }
                   else
                       printf("Data is already present in database\n");
                   break;

            case 2: Display_database(hash_table);
                    break;

            case 3: printf("Enter the word to search: ");scanf("%s", word);
                    if(search_word( hash_table, word) == DATA_NOT_FOUND)
                    {
                        printf("Word is not present in file\n");
                    }
                    break;

            case 4: if(flag == 1)
                    {
                        printf("Enter the file name : ");scanf("%s", word);
                        if(strstr(word, ".txt") != NULL)
                        {
                            if(save_database( hash_table , word ) == FAILURE)
                            {
                                printf("Saving database is failure\n");
                            }
                            else
                            {
                                printf("Data base saved succesfully\n");
                            }
                        }
                        else
                            printf("ERROR: Enter .txt file\n");
                    }
                    else
                        printf("Database is empty\n");
                    break;

            case 5: if(flag == 0)
                    {
                        if((res = update_database( hash_table )) == SUCCESS )
                        {
                            printf("Data restored succesfully\n");
                            flag = 1;
                        }
                        else if( res == DATA_NOT_FOUND )
                        {
                            printf("Enter the backup file name containg backup data\n");
                        }
                        else
                        {
                            printf("Restoring database is failed\n");
                        }
                    }
                    else
                        printf("Data is already exist\n");
                    break;

            case 6: return SUCCESS;

            default: printf("Enter the correct option\n");
        }
    }
    }
    else
    {
        printf("Error: Pass command line arguments\n");
    }

}