#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*top=NULL;
void push()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data:");
scanf("%d",&newnode->data);
newnode->next=top;
top=newnode;
printf("inserted successfully\n");
}
void pop()
{
struct node*temp;
if(top==NULL)
{
printf("Stack Underflow\n");
}
else
{
temp=top;
printf("deleted element:%d\n",top->data);
top=top->next;
free(temp);
}
}
void display()
{
struct node*temp;
if(top==NULL)
{
printf("stack is empty\n");
}
else
{
temp=top;
printf("stack elements:\n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp=temp->next;
}
}
}
int main()
{
int ch;
do
{
printf("\n1.push");
printf("\n2.pop");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case2:
pop();
break;
case3:
display();
break;
case4:
printf("Exit");
break;
default:
printf("invalid choice");
}
}
while(ch!=4);
return 0;
}

