#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    char *arr;
    int top;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char oParenthesis)
{
    ++ptr->top;
    ptr->arr[ptr->top] = oParenthesis;
}

char pop(struct stack *ptr)
{
    int topvalue = ptr->top;
    --ptr->top;
    return ptr->arr[topvalue];
}

char stackTop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    
    return ptr->arr[ptr->top];
}

int isoperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infixtoPostfix(char *infix)
{
    struct stack *s;
    static char postfix[40];
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 40;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i = 0, j = 0, n = 0;
    while (i < strlen(infix))
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
       
    }

    while (!isEmpty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    
    puts(postfix);
}

int main()
{
    struct stack *s;
    char infixExp[40];

    puts("enter the expression : ");
    gets(infixExp);
    infixtoPostfix(infixExp);
}