#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2

typedef struct node
{
    char filename[30];
    struct node *link;
} f_name;

typedef struct sub_n
{
    int wordcount;
    char filename[30];
    struct sub_n *slink;

}S_node;
typedef struct main_n
{
    char word[20];
    int filecount;
    struct sub_n *slink;
    struct main_n *mlink;
}M_node;

// validation prototype
int validata_file(int argc, char *argv[], f_name **files);

int insert_to_list( char *argv, f_name **);

// create function
int create_database( f_name **files, M_node **hash_table );

// Display function

int Display_database(M_node **hash_table);

// search word
int search_word( M_node **hash_table, char *word);

// save database
int save_database( M_node **hash_table , char *file );

//update database
int update_database( M_node **hash_table );
int backup_validate( char *file );