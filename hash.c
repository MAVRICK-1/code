//Created by rishi mondal
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_NAME 256
#define TABLE_SIZE 10
typedef struct node
{
    
    char name[MAX_NAME];
    int  age ;

} person;

person *hash_table[TABLE_SIZE];
unsigned int hash(char *name){
    int length = strlen(name);
    int value=0;
    for (int i = 0; i < length; i++)
    {
        value +=name[i];
        value=value*name[i]%TABLE_SIZE;
    }
    return value;
}
void init_hash_table(){
    for(int i =0;i< TABLE_SIZE;i++){
        hash_table[i]=NULL;
    }
}
void print(){
    printf("START\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i]==NULL)
        {
            printf("%d\t---\n",i);
        }
        else{
            printf("%d\t%s\n",i,hash_table[i]->name);
        }
        
    }
    printf("END\n\n\n");
}
int insert_table(person *p){
    if (p==NULL)
    {
        return 0;
    }
    int index = hash(p->name);
    if (hash_table[index]!=NULL)
    {
        return 0;
    }
    hash_table[index]=p;
    return 1;
}
int new_insert_table(person *p){
    if(p==NULL) return 0;
    int index =hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[(index+i)%TABLE_SIZE]==NULL){//&&strcmp(p->name,hash_table[(index+i)%TABLE_SIZE]->name)!=0){
            hash_table[(index+i)%TABLE_SIZE]=p;
            return 1;
        }
        
    }
    return 0;
    
}
person * hash_lookup(char *name){
    int index = hash(name);
    if(hash_table[index]==NULL)
    return NULL;
    return hash_table[index];
}
person *advance_hash_lookup(char *name){
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int key=(index+i)%TABLE_SIZE;
        if (hash_table[key]!=NULL&&strcmp(name,hash_table[key]->name))
        {
            return hash_table[key];
        }
        
    }
    return NULL;
    
    
}
person * hash_deletion(char *name){
    person *tmp;
    int index=hash(name);
    if(hash_table[index]==NULL&& strcmp(name,hash_table[index]->name)==0)
        return NULL;
    tmp=hash_table[index];
    hash_table[index]=NULL;
    return tmp;
}
person * advance_hash_deletion(char *name){
    person *temp;
    int index=hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int key=(index+i)%TABLE_SIZE;
        if (hash_table[key]==NULL&&strcmp(name,hash_table[index]->name)==0)
        {
            return NULL;
        }
    }
    
}
int main(){
    init_hash_table();
   // print();
    person jacob={.name="jacob",.age=27};
    person ruhi={.name="ruhi",.age=45};
    person amri={.name="amrika",.age=69};
    person roy={.name="ruhi",.age=78};
    person mon={.name="acjob",.age=45};
    insert_table(&jacob);
    insert_table(&ruhi);
    insert_table(&amri);
    insert_table(&roy);
    insert_table(&mon);
    print();
    init_hash_table();
    new_insert_table(&jacob);
    new_insert_table(&ruhi);
    new_insert_table(&amri);
    new_insert_table(&roy);
    new_insert_table(&mon);
    print();
    /*person *temp=hash_lookup("ruhi");
    if (temp==NULL)
    {
        printf("not present\n");
    }
    else
    {
        printf("%s is present in table .\n",temp->name);//or temp;
    }
    temp= hash_lookup("george");
    if (temp==NULL)
    {
        printf("not present\n");
    }
    else
    {
        printf("%s is present in table .\n",temp->name);//or temp;
    }
    */
    person *temp=hash_deletion("ruhi");
    print();
    // printf("%d\t",*(hash_table[2]));
    
    // printf("rishi => %u\n",hash("rishi"));
    // printf("priyanka => %u\n",hash("priyanka"));
    // printf("aritra => %u\n",hash("aritra"));
    // printf("anurag => %u\n",hash("anurag"));
}
