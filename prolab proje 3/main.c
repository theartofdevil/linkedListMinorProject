#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct Node{
    char string[50];
    int count;
    struct Node *next;
};struct Node node;
struct Node *sort(struct Node *node,struct Node *linkedList){
    struct Node *iter=linkedList;
    struct Node *temp=linkedList;
   // INSERT TO THE HEAD
    if (iter->count <= node->count) {
        while (temp->next!=node) {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        node->next=iter;
        return node;
    }
    // INSERT THE NODE
    while (node->count < iter->next->count) {
        iter=iter->next;
        // finding where the node will be insert...
    }
    while (temp->next!=node) {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    node->next=iter->next;
    iter->next=node;
    return linkedList;
}
struct Node *newNode(char string[]){
    // the program allocating space for new struct
    struct Node *new_word=(struct Node*)malloc(sizeof(struct Node));
        strcpy(new_word->string, string);
        new_word->count=1;
        new_word->next=NULL;
    return new_word;
}
struct Node *checkWord(char string[],struct Node *linked_list){
    if (linked_list==NULL ) {                     // if the linked list is empty , the program will create a new root
        printf("List is empty. :(  New one is creating...\n");
        return linked_list=newNode(string);
    }
    struct Node *iter=linked_list;
    // checking the string which was sent, if linked list has just a node
    // if the string equals to root->string , increase the root->number
    if (iter->next==NULL) {
        if (strcmp(iter->string, string)==0) {
            iter->count++;
            return  linked_list;
        }
    }
    // if linked list has more nodes
    while (iter->next!=NULL) {
        if (strcmp(iter->string, string)==0) {
            iter->count++;
            linked_list=sort(iter, linked_list);
            return  linked_list;
        }
        else
            iter=iter->next;
    }
   // if the linked list does not include the  string which is sent , the program will add a new node to the end of the list
    // ADDING ELEMENT TO THE END
    struct Node *newElement=newNode(string);
    if (newElement!=NULL) {
        iter->next=newElement;
    }
    return linked_list;
}
int main(){
    struct Node *linked_list;
    linked_list=NULL;
    struct Node *iter_write=(struct Node*)malloc(sizeof(struct Node));
    FILE *file;
    char string[50],letter;
    int i=0;
    if ((file=fopen("text.txt", "r+"))!=NULL) {
        while (!feof(file)) {
            letter=fgetc(file);
            if (letter!=' ') {
                string[i]=letter;
                i++;
            }
            else if (letter==' '){
               linked_list=checkWord(string,linked_list);
                for (int i=0; i<50; i++) {
                    string[i]='\0';
                }
                i=0;
            }
        }
    }
    else{
        printf("file can not be opened...");
    }
    //printing the linked list...
    iter_write=linked_list;
    while (iter_write->next!=NULL) {
        printf("%s    %d   \n",iter_write->string,iter_write->count);
        iter_write=iter_write->next;
    }
    if (iter_write->next==NULL) {
        printf("%s   %d ",iter_write->string,iter_write->count);
    }
}
