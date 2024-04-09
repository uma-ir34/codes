#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 50

typedef struct node
{
    char *key;
    int value;
}node;

typedef struct Hashing
{
    node* table[size];
    int count;
}Hashing;

node * createnode(char *key,int value)
{
    node * newnode=(node*) malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory allocation failure");
    }
    newnode->key= strdup(key);
    newnode->value= value;
    return newnode;
}

int hash(char *key)
{
    int hash=0;
    for(int i=0;key[i]!='\0';i++)
    {
        hash+=key[i];
    }
    return hash % size;
}
void insert( Hashing *h,char * key,int value)
{
    int index=hash(key);
    int i= index;
    while(h->table[i]!=NULL){
        i =(i+1)% size;
        if(i==index)
        {
            printf("The table is full,unable to insert");
            return;
        }
    }
    h->table[i]=createnode(key ,value);
    h->count++;
}
int search(Hashing *h,char* key)
{
    int index=hash(key);
    int i= index;
    while (h->table[i]!=0)
    {
        if(strcmp(h->table[i]->key,key)==0)
        {
            return h->table[i]->value;
        }
        i=(i+1)%size;
        if(i==index)
        {
            break;
        }
    }
    return -1;

}

int main()
{
    Hashing h;

    for(int i=0;i<size;i++)
    {
        h.table[i]=NULL;
    }
    h.count=0;

    char key[50];
    int value;
    int i;
    
    printf("Enter the key:");
    scanf("%s",key);
    printf("Enter the value :");
    scanf("%d",&value);
    insert(&h,key,value);

    printf("\n hashtable\n");
    if(h.table[i]!=NULL)
    {
        printf("Index %d : key=%s ,value=%d\n",i,h.table[i]->key,h.table[i]->value);
    }

    printf("Enter the search key");
    scanf("%s",key);
    int result=search(&h,key);
    if(result!=-1)
    {
        printf("value for key%s: %d\n",key,result);
    }
    else{
        printf("key not found");
    }
    return 0;
}







