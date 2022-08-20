#include <stdio.h>
#include <stdlib.h>
// BU TAM ANLAMIYLA TAMAMLANMIÞ BÝR KODDUR!!!

struct node{
    int id;
    struct node *next;
    struct node *prev;
};

struct node *sortedlist(struct node *root,int id){
    if(root == NULL){//hiç eleman yokken ekleme
        root=(struct node*)malloc(sizeof(struct node));
        root->id=id;
        root->next=NULL;
        root->prev=NULL;
        return root;
    }
    if(root->id > id){//root deðiþecek burada
        struct node*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->id=id;
        temp->prev=NULL;
        root->prev=temp;
        temp->next=root;//rootun yerine temp geçti o yüzden yeni rootumuz temp oldu.
        return temp;
    }
    struct node*iter;
    iter=root;
    while(iter->next!=NULL && iter->next->id < id)// araya eleman eklenebilmesi için
        iter = iter->next;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->id=id;
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;
    if(temp->next !=NULL)//sona eleman ekleniyorsa
       temp->next->prev=temp;
    return root;
};

struct node *dlt(struct node *root,int id){
    if(root->id == id){// rootu silersek
        struct node*temp;
        temp=root;
        root=temp->next;
        root->prev=NULL;
        root->next=temp->next->next;
        free(temp);
        return root;
    }
    struct node *iter;
    iter=root;
    while(iter->next !=NULL && iter->next->id != id)//elemaný arýyor!!!!
        iter=iter->next;
    if(iter->next == NULL){
        printf("the number was not found!!\n");
        return root;
    }
    struct node *temp;
    temp=iter->next;
    iter->next=temp->next;
    free(temp);
    if(iter->next!=NULL)
       temp->next->prev=iter;
    return root;


};

void print(struct node *start){
    while(start!=NULL){
        printf("%d ",start->id);
        start=start->next;
    }
}

int main()
{
    struct node *root=NULL;
    int id;
    scanf("%d",&id);
    while(id!=-1){
        root=sortedlist(root,id);
        scanf("%d",&id);
    }
    print(root);
    printf("\n");
    root=dlt(root,4);
    print(root);
    printf("\n");
    root=dlt(root,8);
    print(root);
    printf("\n");
    root=dlt(root,900);
    print(root);
    printf("\n");
    root=dlt(root,450);
    print(root);
    return 0;
}
