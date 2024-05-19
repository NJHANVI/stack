#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
 int items[MAX_SIZE];
 int top;   
}Stack;

Stack* create_stack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;//empty stack
    return stack;//check if pointer==null
}
int is_empty(Stack* stack)
{
    return stack->top == -1;
}
int is_full(Stack* stack)
{
    return stack->top == MAX_SIZE - 1;// 0 based indexing
}
void push(Stack* stack,int item)
{
 if(is_full(stack))
 {
    printf("stack is full. cannot push %d.\n",item);
    return;
 }
 stack->items[++stack->top]=item;
}
int pop(Stack* stack)
{
    if(is_empty(stack))
    {
        printf("stack is empty. cannot pop.\n");
        return -1;
    }
    return stack->items[stack->top--];//pehle return ho jayegi value fir decrement hoga
}
int peek(Stack* stack)
{
 if(is_empty(stack))
 {
    printf("stack is empty:\n");
    return -1;
 }
 return stack->items[stack->top];
}
int get_size(Stack* stack)
{
    return stack->top+1;
}
void destroy_stack(Stack* stack)
{
    free(stack);
}
int main()
{
    Stack* stack=create_stack();
    push(stack,10);
    push(stack,20);
    printf("top element is %d\n",peek(stack));
    printf("stack size: %d\n",get_size(stack));
    pop(stack);
    destroy_stack(stack);
    return 0;
}