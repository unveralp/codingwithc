#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    struct node *next;
};

void addLast(struct node **head, int val)
{
    struct node *newNode =(struct node*)malloc(sizeof(struct node));
    newNode->id = val;
    newNode->next = NULL;

    if(*head == NULL)
         *head = newNode;
    else
    {
        struct node *lastNode = *head;
        while(lastNode->next != NULL)//son elemaný bulmak için son elemanýn nextine bakmamýz lazým!
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;//son elemaný buldun onun nextine yeni kutucuðu ekle!
    }

}
void print(struct node *root){
    struct node *temp=root;
    while(temp!=NULL){
        printf("%d ",temp->id);
        temp=temp->next;
    }
}

int main()
{
    struct node *root=NULL;
    for(int i=1;i<=5;i++){
        addLast(&root,i*10);
    }
    print(root);
    return 0;
}
