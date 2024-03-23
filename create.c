int create(mnode *arr[], fnode *flist)
{
    mnode *mlist = NULL;     //main node
    snode *slist = NULL;    //subnode

    int real_fcount=1;
    int real_wcount=1;

    int key_index;

    fnode *temp = flist;
    while( temp != NULL)
    {
        FILE *fptr = fopen(temp->data,"r");  //file opening

        if(fptr==NULL)
        {
            return FAILURE;
        }

        //finding index
        char word[20];

        while(fscanf(fptr,"%s",word) != EOF)
        {

            if( isalpha(word[0] )!= 0 )
            {
                key_index= ( tolower(word[0]) - 97 );
            }
            else
            {
                key_index=26;
            }

            if(arr[key_index].link ==NULL )   //index is null
            {

                //creating new main node

                mnode *m_new= malloc(sizeof(mnode));

                //creating new sub node

                snode *s_new=malloc(sizeof(mnode));


                arr[key_index].link= m_new;  //updating link with index
                mlist=m_new;

                m_new->fcount= real_fcount;            //initialising file count
                s_new->wcount= real_wcount;           //initialising word count

                strcpy(m_new->wname,word);  //copying word
                strcpy(s_name->fname,temp->data);  //copying filenmae

                m_new->mlink=NULL;
                s_new->slink=NULL;    //link initially NULL

                m_new.sublink=s_new;  //main node sub node linking

            }
            else  //index not null
            {
                if(strcmp (mlist.wname,word) !=0 )  //word not exist not match
                {
                    mnode *temp1=mlist;
                    mnode *prev=NULL;

                    while(temp1 != NULL)
                    {
                        prev=temp1;
                        temp=temp->mlink;
                    }

                    //creating new nodes
                    mnode *m_new=malloc(sizeof(mnode));
                    snode *s_new=malloc(sizeof(snode));

                    //updaing data

                    strcpy(m_new->wname,word);
                    strcpy(s_new->fname,temp->data);

                    //updating count
                    real_fcount++;
                    m_new->fcount=real_fcount;
                    s_new->wcount=real_wcount;

                    //updating links
                    m_new->mlink=NULL;
                    s_new->slink=NULL;
                    m_new->sublink=s_new;

                    prev->mlink=m_new;



                }
                else  //word is exist
                {
                    mnode *temp2 = mlist;

                    while(temp2 != NULL) //traversing
                    {
                        if(temp2->wname == word)
                        {
                            snode s_temp= temp2->sublink;

                            snode s_prev= NULL;

                            while(s_temp != NULL)
                            {
                                if( strcmp(s_temp->fname,temp->data)==0)
                                {
                                    real_wcount++;
                                    s_temp->wcount=real_wcount;
                                    break;
                                }
                                s_prev=s_temp;
                                s_temp=s_temp->slink;
                            }
                            if(s_temp==NULL)
                            {
                                snode *s_new=malloc(sizeof(snode));

                                s_new->slink=NULL;
                                s_prev->slink=s_new;

                                s_new->wcount=1;
                                strcpy(s_new->fname,temp->data);

                            }
                        }

                    }


                }

            }



        }






    }
}
