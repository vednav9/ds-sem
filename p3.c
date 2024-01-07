//Postfix Evaluation
#include <stdio.h>
#include <ctype.h>
int stack[50];
int top = -1;
int push(int x);
int pop();
void main()
{
    char exp[50];
    int i = 0, op1, op2, result;
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        // for ascii char from 0 to 9 integer = char - '0'
        else
        {
            op1 = pop();
            op2 = pop();
            switch (exp[i])
            {
            case '+':
            {
                push(op2 + op1);
                break;
            }
            case '-':
            {
                push(op2 - op1);
                break;
            }
            case '*':
            {
                push(op2 * op1);
                break;
            }
            case '/':
            {
                push(op2 / op1);
                break;
            }
            case '^':
            {
                push(op2 ^ op1);
                break;
            }
            }
        }
        i++;
    }
    result = pop();
    printf("\nThe answer of postfix expression %s = %d\n", exp, result);
}
int push(int x)
{
    top++;
    stack[top] = x;
}
int pop()
{
    int y;
    y = stack[top];
    top--;
    return y;
}