//program to insert the node with 3 conditions
#include<stdio.h>
#include<stdlib.h>
//creating node
struct node{
  int data ;
  struct node*next;
};
//insert at beginning ( 4 STEP PROCESS)
void insertbegin(struct node **head,int newdata)
{
    //1] allocate a node in heap
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
    //2]putting data in node
    newnode->data=newdata;
    //3] make next of new node as head
    newnode->next=(*head);
    //4]move the head to point to the new node
    (*head)=newnode;

}
//insert after a node ( 5 STEP PROCESS)
void insertafter(struct node *prev_node,int new_data)
{
    //1] check if the given previous node is null
    if(prev_node==NULL)
    {
        printf("THE GIVEN PREVIOUS NODE CANNOT BE NULL");
    }
    //2]allocate new node
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    //3]put in the data;
    new_node->data=new_data;
    //4]make the new node as next of previous node
    new_node->next=prev_node->next;
    //5]move the next of previous_node as new_node
    prev_node->next=new_node;
}
//ADD A NODE AT THE END ( 6 STEP PROCESS)
void insertend(struct node **head,int new_data)
{
    //1] allocate node
   struct node*new_node=(struct node*)malloc(sizeof(struct node));
   struct node*last=*head;//used in step 5
   //2] put in the data
   new_node->data=new_data;
   //3] this new node is going to be the last node  so make next of this as NULL
   new_node->next=NULL;
   //4] IF THE LINKED LIST IS EMPTY MAKE THE NEW_NODE AS HEAD
   if(*head==NULL)
   {
       *head = new_node;
       return;
   }
   //5] ELSE TRAVERSE TILL THE LAST NODE
   while(last->next!=NULL)
   {
       last=last->next;
   }
   //6] CHANGE THE NEXT OF LIST NODE
   last->next=new_node;
   return;

}

//
void printlist(struct node*n)
{
    while(n!=NULL)
    {
        printf("%d -->",n->data);
        n=n->next;
    }
}





int main(){
    //creating a node
    struct node*head;
    struct node*second;
    //creation dyanamic allocation in the heap memory
     head=(struct node*)malloc(sizeof(struct node));
     second=(struct node*)malloc(sizeof(struct node));
     //assiging value to node;
     head->data=2;
     head->next=second;
     second->data=3;
     second->next=NULL;
     printlist(head);

     insertbegin(&head,1);
      printf("\n");
        printlist(head);
     /*output
2 -->3 -->
1 -->2 -->3 -->
Process returned 0 (0x0)   execution time : 0.062 s
Press any key to continue.
*/
    printf("\n");
      insertafter(head->next,10);
      printlist(head);
/*output
2 -->3 -->
1 -->2 -->3 -->
1 -->2 -->10 -->3 -->
Process returned 0 (0x0)   execution time : 0.047 s
Press any key to continue.
      */
      printf("\n");
      insertend(&head,20);
      printlist(head);
      return 0;
/* output:=
2 -->3 -->
1 -->2 -->3 -->
1 -->2 -->10 -->3 -->
1 -->2 -->10 -->3 -->20 -->
Process returned 0 (0x0)   execution time : 0.063 s
Press any key to continue.
*/


}
