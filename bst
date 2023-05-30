#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;

void Insert(int key){
    struct Node*t=root;
    struct Node*p,*r;
    
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return ;
    }
    
    while(t!=NULL){
        r=t;
        if(key<t->data)
        t=t->lchild;
        else if(key>t->data)
        t=t->rchild;
        else 
        return ;
    }
    
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
    r->lchild=p;
    else r->rchild=p;

}

struct Node*RInsert(struct Node*p , int key){
    
}

int height(struct Node*p){
    int x=0,y=0;
    if(p==NULL)
    return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    return x+1;
    else
    return y+1;
}

struct Node*InPre(struct Node*p){
    while(p &&p->rchild!=NULL)
    p=p->rchild;
    return p;
}
struct Node*InSucc(struct Node*p){
    while(p &&p->lchild!=NULL)
    p=p->lchild;
    return p;
}
void Inorder(struct Node*p){
    if(p){
        Inorder(p->lchild);
        printf("%d\n",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node*p){
    if(p){
        Postorder(p->lchild);
         Postorder(p->rchild);
        printf("%d\n",p->data);
       
    }
}

void Preorder(struct Node*p){
    if(p){
         printf("%d\n",p->data);
       Preorder(p->lchild);
        Preorder(p->rchild);
       
       
    }
}

struct Node* search(int key){
   struct Node*t;
    while(t!=NULL){
        if(key==t->data){
            return t;
        }
        else if(key<t->data){
            t=t->lchild;
            
        }
        else
        t=t->rchild;
    }
    return NULL;
}


struct Node*delete(struct Node*p,int key){
   
    if(p==NULL){
        return NULL;
        
    }
    if(p->lchild == NULL && p->rchild == NULL){
        ///leaf nodes///
        if(p==root)
        root =  NULL;
        else
        free(p);
        return NULL;
    }
 
    
    
    if(key<p->data)
    {
            p->lchild=delete(p->lchild,key);
           
            
    }
    else if(key>p->data)
    {
            p->rchild=delete(p->rchild,key);
    }
    else 
        {
             struct  Node*q;
            if(height(p->lchild) < height(p->rchild)){
                q=InSucc(p->lchild);
                p->data=q->data;
                p->lchild=delete(p->lchild,q->data);
            }
            else{
                q=InPre(p->rchild);
                p->data=q->data;
                p->rchild=delete(p->rchild,q->data);
            }
        }
        return p;
    }
    
    int main() {
    int choice, key;
    
    while (1) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                Insert(key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(key) != NULL)
                    printf("Key %d found in the BST.\n", key);
                else
                    printf("Key %d not found in the BST.\n", key);
                break;
            case 4:
                printf("Inorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
