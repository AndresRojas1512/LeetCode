#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ARRAY_SIZE 100

bool isValid(char * s);
void Push(int *stack, int *top, int x);
void Pop(int *stack, int *top);
int Top(int *stack, int *top);
int isEmpty(int *top);
bool arePair(char opening, char closing);

int main(void)
{
    char str[MAX_ARRAY_SIZE] = "(){}[]";
    if (isValid(str))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

bool isValid(char * s)
{
    int stack[MAX_ARRAY_SIZE]; // stack
    int top = -1;
    int i = 0;
    while (s[i])
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            Push(stack, &top, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if ((top == -1) || !arePair(Top(stack, &top), s[i]))
            {
                return false;
            }
            else
            {
                Pop(stack, &top);
            }
        }
        i++;
    }
    if (isEmpty(&top))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(int *stack, int *top, int x)
{
    if (((*top) == MAX_ARRAY_SIZE - 1))
    {
        return; // overflow
    }
    else
    {
        stack[++(*top)] = x;
    }
}

void Pop(int *stack, int *top)
{
    if ((*top) == -1)
    {
        return; // empyt stack, cannot pop
    }
    else
    {
        (*top)--;
    }
}

int Top(int *stack, int *top)
{
    return stack[(*top)];
}

int isEmpty(int *top)
{
    if ((*top) == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool arePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
    {
        return true;
    }
    else if (opening == '[' && closing == ']')
    {
        return true;
    }
    else if (opening == '{' && closing == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}