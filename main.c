#include "header.h"

int main(int argc, char *argv[])
{
    fnode *flist = NULL;
    mnode *arr[27] = {NULL};

    if (validate(argc, argv, &flist) == SUCCESS)
    {
        printf("Validation Success\n");
        fnode *temp1= flist;

        printf("Valid Files are : ");
        while( temp1  != NULL)
        {
            printf("%s ",temp1->data);
            temp1=temp1->link;
        }


    }
    else
    {
        printf("Validation Failed\n");
    }
    return 0;
}




// validation function
int validate(int argc, char *argv[], fnode **flist)
{
    if(argc>1)
    {
        for(int i=1; i<argc; i++)
        {
            if( strstr(argv[i],".txt") != NULL )
            {
                FILE *fptr = fopen(argv[i],"r");

                if( fptr == NULL)
                {
                    continue;
                }
                else
                {
                    fseek(fptr,0,SEEK_END);

                    if( ftell(fptr) == 0 )
                    {
                        continue;
                    }
                    else
                    {
                        fnode *new=malloc(sizeof(fnode));
                        new->link=NULL;
                        if( (*flist)==NULL ) //list is empty
                        {
                            strcpy(new->data,argv[i]);
                            new->link=NULL;
                            *flist=new;
                        }
                        else
                        {
                            fnode *temp = *flist;
                            fnode *prev = NULL;
                            while(temp != NULL)
                            {
                                if( !strcmp(argv[i],temp->data))
                                {
                                    printf("Duplicate file is found\n");
                                    return FAILURE;
                                }
                                prev=temp;
                                temp=temp->link;
                            }
                            if(temp==NULL)
                            {
                                fnode *new= malloc(sizeof(fnode));
                                strcpy(new->data,argv[i]);
                                new->link=NULL;
                                prev->link=new;

                            }


                        }
                    }
                }
            }
            else
            {
              continue;
            }
        }
        return SUCCESS;

    }
    else
    {
        return FAILURE;
    }

}