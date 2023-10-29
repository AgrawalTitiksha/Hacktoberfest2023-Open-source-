#include<stdio.h>
#include<conio.h>
#define max 10
int queue[max];
int front=-1,rear=-1;
void enqueue();
int dequeue();
void display();
void main(){
    int option,val;
    do{
        printf("\n****************Main Menu****************\n");
        printf("\n1.Insert an element\n");
        printf("\n2.Delete an element\n");
        printf("\n3.Display the queue\n");
        printf("\n*****************************************\n");
        printf("\n\nEnter your choice:");
        scanf("%d",&option);
        switch(option){
            case 1:
            enqueue();
            break;
            case 2:
            val=dequeue();
            printf("\nThe number that was deleted is:%d",val);
            break;
            case 3:
            display();
            break;
        }
    }while(option!=4);
    return 0;
}
void enqueue(){
    int num;
    printf("\nEnter the number to be inserted in the queue:");
    scanf("%d",&num);
    if(rear==max-1 && front==0){
        printf("\nOverflow");
    }
    if(front==-1 && rear==-1){
        front=rear=0;
    }
    else if(rear==max-1 && front!=0){
        rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=num;
}
int dequeue(){
    int val;
    if(front==-1){
        printf("\nUnderflow");
        return -1;
    }
    val=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        if(front==max-1){
            front=0;
        }
        else{
            front++;
        }
    }
    return val;
}
void display(){
    int i;
    printf("\n");
    if(front!=-1 && rear!=-1){
        if(front<rear){
            for(i=front;i<=rear;i++){
                printf("\t%d",queue[i]);
            }
        }
        else{
            for(i=front;i<max;i++){
                printf("\t%d",queue[i]);
            }
            for(i=0;i<rear;i++){
                printf("\t%d",queue[i]);
            }
        }
    }
}
