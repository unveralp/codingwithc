#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    struct node *next;
};

struct node *insert(struct node *root,int id){
    if(root == NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->id=id;
        root->next=NULL;
        return root;
    }
    else{
        struct node *iter;
        iter = root;
        while(iter->next!=NULL)
            iter=iter->next;
        iter->next=(struct node*)malloc(sizeof(struct node));
        iter->next->id=id;
        iter->next->next=NULL;
        return root;
    }
};
void print(struct node *root){
    while(root!=NULL){
        printf("%d ",root->id);
        root=root->next;
    }
}

int main()
{
    struct node *root=NULL;
    int id;
    scanf("%d",&id);
    while(id!=-1){
        root=insert(root,id);
        scanf("%d",&id);
    }
    print(root);
    return 0;
}
