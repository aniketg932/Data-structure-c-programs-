#include<stdio.h>
#include<stdlib.h>

 struct Node 
  {  
      int data;
      struct Node *next;
  }*top=NULL;
   
 void push(int x)
   { 
       struct Node *t;
       t=(struct Node*)malloc(sizeof(struct Node));
       if(t==NULL)
          printf("Stack is full \n");
       else
        { 
           t->data=x;
           t->next=top;
           top=t;
         }
     }
   
  int pop()
   { 
       struct Node *t;
       int x=-1;
       
       if(top==NULL)
          printf("Stack is empty \n");
       else
        { 
            top=top->next;
            x=t->data;
            free(t);
         }
       return x;
     }
  void display()
     { 
         struct Node *p;
         p=top;
         while(p!=NULL)
           { 
              printf("%d", p->data);
              p=p->next;
            }
         printf("\n");
     }
 
  int main()
    {
       push(10);
       push(20);
       //pop(10);
       display();
       printf("%d",pop());
       return 0;
    }
                  
         
