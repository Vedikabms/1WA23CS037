#include<stdio.h>
void push(int arr[],int data,int *top,int n);
int pop(int arr[],int *top);
void display(int arr[],int top);
void main()
{
  int n,choice,data,value;
  printf("Enter size of array:\n");
  scanf("%d",&n);
  int stack[n];
  int top=-1;
  printf("options:\n");
  printf("1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  printf("4.Exit\n");

  do{
  printf("\nPlease enter your choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    printf("Enter value to be pushed:\n\t");
    scanf("%d",&data);
    push(stack,data,&top,n);
    break;

    case 2:
    value=pop(stack,&top);
    if(value!=-1){
    printf("The deleted element is:%d",value);}
    break;

    case 3:
    display(stack,top);
    break;

    case 4:
        printf("Exiting...\n");
        break;


    default:printf("Enter a valid choice");
    }
    }while (choice!=4);
    }
void push (int arr[],int data,int *top,int n)
{if (*top>=n-1)
{ printf("\n\t Stack is overflow");
}
else
{  arr[++(*top)]=data;
   printf("%d Pushed onto stack\n",data);
}
}

int pop(int arr[],int *top)
{ if (*top<=-1)
  { printf("\n\tStack is underflow");
    return -1;
    }
  else
  { return arr[(*top)--];
  }
}
void display(int arr[],int top)
{
  if (top>=0)
  { printf("\nThe elements in stack\n");
  for(int i=top;i>=0;i--)
  { printf("\n%d",arr[i]);
  }
  }
  else
  {  printf("\n The stack is empty");
   }

}













