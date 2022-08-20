#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int data;
};

int pop(struct node *root){
    if(root == NULL){
        printf("stack is empty\n");
        return -1;
    }
    if(root->next == NULL){
            int value=root->data;
            free(root);
            return value;
        }
       struct node *iter;
        iter=root;
        while(iter->next->next!=NULL){
            iter=iter->next;
        }
        struct node *temp=iter->next;
        int value=temp->data;
        iter->next=NULL;
        free(temp);
        return value;
}
struct node *push(struct node *root,int data){
    if(root == NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->next=NULL;
        return root;
    }
        struct node *iter;
        iter=root;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        iter->next=temp;
        return root;
}

void print(struct node *root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}

int main()
{
    struct node *root=NULL;
    root=push(root,10);
    root=push(root,20);
    printf("%d ",pop(root));
    printf("%d ",pop(root));
    return 0;
}
