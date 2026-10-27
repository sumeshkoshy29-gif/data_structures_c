#include<stdio.h>
#define SIZE 5
int main()
{
	int stack[SIZE],top=-1;
	int choice,value,i;
do
{
	printf("\n1.push");
	printf("\n2.pop");
	printf("\n3.Display");
	printf("\n4.Exit");
	printf("\nenter your choice:");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			if(top==SIZE-1)
				printf("stack overflow");
			else
			{
				printf("enter value:");
				scanf("%d",&value);
				stack[++top]=value;
				printf("element pushed");
			}
			break;
		case 2:
			if (top==-1)
				printf("stack underflow");
			else
				printf("popped element:%d",stack[top--]);
			break;
		case 3:
				if(top==-1)
				printf("stack is empty");
			else
			{
				printf("stack elements:");
				for(i=top;i>=0;i--)
				printf("%d",stack[i]);
			}
			break;
		case 4:
				printf("exit");
			break;
		default:
				printf("invalid choice");
			}
		}
			while(choice!=4);
		return 0;
	}



