#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node*next;
    int data;
}*first=NULL,*second=NULL,*third=NULL;

void create1 (int A[] , int n ){
    struct Node*last,*t;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;
    
    for(int i = 1 ; i<n ; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        last->next = t;
        t->next=NULL;
        last = t;
    }
}

void create2 (int B[] , int n ){
    struct Node*last,*t;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data=B[0];
    second->next=NULL;
    last = second;
    
    for(int i = 1 ; i<n ; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = B[i];
        last->next = t;
        t->next=NULL;
        last = t;
    }
}

void display(struct Node*p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void reverse (struct Node*p){
    struct Node*q=NULL;
    struct Node*r=NULL;
    
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        
    }
    first = q ;
}

int count(struct Node*p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int isSorted(struct Node*p){
    int x = -32576;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
       
    }
     return 1;
}

int sum(struct Node*p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
    }
    return sum;
}

int max(struct Node*p){
    int max = -32576;
    if(p->data > max){
        max=p->data;
        p=p->next;
    }
    return max ;
}

int min(struct Node*p){
    int min = 32576;
    if(p->data < min ){
        min=p->data;
        p=p->next;
    }
    return min ;
}

void delete_duplicates(struct  Node*p){
    struct Node*q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int delete(struct Node*p , int index ){
    struct Node*q=NULL;
    int x=-1;
    
    if(index<1 || index>count(p))
    return -1;
    
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    
    else{
        for(int i = 1 ; i<index-1;i++){
            q=p;
            p=p->next;
        }
        
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

struct Node*search(struct Node*p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main() {
    int choice;
    int A[100], B[100];
    int n, index, key;
    
    while (1) {
        printf("\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List\n");
        printf("4. Reverse List\n");
        printf("5. Count Nodes\n");
        printf("6. Check if List is Sorted\n");
        printf("7. Calculate Sum of List\n");
        printf("8. Find Maximum Element\n");
        printf("9. Find Minimum Element\n");
        printf("10. Delete Duplicates\n");
        printf("11. Delete Node at Index\n");
        printf("12. Search for Key\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Enter the number of elements for List 1: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                create1(A, n);
                printf("List 1 created successfully!\n");
                break;
            case 2:
                printf("Enter the number of elements for List 2: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &B[i]);
                }
                create2(B, n);
                printf("List 2 created successfully!\n");
                break;
            case 3:
                printf("Displaying List 1:\n");
                display(first);
               
                break;
            case 4:
                printf("Reversing List 1...\n");
                reverse(first);
                printf("List 1 reversed!\n");
                break;
            case 5:
                printf("Count of nodes in List 1: %d\n", count(first));
               
                break;
            case 6:
                if (isSorted(first))
                    printf("List 1 is sorted.\n");
                else
                    printf("List 1 is not sorted.\n");
                
                break;
            case 7:
                printf("Sum of List 1: %d\n", sum(first));
               
                break;
            case 8:
                printf("Maximum element in List 1: %d\n", max(first));
                
                break;
            case 9:
                printf("Minimum element in List 1: %d\n", min(first));
               
                break;
            case 10:
                printf("Deleting duplicates from List 1...\n");
                delete_duplicates(first);
                printf("Duplicates deleted from List 1!\n");
                
                break;
            case 11:
                printf("Enter the index to delete node from List 1: ");
                scanf("%d", &index);
                if (index < 1 || index > count(first))
                    printf("Invalid index!\n");
                else {
                    int deletedValue = delete(first, index);
                    printf("Node at index %d deleted. Deleted value: %d\n", index, deletedValue);
                }
               
                break;
            case 12:
                printf("Enter the key to search in List 1: ");
                scanf("%d", &key);
                struct Node* node1 = search(first, key);
                if (node1 != NULL)
                    printf("Key %d found in List 1.\n", key);
                else
                    printf("Key %d not found in List 1.\n", key);
                
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
